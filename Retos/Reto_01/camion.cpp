#include "camion.h"
#include <iostream>

Camion::Camion() : Vehiculo(){
    capacidadCarga = 0.0f;
    tipoRemolque = "";
}

Camion::Camion(std::string marca, std::string modelo, int año, std::string matricula, float capacidadCarga, std::string tipoRemolque)
    : Vehiculo(marca, modelo, año, matricula) {
        this->capacidadCarga = capacidadCarga;
        this->tipoRemolque = tipoRemolque;
}

void Camion::actualizarTipoRemolque(std::string nuevoTipo){
    tipoRemolque = nuevoTipo;
}
void Camion::actualizarCapacidadCarga(float nuevaCapacidad){
    capacidadCarga = nuevaCapacidad;
}

void Camion::mostrarInformacion(){
    Vehiculo::mostrarInformacion();
    std::cout << "Capacidad de carga (toneladas): " << capacidadCarga << std::endl;
    std::cout << "Tipo de remolque: " << tipoRemolque << std::endl;
}

std::string Camion::obtenerTipoRemolque(){
    return tipoRemolque;
}

float Camion:: obtenerCapacidadCarga(){
    return capacidadCarga;
}