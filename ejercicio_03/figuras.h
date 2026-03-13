#ifndef FIGURAS.H
#define FIGURAS.H

#include <string>

class Figura{
    protected:
        std::string nombre;
    public:
        Figura(std::string nombre);
        virtual double obtArea() = 0;
        virtual void describir() = 0;
        virtual ~Figura();

        std::string obtNombre();
};



#endif