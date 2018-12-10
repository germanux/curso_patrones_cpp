#include "stdafx.h"
#include "BebidasStarDucks.h"

Bebida* StarducksFactory::dameBebida(tipoBebida tipo, std::list<complementos> complementos) {
	Bebida *bebida = NULL;

	if (tipo == tipoBebida::Cafe) { bebida = new Cafe(); }
	for (auto comp : complementos) {
		// Complemento comp = complementos[i]
		if (comp == complementos::Azucar) {
			bebida->ponAzucar();
		}
	}
	return bebida;
}