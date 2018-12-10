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

class FiguraFactory {
public:
	Circulo * dameCirculo() {
		return new Circulo();
	}
	Figura *dameFigura(figuras tipo) {
		if (tipo == figuras::Circulo) {
			return dameCirculo();
		}
		else if (tipo == figuras::Rectangulo) {
			return new Rectangulo();
		}
		else if (tipo == figuras::Triangulo) {
			return new Triangulo();
		}
	}
};
int main()
{
	std::cout << "Fabricando.. " << std::endl;
	FiguraFactory* fabrica = new FiguraFactory();

	Circulo *circulo;
	circulo = fabrica->dameCirculo();
	Figura *rectangulo = fabrica->dameFigura(figuras::Rectangulo);
	Figura *triangulo = fabrica->dameFigura(figuras::Triangulo);

	circulo->pinta();
	rectangulo->pinta();
	triangulo->pinta();

	system("pause");
    return 0;
}

