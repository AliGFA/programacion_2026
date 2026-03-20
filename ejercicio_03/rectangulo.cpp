#include <iostream>
#include "rectangulo.h"

Rectangulo::Rectangulo(std::string nombre, double base, double altura)
	: Figura(nombre){
	this->base = base;
	this->altura = altura;
}

double Rectangulo::obtArea(){
	return this->base * this->altura;
}

void Rectangulo::describir(){
	std::cout << "Figura: " << this->nombre << ", base: " << this->base
			  << ", altura: " << this->altura << std::endl;
}

double Rectangulo::obtBase(){
	return this->base;
}

double Rectangulo::obtAltura(){
	return this->altura;
}
