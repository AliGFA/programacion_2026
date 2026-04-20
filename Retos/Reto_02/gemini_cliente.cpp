#include "gemini_cliente.h"

#include <cstdio>
#include <fstream>

GeminiCliente::GeminiCliente() {
    apiKey = obtenerVariableEnv("GEMINI_API_KEY");
    if (!apiKey.empty()) {
        url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-2.5-flash:generateContent?key=" + apiKey;
    }
}

bool GeminiCliente::estaConfigurado() const {
    return !apiKey.empty();
}

std::string GeminiCliente::enviarPregunta(const std::string& pregunta, std::string& respuestaJson) const {
    if (!estaConfigurado()) {
        respuestaJson.clear();
        return "";
    }

    std::string preguntaEscapada = escaparJson(pregunta);
    std::string comando = "curl -s -H \"Content-Type: application/json\" -X POST \"" + url + "\" ";
    comando += "-d \"{\\\"contents\\\": [{\\\"parts\\\":[{\\\"text\\\": \\\"" + preguntaEscapada + "\\\"}]}]}\"";

    respuestaJson = ejecutarComandoYCapturar(comando);
    std::string respuestaTexto = extraerCampoText(respuestaJson);
    if (!respuestaTexto.empty()) {
        return respuestaTexto;
    }

    const bool es503 = (respuestaJson.find("\"code\": 503") != std::string::npos);
    const bool esUnavailable = (respuestaJson.find("\"status\": \"UNAVAILABLE\"") != std::string::npos);
    const bool altaDemanda = (respuestaJson.find("high demand") != std::string::npos);

    if (es503 || esUnavailable || altaDemanda) {
        return "*Modelo ocupado, intenta de nuevo mas tarde*";
    }

    return "";
}

std::string GeminiCliente::escaparJson(const std::string& texto) {
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

std::string GeminiCliente::ejecutarComandoYCapturar(const std::string& comando) {
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

std::string GeminiCliente::desescaparJson(const std::string& texto) {
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

std::string GeminiCliente::extraerCampoText(const std::string& json) {
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

std::string GeminiCliente::obtenerVariableEnv(const std::string& clave) {
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
