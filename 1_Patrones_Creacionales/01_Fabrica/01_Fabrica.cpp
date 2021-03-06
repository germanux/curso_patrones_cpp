// 01_Fabrica.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream" //para trabajar con entrada/salida

enum class figuras { Rectangulo, Cuadrado, Circulo };

class Figura {
public:
	virtual void pinta() = 0;
};

class Rectangulo : public Figura {
	//Con la palabra friend decimos que esta clase puede utilizar los atributos y 
	//metodos publicos. En este caso FiguraFactory podra utilizar el constructor
	//privado Rectangulo() y otros nombres privados si tuviera. 
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

//Extendemos estas clases de figura
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

class FiguraFactory {
public:
	Figura* dameFigura(figuras tipo) {
		if (tipo == figuras::Circulo) {
			return new Circulo();
		}
		else if (tipo == figuras::Cuadrado) {
			return new Cuadrado();
		}
		else if (tipo == figuras::Rectangulo) {
			return new Rectangulo();
		}
		return NULL;
	};
};


int main()
{
	FiguraFactory* fabrica = new FiguraFactory();
	Figura* circulo = fabrica->dameFigura(figuras::Circulo);
	Figura* rectangulo = fabrica->dameFigura(figuras::Rectangulo);
	Figura* cuadrado = fabrica->dameFigura(figuras::Cuadrado);
	circulo->pinta();
	rectangulo->pinta();
	cuadrado->pinta();

	// Esto daria error ya que el constructor el privado
	//rectangulo = new Rectangulo();
	
	// Esto tambien daria error ya que no podemos apuntar a una clase padre
	// con una clase hija (el enlace dinamico circulo es de tipo Figura)
	//Circulo* circulo2 = circulo;

	// Debemos castear
	Circulo* circulo2 = (Circulo*)circulo;
	circulo2->pinta();

	// Si hacemos esto como tiene el mismo metodo no daría error
	//Rectangulo* rectangulo2 = (Rectangulo*)circulo;
	//rectangulo2->pinta();

	system("pause");//se necesita iostream
	return 0;
}

