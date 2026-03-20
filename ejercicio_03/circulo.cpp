#include <iostream>
#include "circulo.h"
#include <cmath>


Circulo::Circulo(std::string nombre, double radio)
    : Figura(nombre){
    this->radio = radio;
}

double Circulo::obtArea(){
    return M_PI * this->radio * this->radio;
}

void Circulo::describir(){
    std::cout << "Figura: " << this->nombre << ", radio: " << this->radio << std::endl;
}

double Circulo::obtRadio(){
    return this->radio;
}

