// 09_Decorator.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class DecoratorShape {
public:
	virtual void pinta() = 0;
	DecoratorShape(int x, int y) : x(x), y(y) {};
protected:
	int x, y;
};
class CirculoDeco : public DecoratorShape {
private:
	int r;
public:
	CirculoDeco(int x, int y, int r) : DecoratorShape(x, y), r(r) {}
	void pinta() {
		cout << " - CIRCULO x = " << x << ", y = " << y << ", r = " << r << endl;
	}
};
class RectanguloDeco : public DecoratorShape {
private:
	int ancho, alto;
public:
	RectanguloDeco(int x, int y, int an, int al) 
		: DecoratorShape(x, y), ancho(an), alto(al) {}

	void pinta() {
		cout << " - RECTANGULO x = " << x << ", y = " << y << ", " <<
			ancho << "x" << alto << endl;
	}
};

class Decorator : public DecoratorShape {
protected:
	DecoratorShape *objeto;
public:
	Decorator(DecoratorShape* obj) : 
		DecoratorShape(0, 0), objeto(obj) {};
	virtual void pinta() = 0;
};
class ColorRelleno : public Decorator {
public:
	ColorRelleno(DecoratorShape* obj, string col)
		: Decorator(obj), color(col) {}
	void pinta() {
		cout << "Relleno cambiado a " << color << " ";
		objeto->pinta();
	}
private:
	string color;
};
class GrosorLinea : public Decorator {
public:
	GrosorLinea(DecoratorShape* obj, int gros)
		: Decorator(obj), grosor(gros) {}
	void pinta() {
		cout << "Grosor de línea a " << grosor << " ";
		objeto->pinta();
	}
private:
	int grosor;

};

int main()
{
	DecoratorShape* tempCirc = new CirculoDeco(3, 5, 20);
	// Vamos a añadir funcionalidades
	DecoratorShape* circFinal = new ColorRelleno(tempCirc, "Rojo");
	circFinal->pinta();

	DecoratorShape* recVerdG5 = 
		new ColorRelleno(
			new GrosorLinea(
				new RectanguloDeco(7, 9, 30, 50), 11), "verde");

	recVerdG5->pinta();

	system("pause");
    return 0;
}

