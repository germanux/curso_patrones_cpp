// 09_Observer.cpp: 
#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Participante {	// Observador
protected:
	int posicion;
	int velocidad;
public:
	Participante(int pos, int vel)
		: posicion(pos), velocidad(vel) {}
	virtual int moverse() = 0; // Método aviso
	/// virtual int terminar() = 0; // Otro Método aviso
	virtual string getNombre() = 0; //Nombre a su manera
	int getPosicion() { return posicion; }
	void reiniciarPos() { posicion = 0; }
};
class Persona : public Participante {
private:
	string nombre, apellidos;
public:
	Persona(string nombre, string apell, int vel)
		:Participante(0, vel), 
		nombre(nombre), apellidos(apell) {}
	int moverse() {
		posicion += velocidad;
		return posicion;
	}
	string getNombre() {
		return nombre + " " + apellidos;
	}
};
class Camion : public Participante {
private:
	string matricula;
public:
	Camion(string mat) :Participante(0, 1), matricula(mat) {}
	int moverse() {
		posicion += velocidad;		
		velocidad += 3; // Tiene una aceleracion de 3
		return posicion;
	}
	string getNombre() {
		return matricula;
	}
};
class Carrera {	// Gestor de eventos que avisa a los participantes
private:
	list<Participante*>* listaParticipantes;
	// la posición que tenemos que alcanzar para ganar
	int meta;
public:
	Carrera(int meta) : meta(meta) {
		listaParticipantes = new list<Participante*>();
	}
	void addParticipante(Participante* part) {
		listaParticipantes->push_back(part);
	}
	// Cambio de estado
	void comenzarCarrera() {
		bool seguirMoviendo = true;
		int turno = 0;
		while (seguirMoviendo) {
			// Notificar a los elementos subscritos 
			for (auto participante : *listaParticipantes) {
				participante->moverse();
				cout << "Soy el participante " << participante->getNombre() << " y estoy en posicion " << participante->getPosicion()
					<< endl;
				// Cuando alguien llega a la meta
				if (participante->getPosicion() >= meta) {
					seguirMoviendo = false;
					cout << "**** TENEMOS GANADOR!! **** " << endl;
					cout << "**** " << participante->getNombre();
				}
			}
			cout << "----------- Fin de turno -------------" << endl;
		}
		terminarCarrera();
	}
	void terminarCarrera() {
		for (auto participante : *listaParticipantes) {
			participante->reiniciarPos();
		}
	}
};
class Robot : public Participante {
private:
	string nombreFabrica;
	int contadorTurbo;
public:
	Robot(string nom) :Participante(0, 10), 
		nombreFabrica(nom), contadorTurbo(0)  {}
	int moverse() {
		contadorTurbo++;
		if (contadorTurbo == 5) {
			contadorTurbo = 0;
			posicion += velocidad * 3;
		} else  {
			posicion += velocidad;
		}
		return posicion;
	}
	string getNombre() {
		return nombreFabrica;
	}
};
int main()
{
	Participante *bud = new Persona("Bud", "Spencer", 10);
	Participante *harry = new Persona("Hurry", "El sucio", 20);
	Participante *optimusPrime = new Camion("CXD-9090");
	Participante *c3po = new Robot("C3P0");

	// Configuramos carrera:
	Carrera *carrera = new Carrera(200);
	carrera->addParticipante(bud);
	carrera->addParticipante(harry);
	carrera->addParticipante(optimusPrime);
	carrera->addParticipante(optimusPrime);

	carrera->comenzarCarrera();
	system("pause");
    return 0;
}

