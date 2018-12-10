#pragma once
#include "iostream" //para trabajar con entrada/salida

enum class figuras { Rectangulo, Cuadrado, Circulo };

class Figura {
public:
	virtual void pinta() = 0;
};

class Rectangulo : public Figura {
	//Con la palabra friend decimos que esta clase puede utilizar los atributos y 
	//metodos publicos
	friend class FiguraFactory;
public:
	virtual void pinta() {
		std::cout << "Soy un Rectangulo" << std::endl;
	}
	//Creamos el constructor privado para que nadie pueda crear la clase sin 
	//pasar por el FiguraFactory
private:
	Rectangulo() {};
};

class Circulo : public Figura {
	friend class FiguraFactory;
public:
	virtual void pinta() {
		std::cout << "Soy un Circulo" << std::endl;
	}
private:
	Circulo() {};
};

class Cuadrado : public Figura {
	friend class FiguraFactory;
public:
	virtual void pinta() {
		std::cout << "Soy un Cuadrado" << std::endl;
	}
private:
	Cuadrado() {};
};

