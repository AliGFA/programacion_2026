#ifndef CAMION_H
#define CAMION_H

#include <string>
#include "vehiculo.h"

class Camion : public Vehiculo {
    private:
        float capacidadCarga; // en toneladas
        std::string tipoRemolque; // "plataforma", "cisterna", etc.
    public:
        Camion();
        Camion(std::string marca, std::string modelo, int año, std::string matricula, float capacidadCarga, std::string tipoRemolque);

        void actualizarTipoRemolque(std::string nuevoTipo);
        void actualizarCapacidadCarga(float nuevaCapacidad);

        void mostrarInformacion();

        float obtenerCapacidadCarga();
        std::string obtenerTipoRemolque();  
};
#endif