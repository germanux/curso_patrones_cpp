// 04_FabricaAbstracta_Ejercicio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BebidaStarducks.h"

class AbstractStarducksFactory {
public:
	virtual Bebida* dameBebida(tipoBebida tipo, std::list<complementos>
		complementos) = 0;
	virtual void dimeGanancias() = 0;
};

class StarducksFactoryOriginal :public AbstractStarducksFactory {
public:
	double capitalAcumulado = 0;
	void dimeGanancias() {
		std::cout << "Esta tienda ha ganado " << capitalAcumulado
			<< "€" << std::endl;
	}
	Bebida* dameBebida(tipoBebida tipo, std::list<complementos> listaCompl) {
		Bebida* nuevaBebida;
		if (tipo == tipoBebida::Cafe) {
			nuevaBebida = new Cafe();
			capitalAcumulado += 1.80;
		}
		else if (tipo == tipoBebida::Chocolate) {
			nuevaBebida = new Chocolate();
			capitalAcumulado += 2.0;
		}
		else if (tipo == tipoBebida::Te) {
			nuevaBebida = new Te(); capitalAcumulado +=
				1.7;
		}
		else { return NULL; }
		for (auto i : listaCompl) {
			if (i == complementos::Azucar) {
				nuevaBebida->ponAzucar();
			}
			else if (i == complementos::Descafeinado) {
				nuevaBebida->ponDescafeinado();
			}
			else if (i == complementos::Leche) {
				nuevaBebida->ponLeche();
			}
			else if (i == complementos::Nata) {
				nuevaBebida->ponNata();
				capitalAcumulado += 0.2;
			}
		}
		return nuevaBebida;
	}
};

class StarducksFactoryNueva :public AbstractStarducksFactory {
public:
	double capitalAcumulado = 0;
	void dimeGanancias() {
		std::cout << "Esta tienda ha ganado " << capitalAcumulado
			<< "€" << std::endl;
	}
	Bebida* dameBebida(tipoBebida tipo, std::list<complementos> listaCompl) {
		Bebida* nuevaBebida;
		if (tipo == tipoBebida::Cafe) {
			nuevaBebida = new Cafe(); capitalAcumulado +=
				1.70;
		}
		else if (tipo == tipoBebida::Chocolate) {
			nuevaBebida = new Chocolate();
			capitalAcumulado += 1.9;
		}
		else if (tipo == tipoBebida::Te) {
			nuevaBebida = new Te(); capitalAcumulado +=
				1.5;
		}
		else { return NULL; }
		//No tiene azucar, así que no lo implementamos
		for (auto i : listaCompl) {
			if (i == complementos::Descafeinado) {
				nuevaBebida->ponDescafeinado();
			}
			else if (i == complementos::Leche) {
				nuevaBebida->ponLeche();
			}
			else if (i == complementos::Nata) {
				nuevaBebida->ponNata();
				capitalAcumulado += 0.1;
			}
		}
		return nuevaBebida;
	}
};


enum class tipoFabricas { Original, Nueva };

class StarducksFactoryProducer {
public:
	static AbstractStarducksFactory* dameFabrica(tipoFabricas tipo) {
		if (tipo == tipoFabricas::Original) {
			return new StarducksFactoryOriginal();
		}
		else if (tipo == tipoFabricas::Nueva) {
			return new StarducksFactoryNueva();
		}
		else { return NULL; }
	}
};

int main()
{
	AbstractStarducksFactory* fabricaOriginal =
		StarducksFactoryProducer::dameFabrica(tipoFabricas::Original);

	AbstractStarducksFactory* fabricaNueva =
		StarducksFactoryProducer::dameFabrica(tipoFabricas::Nueva);

	AbstractStarducksFactory* fabricaActual;
	int fabrica = 0;
	int eleccion = 0;

	while (true) {
		std::cout << "Eliga Tienda:" << std::endl;
		std::cout << " 1- Original" << std::endl;
		std::cout << " 2- Nueva" << std::endl;
		std::cout << " 0- Salir" << std::endl;
		std::cin >> fabrica;
		if (fabrica == 0) { break; } //con 0 salimos del programa
		fabricaActual = ((fabrica == 1) ? fabricaOriginal : fabricaNueva);

		std::cout << "Eliga bebida:" << std::endl;
		std::cout << " 1- Cafe" << std::endl;
		std::cout << " 2- Te" << std::endl;
		std::cout << " 3- Chocolate" << std::endl;
		
		std::cin >> eleccion;
		

		tipoBebida tipoB;
		if (eleccion == 1) { tipoB = tipoBebida::Cafe; }
		if (eleccion == 2) { tipoB = tipoBebida::Te; }
		if (eleccion == 3) { tipoB = tipoBebida::Chocolate; }

		int complem = 0;
		std::list<complementos> listaComplementos;
		do
		{
			std::cout << "Incluir complemento: " << std::endl;
			std::cout << " 1- Con Leche" << std::endl;
			std::cout << " 2- Con Nata" << std::endl;
			if (eleccion != 3) {
				std::cout << " 3- Descafeinado" << std::endl;
				if (fabrica == 1) {//si la fabrica es la nueva no mostramos azucar
					std::cout << " 4- Con azucar" << std::endl;
				}
			}
			std::cout << " 0- Parar de incluir" << std::endl;
			std::cin >> complem;
			if (complem == 1) { 
				listaComplementos.push_back(complementos::Leche); 
			}
			if (complem == 2) { 
				listaComplementos.push_back(complementos::Nata); 
			}
			if (complem == 3) {
				listaComplementos.push_back(complementos::Descafeinado);
			}
			if (complem == 4) {
				listaComplementos.push_back(complementos::Azucar);
			}
		} while (complem != 0);
		Bebida* nuevaBebida = fabricaActual->dameBebida(tipoB, listaComplementos);
		nuevaBebida->sirveBebida();
	}
	fabricaNueva->dimeGanancias();
	fabricaOriginal->dimeGanancias();
	system("pause");
	return 0;
}

