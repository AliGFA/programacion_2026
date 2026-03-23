#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    std::cout << "Chat con Gemini" << std::endl;

    std::string apiKey = "AIzaSyCT0khsSZFwU6WEwBO7uQujuHyw547Eg7M"; 
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

        std::string comando = "curl -s -H \"Content-Type: application/json\" -X POST \"" + url + "\" ";
        comando += "-d \"{\\\"contents\\\": [{\\\"parts\\\":[{\\\"text\\\": \\\"" + Pregunta + "\\\"}]}]}\" | powershell -NoProfile -Command \"$input | ConvertFrom-Json | ForEach-Object { $_.candidates[0].content.parts[0].text }\"";

        system(comando.c_str());
    }

    return 0;

}

