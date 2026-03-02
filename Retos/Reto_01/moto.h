#ifndef MOTO.H
#define MOTO.H

#include <string>
#include "vehiculo.h"

class Moto : public Vehiculo {
private:
    std::string tipoManillar;
    std::string cilindrada;

public:
    Moto();
    Moto(std::string marca, std::string modelo, int año, std::string matricula, std::string tipoManillar, std::string cilindrada);

    void actualizarManillar(std::string nuevoManillar);
    void actualizarCilindrada(std::string nuevaCilindrada);
    void mostrarInformacion();

    std::string obtenerManillar();
    std::string obtenerCilindrada();

};

#endif