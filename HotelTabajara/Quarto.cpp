#include "Quarto.h";
#include "Cliente.h";
#include "Cama.h";
#include <iostream>

using namespace std;



Quarto::Quarto(int id, bool state, string classi, vector<Cama> camasQuarto) {

	this->id = id;
	this->ocupado = state;
	this->classificacaoQuarto = classi;
	this->camasQuarto = camasQuarto;


}

vector<Cliente> Quarto::GetHospedes(){

	return this->hospedes;

}

void Quarto::SetNoitesOcupadas(int x) {
	this->periodoContratado = x;
}

void Quarto::SetEstadoReserva(bool x) {
	this->ocupado = x;
}

void Quarto::AdicionarHospede(Cliente c) {
	this->hospedes.push_back(c);

}
string Quarto::VerificarOcupacao() {
	string x;
	if (this->ocupado == true) {
		x =  "Reservado";
	}
	else {
		x =  "Livre";
	}


	return x;


}
int Quarto::GetQuartoID() {
	return this->id;
}

string Quarto::GetTipoCama() {


	return 	this->camasQuarto[0].GetTipoCama();


}

int Quarto::GetNoitesReservadas() {
	return this->periodoContratado;

}
int Quarto::GetQuantidadeCamas() {
	return this->camasQuarto.size();
}

string Quarto::GetQualificacao() {
	return this->classificacaoQuarto;
}

bool Quarto::GetEstadoReserva() {
	return this->ocupado;
}