#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cstdio>

std::string escaparJson(const std::string& texto) {
    std::string resultado;
    resultado.reserve(texto.size());

    for (char c : texto) {
        switch (c) {
            case '\\': resultado += "\\\\"; break;
            case '"': resultado += "\\\""; break;
            case '\n': resultado += "\\n"; break;
            case '\r': resultado += "\\r"; break;
            case '\t': resultado += "\\t"; break;
            default: resultado += c; break;
        }
    }

    return resultado;
}

std::string ejecutarComandoYCapturar(const std::string& comando) {
    std::string salida;
    char buffer[512];

    FILE* pipe = _popen(comando.c_str(), "r");
    if (!pipe) {
        return "";
    }

    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        salida += buffer;
    }

    _pclose(pipe);
    return salida;
}

std::string desescaparJson(const std::string& texto) {
    std::string resultado;
    resultado.reserve(texto.size());

    for (size_t i = 0; i < texto.size(); ++i) {
        if (texto[i] == '\\' && i + 1 < texto.size()) {
            char sig = texto[i + 1];
            switch (sig) {
                case 'n': resultado += '\n'; break;
                case 'r': resultado += '\r'; break;
                case 't': resultado += '\t'; break;
                case '"': resultado += '"'; break;
                case '\\': resultado += '\\'; break;
                case '/': resultado += '/'; break;
                default: resultado += sig; break;
            }
            ++i;
        } else {
            resultado += texto[i];
        }
    }

    return resultado;
}

std::string extraerCampoText(const std::string& json) {
    size_t posClave = json.find("\"text\"");
    if (posClave == std::string::npos) {
        return "";
    }

    size_t posDosPuntos = json.find(':', posClave);
    if (posDosPuntos == std::string::npos) {
        return "";
    }

    size_t posComillaInicio = json.find('"', posDosPuntos);
    if (posComillaInicio == std::string::npos) {
        return "";
    }

    std::string textoEscapado;
    for (size_t i = posComillaInicio + 1; i < json.size(); ++i) {
        if (json[i] == '"' && json[i - 1] != '\\') {
            break;
        }
        textoEscapado += json[i];
    }

    return desescaparJson(textoEscapado);
}

std::string obtenerVariableEnv(const std::string& clave) {
    std::ifstream archivo(".env");
    if (!archivo.is_open()) {
        return "";
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        if (linea.empty() || linea[0] == '#') {
            continue;
        }

        size_t pos = linea.find('=');
        if (pos == std::string::npos) {
            continue;
        }

        std::string key = linea.substr(0, pos);
        std::string value = linea.substr(pos + 1);

        if (!value.empty() && value.front() == '"' && value.back() == '"') {
            value = value.substr(1, value.size() - 2);
        }

        if (!value.empty() && value.back() == '\r') {
            value.pop_back();
        }

        if (key == clave) {
            return value;
        }
    }

    return "";
}

int main() {
    std::cout << "Chat con Gemini" << std::endl;

    std::string apiKey = obtenerVariableEnv("GEMINI_API_KEY");
    if (apiKey.empty()) {
        std::cout << "No se encontro GEMINI_API_KEY en .env" << std::endl;
        return 1;
    }

    std::string url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-2.5-flash:generateContent?key=" + apiKey;

    while (true) {
        std::string Pregunta;
        std::cout << "\nEscribe tu pregunta para la IA (o escribe Salir): ";
        std::getline(std::cin, Pregunta);

        if (Pregunta == "Salir") {
            std::cout << "Saliendo del programa" << std::endl;
            break;
        }

        std::cout << "\nEnviando mensaje. Esperando respuesta.\n" << std::endl;

        std::string preguntaEscapada = escaparJson(Pregunta);
        std::string comando = "curl -s -H \"Content-Type: application/json\" -X POST \"" + url + "\" ";
        comando += "-d \"{\\\"contents\\\": [{\\\"parts\\\":[{\\\"text\\\": \\\"" + preguntaEscapada + "\\\"}]}]}\"";

        std::string respuestaJson = ejecutarComandoYCapturar(comando);
        std::string respuestaIA = extraerCampoText(respuestaJson);

        if (respuestaIA.empty()) {
            std::cout << "No se pudo extraer el texto de la respuesta." << std::endl;
            std::cout << "Respuesta completa: " << respuestaJson << std::endl;
        } else {
            std::cout << "Respuesta IA:\n" << respuestaIA << std::endl;
        }
    }

    return 0;
}
