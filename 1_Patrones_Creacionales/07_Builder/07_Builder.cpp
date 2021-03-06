// 07_Builder.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <list>
class Elemento {
public:
	virtual void mostrar() = 0;
};
class BebidaHamburgueseria : public Elemento { };
class Agua : public BebidaHamburgueseria {
public:
	virtual void mostrar() { std::cout << "Agua, "; }
};
class Cerveza : public BebidaHamburgueseria {
public:
	virtual void mostrar() { std::cout << "Cerveza, "; }
};
class Comida : public Elemento { };
class HamburguesaVegetal : public Comida {
	virtual void mostrar() { std::cout << "HamburguesaVegetal, "; }
};
class HamburguesaInfantil : public Comida {
	virtual void mostrar() { std::cout << "Hamburguesa Infantil, "; }
};
class HamburguesaDeluxe : public Comida {
	virtual void mostrar() { std::cout << "Hamburguesa Deluxe, "; }
};

class Menu {
private:
	std::list<Elemento*>* listaMenu;
public:
	Menu() {
		listaMenu = new std::list<Elemento*>();
	}
	void muestraMenu() {
		for (auto elem : *listaMenu) {
			elem->mostrar();
		}
	}
	void inserta(Elemento* nuevo) {
		listaMenu->push_back(nuevo);
	}
	~Menu() {
		for (auto elem : *listaMenu) {
			delete elem;
		}
		delete listaMenu;
	}
};
class MenuBuilder {
public:
	static Menu* dameMenuInfantil() {
		Menu* nuevo = new Menu();
		nuevo->inserta(new HamburguesaInfantil());
		nuevo->inserta(new Agua());
		return nuevo;
	}
};

int main()
{
	Menu* menuInf = MenuBuilder::dameMenuInfantil();
	std::cout << "Menu infantil: "<< std::endl;
	menuInf->muestraMenu();

	system("pause");
    return 0;
}

