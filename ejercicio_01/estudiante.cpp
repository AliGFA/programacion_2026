#include "estudiante.h"
#include <iostream>

using namespace std;

// Default, todo vacío
Estudiante::Estudiante() {
    this->nombre = "";
    this->codigo = "";
    this->edad = 0;
    this->promedio = 0.0;
    this->activo = false;
}

Estudiante::Estudiante(string nombre, string codigo, int edad, float promedio, bool activo) {
    this->nombre = nombre;
    this->codigo = codigo;
    this->edad = edad;
    this->promedio = promedio;
    this->activo = activo;
}

void Estudiante::actualizarNombre(string nuevoNombre) {
    this->nombre = nuevoNombre;
}

void Estudiante::actualizarCodigo(string nuevoCodigo) {
    this->codigo = nuevoCodigo;
}

void Estudiante::actualizarEdad(int nuevaEdad) {
    this->edad = nuevaEdad;
}

void Estudiante::actualizarPromedio(float nuevoPromedio) {
    if (nuevoPromedio >= 0.0 && nuevoPromedio <= 10.0) {
        this->promedio = nuevoPromedio;
    } else {
        cout << "Error: El promedio debe estar entre 0.0 y 10.0" << endl;
    }
}

void Estudiante::actualizarActivo(bool nuevoEstado) {
    this->activo = nuevoEstado;
}

string Estudiante::obtenerNombre() {
    return this->nombre;
}

string Estudiante::obtenerCodigo() {
    return this->codigo;
}

int Estudiante::obtenerEdad() {
    return this->edad;
}

float Estudiante::obtenerPromedio() {
    return this->promedio;
}

bool Estudiante::obtenerActivo() {
    return this->activo;
}

void Estudiante::mostrarNombre() {
    cout << "Nombre: " << this->nombre << endl;
}

void Estudiante::mostrarCodigo() {
    cout << "Código: " << this->codigo << endl;
}

void Estudiante::mostrarEdad() {
    cout << "Edad: " << this->edad << " años" << endl;
}

void Estudiante::mostrarPromedio() {
    cout << "Promedio: " << this->promedio << endl;
}

void Estudiante::mostrarActivo() {
    if (this->activo) {
        cout << "Estado: Activo" << endl;
    } else {
        cout << "Estado: Inactivo" << endl;
    }
}

void Estudiante::mostrarInformacionCompleta() {
    mostrarNombre();
    mostrarCodigo();
    mostrarEdad();
    mostrarPromedio();
    mostrarActivo();
}

void Estudiante::incrementarEdad() {
    this->edad++;
}

void Estudiante::calcularEstadoAcademico() {
    cout << "Estado académico: ";
    if (this->promedio >= 9.0 && this->promedio <= 10.0) {
        cout << "Excelente" << endl;
    } else if (this->promedio >= 8.0 && this->promedio < 9.0) {
        cout << "Muy Bueno" << endl;
    } else if (this->promedio >= 7.0 && this->promedio < 8.0) {
        cout << "Bueno" << endl;
    } else if (this->promedio >= 6.0 && this->promedio < 7.0) {
        cout << "Regular" << endl;
    } else if (this->promedio >= 0.0 && this->promedio < 6.0) {
        cout << "Necesita Mejorar" << endl;
    }
}
