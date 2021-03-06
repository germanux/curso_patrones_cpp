// 07_Command.cpp:
#include "stdafx.h"
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Medico {
private:
	string nombre;
public:
	Medico(string s) : nombre(s) {}
	void ponInyeccion(string paciente) {
		cout << nombre << " ha puesto inyeccion a " << paciente;
	}
	void diagnostica(string paciente) {
		cout << nombre << " ha diagnosticado a " << paciente;
	}
	void daReceta(string paciente) {
		cout << nombre << " ha dado receta a " << paciente;
	}
};
class CommandMedico {
public:
	virtual void ejecuta() = 0;
};
// Las distintas implenentaciones de comandos:
class PonInyeccion : public CommandMedico {
private:
	Medico * receptor;
	string paciente;
public:
	PonInyeccion(Medico *r, string p) : receptor(r), paciente(p) {}
	void ejecuta() {
		this->medicoPonInyeccion();
	}
	void medicoPonInyeccion() {
		receptor->ponInyeccion(paciente);
	}
};
class Diagnostica : public CommandMedico {
private:
	Medico * receptor;
	string paciente;
public:
	Diagnostica(Medico *r, string p) : receptor(r), paciente(p) {}
	void ejecuta() {
		this->medicoDiagnostica();
	}
	void medicoDiagnostica() {
		receptor->diagnostica(paciente);
	}
};
class DaReceta : public CommandMedico {
private:
	Medico * receptor;
	string paciente;
	string medicamento;
public:
	DaReceta(Medico *r, string p, string m) : 
		receptor(r), paciente(p), medicamento(m) {}
	void ejecuta() {
		this->daReceta();
	}
	void daReceta() {
		receptor->daReceta(paciente);
		cout << " del medicamento " << medicamento << endl;
	}
};
class BrokerMedico {
private:
	list<CommandMedico*>* ordenes;
public:
	BrokerMedico() {		
		this->ordenes = new list<CommandMedico*>();
	}
	void addOrden(CommandMedico* c) {
		ordenes->push_back(c);
	}
	void procesaOrdenes() {
		for (auto ord : *ordenes) {
			ord->ejecuta();
		}
		// limpiarOrdenes();
	}
	void limpiarOrdenes() {
		for (auto ord : *ordenes) {
			delete ord;
		}
		ordenes->clear();
	}
};
int main()
{
	Medico* m1 = new Medico("Beneplacito");
	Medico* m2 = new Medico("Rigoberta");

	BrokerMedico* mb = new BrokerMedico();
	CommandMedico* c1 = new Diagnostica(m1, "Sergio");

	mb->addOrden(c1);
	// mb->addOrden(c1); No se puede liberar dos veces
	mb->addOrden(new Diagnostica(m1, "Sergio"));
	mb->addOrden(new PonInyeccion(m1, "Pablo"));
	mb->addOrden(new Diagnostica(m2, "Sara"));
	mb->addOrden(new PonInyeccion(m2, "Teresa"));
	
	mb->procesaOrdenes();
	mb->limpiarOrdenes();

	system("pause");
    return 0;
}
void SinBroker() {
	Medico* m1 = new Medico("Beneplacito");
	Medico* m2 = new Medico("Rigoberta");

	CommandMedico* c1 = new Diagnostica(m1, "Sergio");
	CommandMedico* c2 = new PonInyeccion(m1, "Pablo");
	CommandMedico* c3 = new Diagnostica(m2, "Sara");

	c1->ejecuta();
	c2->ejecuta();
	c3->ejecuta();

	c2->ejecuta();	// m1->ponInyeccion("Pablo");
	c2->ejecuta();
	c2->ejecuta();
}
