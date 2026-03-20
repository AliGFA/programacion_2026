#include <iostream>

#include "figuras.h"
#include "circulo.h"
#include "rectangulo.h"

int main(){
	std::cout << "Figuras Geometricas" << std::endl;
	std::cout << std::endl;

	Figura* f1 = new Circulo("Circulo", 16.0);
	Figura* f2 = new Rectangulo("Rectangulo", 9.0, 21.0);

	std::cout << "Figura 1" << std::endl;
	f1->describir();
	std::cout << "Area: " << f1->obtArea() << std::endl;
	std::cout << std::endl;

	std::cout << "Figura 2" << std::endl;
	f2->describir();
	std::cout << "Area: " << f2->obtArea() << std::endl;
	std::cout << std::endl;

	std::cout << "Tratamiento uniforme con Figura*" << std::endl;
	Figura* figuras[] = {f1, f2};
	for(int i = 0; i < 2; i++){
		figuras[i]->describir();
		std::cout << "Area: " << figuras[i]->obtArea() << std::endl;
	}

	delete f1;
	delete f2;

	return 0;
}
