#include <iostream>
#include <string>

#include "mensaje.h"
#include "historial_mensajes.h"
#include "gemini_cliente.h"

int main() {
    std::cout << "Chat con Gemini" << std::endl;

    GeminiCliente cliente;
    if (!cliente.estaConfigurado()) {
        std::cout << "No se encontro GEMINI_API_KEY en .env" << std::endl;
        return 1;
    }

    HistorialMensajes historial;
    std::string fechaInicioConversacion = Mensaje::ObtenerFechaHoraActual();
    std::string rutaLogConversacion = HistorialMensajes::ConstruirRutaLogConversacion(fechaInicioConversacion);

    while (true) {
        std::string Pregunta;
        std::cout << "\nEscribe tu pregunta para la IA (o escribe Salir): ";
        std::getline(std::cin, Pregunta);

        if (Pregunta == "Salir") {
            std::cout << "Saliendo del programa" << std::endl;
            break;
        }

        std::cout << "\nEnviando mensaje. Esperando respuesta.\n" << std::endl;
        std::string fechaEnvio = Mensaje::ObtenerFechaHoraActual();
        std::string respuestaJson;
        std::string respuestaIA = cliente.enviarPregunta(Pregunta, respuestaJson);
        std::string fechaRecepcion = Mensaje::ObtenerFechaHoraActual();

        Mensaje mensaje(Pregunta, respuestaIA, fechaEnvio, fechaRecepcion);
        historial.agregarYGuardar(mensaje, rutaLogConversacion);

        if (respuestaIA == "*Modelo ocupado*") {
            std::cout << "*Modelo ocupado*" << std::endl;
        } else if (respuestaIA.empty()) {
            std::cout << "No se pudo extraer el texto de la respuesta." << std::endl;
            std::cout << "Respuesta completa: " << respuestaJson << std::endl;
        } else {
            std::cout << "Respuesta IA:\n" << respuestaIA << std::endl;
        }
    }

    return 0;
}
