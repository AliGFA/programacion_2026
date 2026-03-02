/*
 * Instrucciones de Compilación:
 *
 * Para compilar este programa, utiliza el siguiente comando:
 *
 *     g++ vehiculo.cpp coche.cpp main.cpp -o herencia
 *
 * O si prefieres usar la opción de estándar C++17:
 *
 *     g++ -std=c++17 vehiculo.cpp coche.cpp main.cpp -o herencia
 *
 * Para ejecutar el programa:
 *
 *     ./herencia
 */

#include <iostream>
#include "vehiculo.h"
#include "coche.h"
#include "camion.h"
#include "moto.h"
#include "autobus.h"
using namespace std;


int main() {
 int opcion;   
 
 while(opcion != 5){
    std::cout << "Sistema de datos de vehiculos" << std::endl;
    std::cout << "=============================" <<std::endl;
    std::cout << "¿Que desea hacer?" <<std::endl;
    std::cout << "1. Agregar un nuevo vehiculo" <<std::endl;
    std::cout << "2. Mostrar informacion de un vehiculo" <<std::endl;
    std::cout << "3. Mostrar informacion de todos los vehiculos" << std::endl;
    std::cout << "4. Actualizar informacion de un vehiculo" <<std::endl;
    std::cout << "5. Salir" <<std::endl;
    
   
    std::cin >> opcion;

    if (opcion == 1) {
        std::cout << "¿Que tipo de vehiculo desea agregar?" <<std::endl;
        std::cout << "1. Coche" <<std::endl;
        std::cout << "2. Camion" <<std::endl;
        std::cout << "3. Moto" <<std::endl;
        std::cout << "4. Autobus" <<std::endl;

        int tipoVehiculo;
        std::cin >> tipoVehiculo;

        if (tipoVehiculo == 1) {
            std::string marca, modelo, matricula; int año, numeroPuertas;

            std::cout << "Ingrese la marca del coche: ";
            std::cin >> marca;
            std::cout << "Ingrese el modelo del coche: ";
            std::cin >> modelo;
            std::cout << "Ingrese el año del coche: ";
            std::cin >> año;
            std::cout << "Ingrese el número de puertas del coche: ";
            std::cin >> numeroPuertas;
            std::cout << "Ingrese la matrícula del coche: ";
            std::cin >> matricula;
            

            Coche nuevoCoche(marca, modelo, año, matricula, numeroPuertas);
            std::cout << "Coche agregado al catalogo." << std::endl;
        }
        else if (tipoVehiculo == 2) {
            std::string marca, modelo, matricula, tipoRemolque;
            int año;
            float capacidadCarga;

            std::cout << "Ingrese la marca del camión: ";
            std::cin >> marca;
            std::cout << "Ingrese el modelo del camión: ";
            std::cin >> modelo;
            std::cout << "Ingrese el año del camión: ";
            std::cin >> año;
            std::cout << "Ingrese la capacidad de carga del camión (en toneladas): ";
            std::cin >> capacidadCarga;
            std::cout << "Ingrese el tipo de remolque del camión: ";
            std::cin >> tipoRemolque;
            std::cout << "Ingrese la matrícula del camión: ";
            std::cin >> matricula;

            Camion nuevoCamion(marca, modelo, año, matricula, capacidadCarga, tipoRemolque);
            std::cout << "Camión agregado al catalogo." << std::endl;
        }
        else if (tipoVehiculo == 3) {
            std::string marca, modelo, matricula, tipoManillar;
            int año;
            string cilindrada;

            std::cout << "Ingrese la marca de la moto: ";
            std::cin >> marca;
            std::cout << "Ingrese el modelo de la moto: ";
            std::cin >> modelo;
            std::cout << "Ingrese el año de la moto: ";
            std::cin >> año;
            std::cout << "Ingrese la cilindrada de la moto (en cc): ";
            std::cin >> cilindrada;
            std::cout << "Ingrese el tipo de manillar de la moto: ";
            std::cin >> tipoManillar;
            std::cout << "Ingrese la matrícula de la moto: ";
            std::cin >> matricula;

            Moto nuevaMoto(marca, modelo, año, matricula, tipoManillar, cilindrada);
            std::cout << "Moto agregada al catalogo." << std::endl;
        }
        else if (tipoVehiculo == 4) {
            std::string marca, modelo, matricula;
            int año, numeroPasajeros, numeroAsientos;

            std::cout << "Ingrese la marca del autobús: ";
            std::cin >> marca;
            std::cout << "Ingrese el modelo del autobús: ";
            std::cin >> modelo;
            std::cout << "Ingrese el año del autobús: ";
            std::cin >> año;
            std::cout << "Ingrese el número de pasajeros del autobús: ";
            std::cin >> numeroPasajeros;
            std::cout << "Ingrese el número de asientos del autobús: ";
            std::cin >> numeroAsientos;
            std::cout << "Ingrese la matrícula del autobús: ";
            std::cin >> matricula;

            Autobus nuevoAutobus(marca, modelo, año, matricula, numeroPasajeros, numeroAsientos);
            std::cout << "Autobús agregado al catalogo." << std::endl;
        }
    else if (opcion == 2) {
        std::cout << "" << std::endl;
    }
    else if (opcion == 3) {
        std::cout << "" << std::endl;
    }
    else if (opcion == 4) {
        std::cout << "" << std::endl;
    }
    else if (opcion == 5) {
        std::cout << "Cerrando programa" << std::endl;
        break;
    }
    else {
        std::cout << "Opción no es valida, intenta otra vez" << std::endl;
    }


    return 0;
}}}
