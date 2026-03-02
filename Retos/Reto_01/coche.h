#ifndef COCHE_H
#define COCHE_H

#include <string>
#include "vehiculo.h"

class Coche : public Vehiculo {
private:
    int numeroPuertas;

public:
    // Constructores
    Coche();
    Coche(std::string marca, std::string modelo, int año, std::string matricula, int numeroPuertas);

    // Métodos para actualizar
    void actualizarNumeroPuertas(int nuevoNumero);

    // Sobrescritura del método de la clase base
    void mostrarInformacion();

    // Getter
    int obtenerNumeroPuertas();
};

#endif // COCHE_H
