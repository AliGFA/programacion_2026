#ifndef CELULAR_H
#define CELULAR_H

#include <string>

class Celular{
    private:
        std::string marca;
        std::string modelo;
        int almacenamiento;
        int ram;
        float precio;
    public:
        Celular();
        Celular(std::string marca, std::string modelo, int almacenamiento, int ram, float precio);

        void actualizarMarca(std::string nuevaMarca);
        void actualizarModelo(std::string nuevoModelo);
        void actualizarAlmacenamiento(int nuevoAlmacenamiento);
        void actualizarRam(int nuevaRam);
        void actualizarPrecio(float nuevoPrecio);

        std::string obtenerMarca();
        std::string obtenerModelo();
        int obtenerAlmacenamiento();
        int obtenerRam();
        float obtenerPrecio();

        void mostrarMarca();
        void mostrarModelo();
        void mostrarAlmacenamiento();
        void mostrarRam();
        void mostrarPrecio();
};

#endif