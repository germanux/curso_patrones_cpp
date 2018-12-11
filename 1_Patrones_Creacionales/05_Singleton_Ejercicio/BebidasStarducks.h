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
	virtual void ponAzucar() { };
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
class StarducksFactory {
public:
	//creamos una bebida con unoos complementos
	Bebida* dameBebida(tipoBebida tipo, std::list<complementos> complementos) {
		Bebida* nuevaBebida;

		//Creamos la bebida en funcion del tipoBebida
		if (tipo == tipoBebida::Cafe) { nuevaBebida = new Cafe(); }
		else if (tipo == tipoBebida::Chocolate) { nuevaBebida = new Chocolate(); }
		else if (tipo == tipoBebida::Te) { nuevaBebida = new Te(); }
		else { return NULL; }//si no es de ninguno de estos, devuevlo NULL

		//le ponemos a la bebida los complementos
		//Auto -> dejamos al compilador que le asigne el tipo (C++11)
		for (auto i : complementos) {
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
			}
		}

		return nuevaBebida;
	}

	static StarducksFactory* getInstancia() {
		if (instancia == nullptr)
			instancia = new StarducksFactory();
		return instancia;
	}

private:
	static StarducksFactory* instancia;
	StarducksFactory() {}
};

StarducksFactory* StarducksFactory::instancia = nullptr;