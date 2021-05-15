#include "Funcionario.h";
Funcionario::Funcionario(int id, string nome) {
	this->id = id;
	this->nome = nome;


}
bool Funcionario::VerificarOcupacao(Quarto c) {
	return c.GetEstadoReserva();
}

void Funcionario::HospedarCliente(Cliente c, Quarto q,int noites,bool estadoReserva) {
	q.SetEstadoReserva(estadoReserva);
	q.AdicionarHospede(c);

}



int Funcionario::GetId() {
	return this->id;
}
string Funcionario::GetNome() {
	return this->nome;
}