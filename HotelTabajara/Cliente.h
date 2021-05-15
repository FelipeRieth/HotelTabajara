#pragma once
#include <vector>
#include <string>

using namespace std;

class Cliente {
private:
	int id;
	bool hospedado;
	int idQuartoHospedado = 0;
	int quantidadeReservas = 0;
	string nome;
	string nomeFuncionario;
	int diasHospedados = 0;


public:

	Cliente(int id,int reservas,string nome,bool hospedado);

	void AdicionarReserva();
	void SetQuartoHospedadoId(int id);
	int GetQuartoHospedadoId();
	int GetQuantidadeReservas();
	void SetEstadoHospedagem(bool x);
	bool GetEstadoHospedagem();
	void SetFuncionarioAjudanteNome(string x);
	string GetNome();
	string GetNomeHospedor();
	int GetId();
	int GetNoitesHospedados();
	void SetNoitesHospedadas(int x);

};