#pragma once
#include <vector>
#include <string>
#include "Cliente.h";
#include "Cama.h";
using namespace std;

class Quarto {
private:

	int id;
	bool ocupado = false;
	string classificacaoQuarto;
	vector<Cliente> hospedes;	
	vector<Cama> camasQuarto;
	int periodoContratado;
	

public:
	Quarto(int id,bool state,string classific, vector<Cama> camasQuarto);

	int GetQuartoID();

	string VerificarOcupacao();
	string GetQualificacao();
	string GetTipoCama();
	int GetQuantidadeCamas();

	bool GetEstadoReserva();

	void SetEstadoReserva(bool x);
	void AdicionarHospede(Cliente c);
	void SetNoitesOcupadas(int x);
	int GetNoitesReservadas();


	vector<Cliente> GetHospedes();

};

