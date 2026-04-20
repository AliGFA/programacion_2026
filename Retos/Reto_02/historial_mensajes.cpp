#include "historial_mensajes.h"

#include <filesystem>
#include <fstream>

void HistorialMensajes::agregar(const Mensaje& mensaje) {
    mensajes.push_back(mensaje);
}

std::string HistorialMensajes::ConstruirRutaLogConversacion(const std::string& fechaInicio,
                                                            const std::string& carpeta) {
    std::filesystem::create_directories(carpeta);

    std::string nombreArchivo = fechaInicio;
    for (char& c : nombreArchivo) {
        if (c == ' ') {
            c = '_';
        } else if (c == ':') {
            c = '-';
        }
    }

    return carpeta + "/" + nombreArchivo + ".txt";
}

void HistorialMensajes::agregarYGuardar(const Mensaje& mensaje, const std::string& rutaArchivo) {
    agregar(mensaje);

    std::ofstream archivo(rutaArchivo, std::ios::app);
    if (!archivo.is_open()) {
        return;
    }

    archivo << mensaje.FormatoLogEnvio() << '\n';
    archivo << mensaje.FormatoLogRecepcion() << '\n';
    archivo << "----------------------------------------\n";
}

const std::vector<Mensaje>& HistorialMensajes::obtenerMensajes() const {
    return mensajes;
}

void HistorialMensajes::limpiar() {
    mensajes.clear();
}
