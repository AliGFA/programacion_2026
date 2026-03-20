#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "figuras.h"

class Rectangulo : public Figura{
	private:
		double base;
		double altura;
	public:
		Rectangulo(std::string nombre, double base, double altura);
		double obtArea() override;
		void describir() override;
		double obtBase();
		double obtAltura();
};

#endif
