// 02_Adapter_Ejercicio.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;

class BallenaSecurityInterfaz {
public:
	virtual string dameClave() = 0;
	virtual string dameUsuario() = 0;
};
class BallenaUser : public BallenaSecurityInterfaz {
protected:
	string user, pass;
public:
	BallenaUser(string u, string p) : user(u), pass(p) {}
	string dameUsuario() { return user; }
	string dameClave() { return pass; }
};
class BallenaCompany {
public:
	map<string, string>* claves;
	BallenaCompany() {
		claves = new map<string, string>();
		claves->insert(pair<string, string>("pepe", "1234"));
		claves->insert(pair<string, string>("luis", "mosca"));
		claves->insert(pair<string, string>("mario", "zubat"));
	}
	bool validaSeguridad(BallenaSecurityInterfaz* b) {
		map<string, string>::iterator it = claves->find(b->dameUsuario());
		if (it == claves->end()) {
			return false;	// No hemos encontrado el usuario
		}
		string clave = claves->find(b->dameUsuario())->second;
		return (b->dameClave().compare(clave) == 0);
	}
};
class PatataSecurityInterfaz {
public:
	virtual string dameCadena() = 0; // Debe contener "usuario"/"password"
};
class PatataUser : public PatataSecurityInterfaz {
private:
	string cadenaSegura;
public:
	PatataUser(string cadena) : cadenaSegura(cadena) {}
	string dameCadena() { return cadenaSegura; }
};
class PatataCompany {
public:
	list<string>* cadenas;
	PatataCompany() {
		cadenas = new list<string>();
		cadenas->push_back("pepe/1234");
		cadenas->push_back("luis/mosca");
		cadenas->push_back("mario/zubat");
	}
	bool validaSeguridad(PatataSecurityInterfaz* p) {
		for (string cad : *cadenas) {
			if (p->dameCadena().compare(cad) == 0) {
				return true;
			}
		}
		return false;
	}
};
class BallenaUserAdaptador : public BallenaUser, public PatataSecurityInterfaz  {
public:
	BallenaUserAdaptador(string u, string p) : BallenaUser(u, p) { }
	string dameCadena() {
		return user + "/" + pass;
	}
};
class PatataUserAdaptador : public BallenaSecurityInterfaz, public PatataUser {
public:
	PatataUserAdaptador(string c) : PatataUser(c) { }
	string dameUsuario() {
		int sepPos = dameCadena().find("/");
		return dameCadena().substr(0, sepPos);
	}
	string dameClave() {
		int sepPos = dameCadena().find("/");
		return dameCadena().substr(sepPos + 1, dameCadena().length() + sepPos);
	}
};

/* : PatataUser(u + "/" + p) {}
string dameUsuario() {
int sepPos = dameCadena().find("/");
return dameCadena().substr(0, sepPos);
}
string dameClave() {
int sepPos = dameCadena().find("/");
return dameCadena().substr(sepPos + 1, dameCadena().length() + sepPos);
} */
int main()
{
	BallenaCompany* bc = new BallenaCompany();
	PatataCompany* pc = new PatataCompany();

	BallenaUser* bu_ok = new BallenaUser("luis", "mosca");
	PatataUser* pu_ok = new PatataUser("luis/mosca");
	BallenaUser* bu_ko = new BallenaUser("luis", "moasdff");
	PatataUser* pu_ko = new PatataUser("luis/gfgfgf");

	cout << bc->validaSeguridad(bu_ok) << " - " << bc->validaSeguridad(bu_ko) << endl;
	cout << pc->validaSeguridad(pu_ok) << " - " << pc->validaSeguridad(pu_ko) << endl;

	BallenaUserAdaptador *buad_ok = new BallenaUserAdaptador("luis", "mosca");
	BallenaUserAdaptador *buad_ko = new BallenaUserAdaptador("luis", "jjjjj");

	cout << "buad_ok: loginBallena: " << bc->validaSeguridad(buad_ok) << endl;
	cout << "buad_ok: loginPatata: " << pc->validaSeguridad(buad_ok) << endl;
	cout << "buad_ko: loginBallena: " << bc->validaSeguridad(buad_ko) << endl;
	cout << "buad_ko: logindPatata: " << pc->validaSeguridad(buad_ko) << endl;

	PatataUserAdaptador *puad_ok = new PatataUserAdaptador("luis/mosca");
	PatataUserAdaptador *puad_ko = new PatataUserAdaptador("luis/jjjjj");

	cout << "puad_ok: loginBallena: " << bc->validaSeguridad(puad_ok) << endl;
	cout << "puad_ok: loginPatata: " << pc->validaSeguridad(puad_ok) << endl;
	cout << "puad_ko: loginBallena: " << bc->validaSeguridad(puad_ko) << endl;
	cout << "puad_ko: logindPatata: " << pc->validaSeguridad(puad_ko) << endl;

	system("pause");

	return 0;
}

