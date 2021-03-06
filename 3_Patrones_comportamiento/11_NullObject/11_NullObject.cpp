// 11_NullObject.cpp:
#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Producto {
public:
	virtual bool esNulo() = 0;
	virtual void muestraPrecio() = 0;
};
class ProductoInstancia : public Producto {
private:
	int precio;
	string nombre;
public:
	ProductoInstancia(string n, int p) : precio(p), nombre(n) {}
	bool esNulo() { return false; }
	string getNombre() { return nombre; }
	void muestraPrecio() {
		cout << "El precio de " << nombre << " es de " << precio << endl;
	}
};

class ProductoNull : public Producto  {
private:
	static ProductoNull* instancia;
public:
	static ProductoNull* getInstanciaNull() {
		if (instancia == NULL)
			instancia = new ProductoNull();
		return instancia;
	}
	void muestraPrecio() {
		cout << "Producto no valido" << endl;
	}
	// No podemos saber el precio
	bool esNulo() { return true; }
};
ProductoNull* ProductoNull::instancia = NULL;

class FabricaProductos {
private:
	list<ProductoInstancia*>* lista;
public:
	FabricaProductos() {
		lista = new list<ProductoInstancia*>();
		lista->push_back(new ProductoInstancia("Jabón", 2));
		lista->push_back(new ProductoInstancia("Cepillo", 8));
		lista->push_back(new ProductoInstancia("Caviar", 200));
	}
	~FabricaProductos() {
		for (auto a : *lista) { delete a; };
		delete lista;
	}
	Producto* dameProducto(string nombreProd) {
		for (auto prod : *lista) { 
			if (prod->getNombre().compare(nombreProd) == 0)
				return prod;
		};
		return ProductoNull::getInstanciaNull();
	}
};
int main()
{
	FabricaProductos* fab = new FabricaProductos();
	Producto* p = fab->dameProducto("Cepillo");
	p->muestraPrecio();

	p = fab->dameProducto("Caviar");
	p->muestraPrecio();
	
	p = fab->dameProducto("Sable Laser");
	p->muestraPrecio();
	if (p->esNulo())
		cout << "No se encontro" << endl;
	system("pause");
    return 0;
}

