#include "autobus.h"
#include <iostream>

Autobus::Autobus() : Vehiculo(){
    numeroPasajeros = 0;
    numeroAsientos = 0;
}

Autobus::Autobus(std::string marca, std::string modelo, int año, std::string matricula, int numeroPasajeros, int numeroAsientos)
    : Vehiculo(marca, modelo, año, matricula) {
        this->numeroPasajeros = numeroPasajeros;
        this->numeroAsientos = numeroAsientos;
}

void Autobus::actualizarPasajeros(int nuevoNumero){
    numeroPasajeros = nuevoNumero;
}

void Autobus::actualizarPasajeros(int nuevoNumero){
    numeroPasajeros=nuevoNumero;
}