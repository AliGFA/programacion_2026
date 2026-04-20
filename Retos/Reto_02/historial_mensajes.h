#ifndef HISTORIAL_MENSAJES_H
#define HISTORIAL_MENSAJES_H

#include <string>
#include <vector>
#include "mensaje.h"

class HistorialMensajes {
private:
    std::vector<Mensaje> mensajes;

public:
    void agregar(const Mensaje& mensaje);

    static std::string ConstruirRutaLogConversacion(const std::string& fechaInicio,
                                                    const std::string& carpeta = "historial");

    void agregarYGuardar(const Mensaje& mensaje, const std::string& rutaArchivo = "log_mensajes.txt");

    const std::vector<Mensaje>& obtenerMensajes() const;

    void limpiar();
};

#endif