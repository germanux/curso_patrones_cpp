#include "stdafx.h"
#include <iostream>
using namespace std;
class Rectangulo {
public:
	virtual void pinta() = 0;
};
class RectanguloAntiguo {
private:
	int x1, y1, x2, y2;
public:
	// RectanguloAntiguo() {}
	RectanguloAntiguo(int x1, int y1, int x2, int y2)
				: x1(x1), y1(y1), x2(x2), y2(y2) {}
	void dibujaViejo() {
		cout << "(" << x1 << ", " << y1 << "), ";
		cout << "(" << x2 << ", " << y2 << ")";
	}
};
class RectanguloAdaptado : public Rectangulo, private RectanguloAntiguo {
public: 
	RectanguloAdaptado(int x, int y, int ancho, int alto)
		: RectanguloAntiguo(x, y, x + ancho, y + alto) { };
	void pinta() {
		cout << "Adaptando..." << endl;
		dibujaViejo();
	}
};
class RectanguloJaime : public Rectangulo, protected RectanguloAntiguo {
private:
	int x, y, ancho, alto;
public:
	RectanguloJaime(int x, int y, int ancho, int alto)
		: x(x), y(y), ancho(ancho), alto(alto), RectanguloAntiguo(0,0,0,0) {}
};
int main()
{
	Rectangulo* r = new RectanguloAdaptado(3, 8, 20, 30);
	r->pinta();
	system("pause");
    return 0;
}

