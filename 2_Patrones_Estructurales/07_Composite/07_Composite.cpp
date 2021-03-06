// 07_Composite.cpp:
#include "stdafx.h"
#include <iostream>

class IComponente {
public:
	virtual int opera() = 0;
};
class Compuesto : public IComponente {
protected:
	IComponente * c1;	// operadando izquierda
	IComponente* c2;	// operadando derecha
	Compuesto(IComponente* c1, IComponente* c2) : c1(c1), c2(c2) { }
};
class Hoja : public IComponente {
private:
	int valor;
public:
	Hoja(int v) : valor(v) {}
	int opera() { return valor;  }
};
class Suma : public Compuesto {
public:
	Suma(IComponente* c1, IComponente* c2) 
		: Compuesto(c1, c2) { }
	int opera() { return c1->opera() + c2->opera(); }
};
class Resta : public Compuesto {
public:
	Resta(IComponente* c1, IComponente* c2) : Compuesto(c1, c2) { }
	int opera() { return c1->opera() - c2->opera(); }
};
class Multiplicacion : public Compuesto {
public:
	Multiplicacion(IComponente* c1, IComponente* c2) : Compuesto(c1, c2) { }
	int opera() { return c1->opera() * c2->opera(); }
};
int main()
{
	Hoja* h1 = new Hoja(7);
	IComponente* h2 = new Hoja(5);
	IComponente* h3 = new Hoja(2);
	IComponente* h4 = new Hoja(1);
	IComponente* h5 = new Hoja(3);

	IComponente* s1 = new Multiplicacion(h1, h2);
	IComponente* s2 = new Resta(h3, h4);
	IComponente* s3 = new Suma(s2, h5);
	IComponente* s4 = new Suma(s1, s3);

	std::cout << "Resultado: " << s4->opera() << std::endl;
	system("pause");

    return 0;
}

