#pragma once

#include <iostream>

enum class colores {Azul, Verde};

class Color {
public:
	virtual void pinta() = 0;
};
class Azul : public Color {
	friend class ColorFactory;
public:
	virtual void pinta() {
		std::cout << "Soy Azul" << std::endl;
	}
private:
	Azul() {}
};
class Verde : public Color {
	friend class ColorFactory;
public:
	virtual void pinta() {
		std::cout << "Soy Verde" << std::endl;
	}
private:
	Verde() {}
};