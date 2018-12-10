// 02_Fabrica_ejercicio.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "BebidasStarDucks.h"

int main()
{
	StarducksFactory *fabricaBebidas = new StarducksFactory();
	int eleccion = 0;
	while (true) {
		std::cout << "Elige bebida:" << std::endl;
		std::cout << "  1 - Cafe" << std::endl;
		std::cout << "  0 - Salir" << std::endl;
		std::cin >> eleccion;
		if (eleccion == 0) { break; }
		tipoBebida tipoBebida;
		if (eleccion == 1) { tipoBebida = tipoBebida::Cafe; }
		int complem = 0;
		std::list<complementos> complementos;
		do {
			std::cout << "Incluir complemento: " << std::endl;
			if (tipoBebida != tipoBebida::Chocolate) {
				std::cout << " 1 - Con azucar" << std::endl;
			}
			std::cout << " 0 - Parar de incluir" << std::endl;

			std::cin >> complem;
			if (complem == 1)
				complementos.push_back(complementos::Azucar);
		} while (complem != 0);

		Bebida* nuevaBebida = fabricaBebidas->dameBebida(tipoBebida, complementos);
		nuevaBebida->sirveBebida();
	}
    return 0;
}

