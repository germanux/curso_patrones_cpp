// 02_Fabrica_Ejercicio.cpp : Defines the entry point for the console application.
//

/*
Vamos a usar el patrón Factory para mostrar cómo puede simplificar la creación de objetos cuya
creación es compleja. Concretamente vamos a mostrar cómo se gestionaría una cafetería
StarDucks, cuya fama viene dada por ciertas bebidas calientes.
Cuando un cliente llega a StarDucks elige una bebida base, que puede ser "Té,café o chocolate".
Después, pueden configurar su bebida como sigue
• Descafeinado → Se hace el café o te sin cafeína. El chocolate no se ve afectado
• Azucarado → Se añade azucar al café o te. El chocolate no se ve afectado
• Nata → Se echa un chorro de nata por encima
• Leche → Se añade leche a la bebida
Tras crearse las bebidas, deben tener un método servir que muestra la descripción de la bebida,
como por ejemplo Té descafeinado azucarado con Leche.
*/
#include "stdafx.h"
#include "BebidasStarducks.h"
#include "list"
#include "iostream"

int main()
{
	StarducksFactory* fabrica = new StarducksFactory();

	int eleccion = 0;
	while (true) {
		//Recogemos la seleccion de bebida
		std::cout << "Eliga bebida:" << std::endl;
		std::cout << " 1- Cafe" << std::endl;
		std::cout << " 2- Te" << std::endl;
		std::cout << " 3- Chocolate" << std::endl;
		std::cout << " 0- Salir" << std::endl;
		std::cin >> eleccion;

		//si es 0 salimos
		if (eleccion == 0) { break; }

		//En función de la bebida elegida, seleccionamos su tipo
		tipoBebida tipoBebida;
		if (eleccion == 1) { tipoBebida = tipoBebida::Cafe; }
		if (eleccion == 2) { tipoBebida = tipoBebida::Te; }
		if (eleccion == 3) { tipoBebida = tipoBebida::Chocolate; }

		//Elegimos los complementos
		int compl= 0;
		//creamos la lista
		std::list<complementos> listaComplementos;
		do
		{
			std::cout << "Incluir complemento: " << std::endl;
			std::cout << " 1- Con Leche" << std::endl;
			std::cout << " 2- Con Nata" << std::endl;
			//El chocolate no puede ser ni descafeinado ni con azucar
			if (eleccion != 3) {
				std::cout << " 3- Descafeinado" << std::endl;
				std::cout << " 4- Con azucar" << std::endl;
			}
			std::cout << " 0- Parar de incluir" << std::endl;
			std::cin >> compl;

			//una vez elegido el complemento lo metemos en la lista
			if (compl== 1) { listaComplementos.push_back(complementos::Leche); }
			if (compl== 2) { listaComplementos.push_back(complementos::Nata); }
			if (compl== 3) {
				listaComplementos.push_back(complementos::Descafeinado);
			}
			if (compl== 4) { listaComplementos.push_back(complementos::Azucar); }
		} while (compl != 0);

		//Una vez recogido el tipo de bebida y la lista de complementos se la pasamos
		//a la fabrica para que nos la genere
		Bebida* nuevaBebida = fabrica->dameBebida(tipoBebida, listaComplementos);
		//la servimos
		nuevaBebida->sirveBebida();
	}

	return 0;
}

