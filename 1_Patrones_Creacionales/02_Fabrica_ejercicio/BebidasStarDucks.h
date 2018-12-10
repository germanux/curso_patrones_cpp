#pragma once
#include <iostream>
#include "list"

enum class tipoBebida {Cafe, Te, Chocolate };
enum class complementos {Azucar, Leche, Descafeinado };

class Bebida
{
public:
	virtual void ponAzucar() = 0;
	virtual void sirveBebida() = 0;
protected:
	bool azucar = false;
};
class Cafe : public Bebida {
public:
	Cafe() {}
	virtual void ponAzucar() { azucar = true; }
	virtual void sirveBebida() {
		std::cout << "Tome su Cafe ";
		if (azucar == true) {
			std::cout << "azucarado ";
		} else {
			std::cout << "sin azucar ";
		}
		std::cout << std::endl;
	}
};

class StarducksFactory {
public:
	Bebida * dameBebida(tipoBebida tipo, std::list<complementos> complementos);
};