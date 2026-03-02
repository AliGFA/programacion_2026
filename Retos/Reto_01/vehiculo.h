#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    int año;
    std::string matricula;

public:
    // Constructores
    Vehiculo();
    Vehiculo(std::string marca, std::string modelo, int año, std::string matricula);

    // Métodos para actualizar
    void actualizarMarca(std::string nuevaMarca);
    void actualizarModelo(std::string nuevoModelo);
    void actualizarAño(int nuevoAño);
    void actualizarMatricula(std::string nuevaMatricula);

    // Métodos para mostrar
    void mostrarInformacion();

    // Getters
    std::string obtenerMarca();
    std::string obtenerModelo();
    int obtenerAnio();
    std::string obtenerMatricula();
};

#endif // VEHICULO_H
