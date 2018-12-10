#pragma once
#include "stdafx.h"
#include <iostream>

enum class figuras { Rectangulo, Circulo, Triangulo };

class Figura {
public:
	virtual void pinta() = 0;
};
class Rectangulo : public Figura {
	friend class FiguraFactory;
public:
	virtual void pinta() {
		std::cout << "Soy un Rectangulo" << std::endl;
	}
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
class Triangulo : public Figura {
	friend class FiguraFactory;
public:
	virtual void pinta() {
		std::cout << "Soy un Triangulo" << std::endl;
	}
private:
	Triangulo() {};
};
