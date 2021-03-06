#include "stdafx.h"
#include <iostream>

class SingletonSencillo {
public:
	static SingletonSencillo* getInstancia() {
		if (instancia == nullptr) {
			instancia = new SingletonSencillo();
		}
		return instancia;
	}
	void metodo() {
		std::cout << "Hola soy yo." << std::endl;
	}
private:
	static SingletonSencillo *instancia;

	SingletonSencillo() {
		std::cout << "Constructor" << std::endl;
	}
};
SingletonSencillo *SingletonSencillo::instancia;

int main()
{
	std::cout << "Comenzando aplicacion" << std::endl;
	SingletonSencillo* unSingleton = SingletonSencillo::getInstancia();
	unSingleton->metodo();

	unSingleton = SingletonSencillo::getInstancia();
	unSingleton->metodo();
	// SingletonSencillo *sen = new SingletonSencillo();
	system("pause");
    return 0;
}

