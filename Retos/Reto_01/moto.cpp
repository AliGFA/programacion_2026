#include "moto.h"
#include <iostream>

//Mi constructor por defecto
Moto::Moto() : Vehiculo() {
    tipoManillar = "";
    cilindrada = "";
}

Moto::Moto(std::string marca, std::string modelo, int año, std::string matricula, std::string tipoManillar, std::string cilindrada)
    : Vehiculo(marca, modelo, año, matricula) {
    this->tipoManillar = tipoManillar;
    this->cilindrada = cilindrada;
}

void Moto::actualizarManillar(std::string nuevoManillar){
    tipoManillar = nuevoManillar;
}

void Moto::actualizarCilindrada(std::string nuevaCilindrada){
    cilindrada = nuevaCilindrada;
}

void Moto::mostrarInformacion(){
    Vehiculo::mostrarInformacion();
    std::cout << "Tipo de manillar: " << tipoManillar << std::endl;
    std::cout << "Cilindrada: " << cilindrada << std::endl;
}

std::string Moto::obtenerManillar(){
    return tipoManillar;
}