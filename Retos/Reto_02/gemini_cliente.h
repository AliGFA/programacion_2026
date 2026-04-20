#ifndef GEMINI_CLIENTE_H
#define GEMINI_CLIENTE_H

#include <string>

class GeminiCliente {
private:
    std::string apiKey;
    std::string url;

    static std::string escaparJson(const std::string& texto);
    static std::string ejecutarComandoYCapturar(const std::string& comando);
    static std::string desescaparJson(const std::string& texto);
    static std::string extraerCampoText(const std::string& json);
    static std::string obtenerVariableEnv(const std::string& clave);

public:
    GeminiCliente();

    bool estaConfigurado() const;

    std::string enviarPregunta(const std::string& pregunta, std::string& respuestaJson) const;
};

#endif
