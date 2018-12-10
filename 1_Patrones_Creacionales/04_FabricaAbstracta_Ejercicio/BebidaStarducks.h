#pragma once
#include <iostream>
#include "list"

enum class tipoBebida { Cafe, Te, Chocolate };
enum class complementos { Azucar, Leche, Nata, Descafeinado };

class Bebida {
public:
	virtual void ponAzucar() = 0;
	virtual void ponLeche() = 0;
	virtual void ponNata() = 0;
	virtual void ponDescafeinado() = 0;
	virtual void sirveBebida() = 0;
protected:
	bool azucar = false;
	bool leche = false;
	bool nata = false;
	bool descafeinado = false;
};

class Cafe : public Bebida {
public:
	Cafe() {}
	virtual void ponAzucar() { azucar = true; };
	virtual void ponLeche() { leche = true; };
	virtual void ponNata() { nata = true; };
	virtual void ponDescafeinado() { descafeinado = true; };
	virtual void sirveBebida() {
		std::cout << "Cafe ";
		std::cout << ((leche == true) ? "con leche " : "solo ");
		std::cout << ((descafeinado == true) ? "descafeinado " : "");
		std::cout << ((azucar == true) ? "azucarado " : "sin azucar ");
		std::cout << ((nata == true) ? "con nata " : "");
		std::cout << std::endl;
	}
};

class Te : public Bebida {
public:
	Te() {}
	virtual void ponAzucar() { azucar = true; };
	virtual void ponLeche() { leche = true; };
	virtual void ponNata() { nata = true; };
	virtual void ponDescafeinado() { descafeinado = true; };
	virtual void sirveBebida() {
		std::cout << "Te ";
		std::cout << ((leche == true) ? "con leche " : "solo ");
		std::cout << ((descafeinado == true) ? "descafeinado " : "");
		std::cout << ((azucar == true) ? "azucarado " : "sin azucar ");
		std::cout << ((nata == true) ? "con nata " : "");
		std::cout << std::endl;
	}
};

class Chocolate : public Bebida {
public:
	Chocolate() {}
	virtual void ponAzucar() { azucar = true; };
	virtual void ponLeche() { leche = true; };
	virtual void ponNata() { nata = true; };
	virtual void ponDescafeinado() { };
	virtual void sirveBebida() {
		std::cout << "chocolate ";
		std::cout << ((leche == true) ? "con leche " : "solo ");
		std::cout << ((nata == true) ? "con nata " : "");
		std::cout << std::endl;
	}
};

