#include "stdafx.h"
#include <iostream>
#include "figuras.h"
#include "colores.h"

class FactoriaAbstracta {
public:
	virtual Figura* dameFigura(figuras tipo) = 0;
	virtual Color* dameColor(colores color) = 0;
};
class FiguraFactory : public FactoriaAbstracta {
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
	Color *dameColor(colores color) { return NULL; }
};
enum class fabricas {Colores, Figuras};

class FactoriaDeFactorias {
public:
	static FactoriaAbstracta* dameFabrica(fabricas tipo) {
		if (tipo == fabricas::Figuras)
			return new FiguraFactory();		
	}
};
int main()
{
	FactoriaAbstracta *f1 = FactoriaDeFactorias::dameFabrica(fabricas::Figuras);

	Figura *circ = f1->dameFigura(figuras::Circulo);
	circ->pinta();
	system("pause");
    return 0;
}

