#include "mensaje.h"

#include <chrono>
#include <iomanip>
#include <sstream>

Mensaje::Mensaje() = default;

Mensaje::Mensaje(const std::string& prompt,
                 const std::string& respuesta,
                 const std::string& fechaEnvio,
                 const std::string& fechaRecepcion)
    : prompt(prompt),
      respuesta(respuesta),
      fechaEnvio(fechaEnvio),
      fechaRecepcion(fechaRecepcion) {}

const std::string& Mensaje::ObtPrompt() const {
    return prompt;
}

const std::string& Mensaje::ObtRespuesta() const {
    return respuesta;
}

const std::string& Mensaje::ObtFechaEnvio() const {
    return fechaEnvio;
}

const std::string& Mensaje::ObtFechaRecepcion() const {
    return fechaRecepcion;
}

std::string Mensaje::FormatoLogEnvio() const {
    return "[ENVIADO ] " + fechaEnvio + " | " + prompt;
}

std::string Mensaje::FormatoLogRecepcion() const {
    return "[RECIBIDO] " + fechaRecepcion + " | " + respuesta;
}

std::string Mensaje::ObtenerFechaHoraActual() {
    auto ahora = std::chrono::system_clock::now();
    std::time_t tiempo = std::chrono::system_clock::to_time_t(ahora);
    std::tm tmLocal{};

    localtime_s(&tmLocal, &tiempo);

    std::ostringstream salida;
    salida << std::put_time(&tmLocal, "%Y-%m-%d %H:%M:%S");
    return salida.str();
}

void Mensaje::CambPrompt(const std::string& nuevoPrompt) {
    prompt = nuevoPrompt;
}

void Mensaje::CambRespuesta(const std::string& nuevaRespuesta) {
    respuesta = nuevaRespuesta;
}

void Mensaje::CambFechaEnvio(const std::string& nuevaFechaEnvio) {
    fechaEnvio = nuevaFechaEnvio;
}

void Mensaje::CambFechaRecepcion(const std::string& nuevaFechaRecepcion) {
    fechaRecepcion = nuevaFechaRecepcion;
}
