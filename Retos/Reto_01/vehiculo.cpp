#include "vehiculo.h"
#include <iostream>

// Constructor por defecto
Vehiculo::Vehiculo() {
    marca = "";
    modelo = "";
    año = 0;
}

// Constructor con parámetros
Vehiculo::Vehiculo(std::string marca, std::string modelo, int año, std::string matricula) {
    this->marca = marca;
    this->modelo = modelo;
    this->año = año;
    this->matricula = matricula;
}

// Métodos para actualizar
void Vehiculo::actualizarMarca(std::string nuevaMarca) {
    marca = nuevaMarca;
}

void Vehiculo::actualizarModelo(std::string nuevoModelo) {
    modelo = nuevoModelo;
}

void Vehiculo::actualizarMatricula(std::string nuevaMatricula) {
    matricula = nuevaMatricula;
}

void Vehiculo::actualizarAño(int nuevoAño) {
    año = nuevoAño;
}

// Método para mostrar
void Vehiculo::mostrarInformacion() {
    std::cout << "Marca: " << marca << std::endl;
    std::cout << "Modelo: " << modelo << std::endl;
    std::cout << "Año: " << año << std::endl;
    std::cout << "Matrícula: " << matricula << std::endl;
}

// Getters
std::string Vehiculo::obtenerMarca() {
    return marca;
}

std::string Vehiculo::obtenerModelo() {
    return modelo;
}

int Vehiculo::obtenerAnio() {
    return año;
}
