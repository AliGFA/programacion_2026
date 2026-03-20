#ifndef CIRCULO_H
#define CIRCULO_H

#include "figuras.h"


class Circulo : public Figura{
    private:
        double radio;
    public:
        Circulo(std::string nombre, double radio);
        double obtArea() override;
        void describir() override; 
        double obtRadio();

};



#endif