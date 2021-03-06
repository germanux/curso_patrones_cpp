// 03_FabricaAbstracta.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "figuras.h"//incluimos las figuras y los colores
#include "colores.h"

/*
Ha llegado el momento de crear una fábrica de
fábricas, y para ello tenemos que agrupar ambas fábricas bajo una misma clase. Para ello, creamos
una nueva clase abstracta que va a tener definidos todos los métodos públicos que las fábricas
finales van a necesitar usar

Nos hemos creado el fichero 'figuras.h'
*/
class AbstractFactory {
public:
	virtual Color* dameColor(colores tipo) = 0;
	virtual Figura* dameFigura(figuras tipo) = 0;
};

//Creamos las factorias heredando de AbstractFactory
//El metodo que no usemos devolvemos NULL
class ColorFactory : public AbstractFactory {
public:
	Color* dameColor(colores tipo) {
		if (tipo == colores::Azul) {
			return new Azul();
		}
		else if (tipo == colores::Verde) {
			return new Verde();
		}
		else if (tipo == colores::Rojo) {
			return new Rojo();
		}
		return NULL;
	};

	Figura* dameFigura(figuras tipo) { return NULL; }

};

class FiguraFactory : public AbstractFactory {
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

	Color* dameColor(colores tipo) { return NULL; }
};


//Ya sólo necesitamos una fábrica que nos devuelva las fábricas necesarias para poder trabajar
enum class fabricas { Formas, Colores };

class FactoryOfFactories {
public:
	static AbstractFactory* dameFabrica(fabricas tipoFabrica) {
		if (tipoFabrica == fabricas::Formas) {
			return new FiguraFactory();
		}
		else if (tipoFabrica == fabricas::Colores) {
			return new ColorFactory();
		}
		else {
			return NULL;
		}
	}
};

int main()
{
	AbstractFactory* f1 = FactoryOfFactories::dameFabrica(fabricas::Colores);
	AbstractFactory* f2 = FactoryOfFactories::dameFabrica(fabricas::Formas);
	Figura* figura1 = f2->dameFigura(figuras::Cuadrado);
	Color* color1 = f1->dameColor(colores::Verde);
	figura1->pinta();
	color1->pinta();

	system("pause");
    return 0;
}

