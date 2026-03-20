#include "figuras.h"

#include <iostream>

Figura::Figura(std::string nombre){
    this->nombre = nombre;
}

Figura::~Figura(){}

std::string Figura::obtNombre(){
    return this->nombre;
}
