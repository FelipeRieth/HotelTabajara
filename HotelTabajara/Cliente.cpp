#include "Cliente.h";


Cliente::Cliente(int id,int reser,string nome,bool hospedado) {
	this->hospedado = hospedado;
	this->id = id;
	this->quantidadeReservas = reser;
	this->nome = nome;
}

void Cliente::SetQuartoHospedadoId(int id) {
	this->idQuartoHospedado = id;

}
int Cliente::GetId() {
	return this->id;

}
int Cliente::GetQuartoHospedadoId() {
	return this->idQuartoHospedado;
}

void Cliente::AdicionarReserva() {
	this->quantidadeReservas++;
}

int Cliente::GetQuantidadeReservas() {
	return this->quantidadeReservas;
}
void Cliente::SetEstadoHospedagem(bool x) {
	this->hospedado = x;

}
bool Cliente::GetEstadoHospedagem() {
	return this->hospedado;
}

void Cliente::SetFuncionarioAjudanteNome(string x) {
	this->nomeFuncionario = x;
}
string Cliente::GetNome() {
	return this->nome;
}

string Cliente::GetNomeHospedor() {
	return this->nomeFuncionario;
} 

int Cliente::GetNoitesHospedados() {
	return this->diasHospedados;
}

void Cliente::SetNoitesHospedadas(int x) {
	this->diasHospedados = x;
}