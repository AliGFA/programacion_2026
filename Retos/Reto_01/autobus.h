#ifndef AUTOBUS.H
#define AUTOBUS.H

#include <string>
#include "vehiculo.h"

class Autobus : public Vehiculo{
    private:
        int numeroPasajeros;
        int numeroAsientos;
    public:
        Autobus();
        Autobus(std::string marca, std::string modelo, int año, std::string matricula, int numeroPasajeros, int numeroAsientos);

        void actualizarPasajeros(int nuevoNumero);
        void actualizarAsientos(int nuevoNumero);

        void mostrarInformacion();

        int obtenerPasajeros();
        int obtenerAsientos();
};

#endif