#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

using namespace std;
// Escribe "chcp 65001" en la terminal para que muestre los acentos correctamente
//ejemplo: chcp 65001; ./estudiante
     

class Estudiante {
private:
    string nombre;
    string codigo;
    int edad;
    float promedio;
    bool activo;

public:
    Estudiante();
    Estudiante(string nombre, string codigo, int edad, float promedio, bool activo);

    void actualizarNombre(string nuevoNombre);
    void actualizarCodigo(string nuevoCodigo);
    void actualizarEdad(int nuevaEdad);
    void actualizarPromedio(float nuevoPromedio);
    void actualizarActivo(bool nuevoEstado);

    string obtenerNombre();
    string obtenerCodigo();
    int obtenerEdad();
    float obtenerPromedio();
    bool obtenerActivo();

    void mostrarNombre();
    void mostrarCodigo();
    void mostrarEdad();
    void mostrarPromedio();
    void mostrarActivo();
    void mostrarInformacionCompleta();

    // Métodos útiles del estudiante
    void incrementarEdad();
    void calcularEstadoAcademico();
};

#endif
