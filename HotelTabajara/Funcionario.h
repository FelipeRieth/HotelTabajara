#pragma once
#include <vector>
#include <string>
#include "Quarto.h";
using namespace std;


class Funcionario {
private:
	int id;
	string nome;




public:
	Funcionario(int id, string nom);
	bool VerificarOcupacao(Quarto q);
	void HospedarCliente(Cliente c, Quarto q,int noites,bool estado);
	int GetId();
	string GetNome();


};