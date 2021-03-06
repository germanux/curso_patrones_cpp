// 05_Memento.cpp: 
#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

class MementoVigilada;
// Nuestra clase de tarbajo
class Vigilada {
private:
	string estado;
	int datosNoImportantes;
public:
	Vigilada() {
		estado = "Inicial";
		datosNoImportantes = 0;
	}
	// Métodos de trabajo
	void cambiaEstado(string s) { estado = s; }
	string dameEstado() { return estado; }
	// Metodos patrón memento
	MementoVigilada* guardaEstado();
	void recupera(MementoVigilada* mv);
};
// Clase donde se guarda un estado
class MementoVigilada {
	friend class Vigilada;
private:
	string estado;
public:
	MementoVigilada(string s) : estado(s) {}
};
// Clase niñera (guarda todos estados)
class Nanny {
private: 
	list<MementoVigilada*>* listaMemento;
public:
	Nanny() { listaMemento = new list<MementoVigilada*>(); }
	~Nanny() { delete listaMemento; }
	void add(MementoVigilada* mv) { listaMemento->push_back(mv); }
	MementoVigilada* recupera(int i) {	// Buscamos por posicion
		for (auto it : *listaMemento) {
			if (i == 0) { return it; }
			i--;
		}
		return NULL;
	}
};
void Vigilada::recupera(MementoVigilada *v) { estado = v->estado; }
MementoVigilada* Vigilada::guardaEstado() { 
	return new MementoVigilada(estado);
}

int main()
{
	Nanny* n = new Nanny();
	Vigilada* v = new Vigilada();
	n->add(v->guardaEstado());	// Vacío
	v->cambiaEstado("Estado 2");
	v->cambiaEstado("Estado 3");
	n->add(v->guardaEstado());	// 3
	v->cambiaEstado("Estado 4");
	v->cambiaEstado("Estado 5");
	n->add(v->guardaEstado());	// 5
	v->cambiaEstado("Estado 6");

	cout << "Estado final " << v->dameEstado() << endl;
	cout << "Recuperamos el estado 1" << endl;
	v->recupera(n->recupera(1));
	cout << "Estado recuperado " << v->dameEstado() << endl;
	system("pause");
    return 0;
}

