#include "Cama.h";
Cama::Cama(string c) {
	this->tipo = c;
}

string Cama::GetTipoCama() {

	return this -> tipo;
}