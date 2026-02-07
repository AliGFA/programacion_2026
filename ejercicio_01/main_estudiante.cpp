#include "estudiante.h"
#include <iostream>

using namespace std;

int main() {
    cout << "=== Sistema de Gestión de Estudiante ===" << endl;
    cout << endl;

    // Primer estudiante: vacío al principio
    Estudiante estudiante1;
    cout << "Estudiante 1 (constructor por defecto):" << endl;
    estudiante1.mostrarInformacionCompleta();
    cout << endl;

    estudiante1.actualizarNombre("Carlos Ramírez Soto");
    estudiante1.actualizarCodigo("EST-2026-089");
    estudiante1.actualizarEdad(19);
    estudiante1.actualizarPromedio(8.7);
    estudiante1.actualizarActivo(true);

    cout << "Estudiante 1 después de actualizar:" << endl;
    estudiante1.mostrarInformacionCompleta();
    estudiante1.calcularEstadoAcademico();
    cout << endl;

    // Segundo estudiante: datos listos desde el inicio
    Estudiante estudiante2("Ana Sofía Morales", "EST-2026-147", 21, 9.5, true);
    cout << "Estudiante 2 (constructor con parámetros):" << endl;
    estudiante2.mostrarInformacionCompleta();
    estudiante2.calcularEstadoAcademico();
    cout << endl;

    cout << "Incrementando edad del estudiante 2:" << endl;
    estudiante2.incrementarEdad();
    estudiante2.mostrarEdad();
    cout << endl;

    // Probamos si rechaza un promedio fuera de rango
    cout << "Intentando actualizar promedio con valor inválido:" << endl;
    estudiante2.actualizarPromedio(15.0);
    estudiante2.mostrarPromedio();
    cout << endl;

    return 0;
}
