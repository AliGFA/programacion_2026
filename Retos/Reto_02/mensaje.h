#ifndef MENSAJE_H
#define MENSAJE_H

#include <string>

class Mensaje {
private:
    std::string prompt;
    std::string respuesta;
    std::string fechaEnvio;
    std::string fechaRecepcion;

public:
    Mensaje();

    Mensaje(const std::string& prompt,
            const std::string& respuesta,
            const std::string& fechaEnvio,
            const std::string& fechaRecepcion);

    const std::string& ObtPrompt() const;

    const std::string& ObtRespuesta() const;

    const std::string& ObtFechaEnvio() const;

    const std::string& ObtFechaRecepcion() const;

    std::string FormatoLogEnvio() const;

    std::string FormatoLogRecepcion() const;

    static std::string ObtenerFechaHoraActual();

    void CambPrompt(const std::string& nuevoPrompt);

    void CambRespuesta(const std::string& nuevaRespuesta);

    void CambFechaEnvio(const std::string& nuevaFechaEnvio);

    void CambFechaRecepcion(const std::string& nuevaFechaRecepcion);
};

#endif