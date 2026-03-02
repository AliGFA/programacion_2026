#include "coche.h"
#include <iostream>

// Constructor por defecto: llama al constructor por defecto de Vehiculo
Coche::Coche() : Vehiculo() {
    numeroPuertas = 0;
}

// Constructor con parámetros: pasa los datos del vehículo a la base
Coche::Coche(std::string marca, std::string modelo, int año, std::string matricula, int numeroPuertas)
    : Vehiculo(marca, modelo, año, matricula) {
    this->numeroPuertas = numeroPuertas;
}

// Método para actualizar
void Coche::actualizarNumeroPuertas(int nuevoNumero) {
    numeroPuertas = nuevoNumero;
}

// Sobrescritura: reutiliza el método de la base y añade información del coche
void Coche::mostrarInformacion() {
    Vehiculo::mostrarInformacion();
    std::cout << "Número de puertas: " << numeroPuertas << std::endl;
}

// Getter
int Coche::obtenerNumeroPuertas() {
    return numeroPuertas;
}
