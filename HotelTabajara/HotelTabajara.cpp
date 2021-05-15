#include <vector>
#include <iostream>
#include "Funcionario.h";
#include "Quarto.h";
#include <windows.h>


vector<Quarto> quartos;

vector<Funcionario> funcionarios;

vector<Cliente> clientes;

void CriarCliente(int id,int reservas, string nome,bool hospedadado) {
    Cliente c(id,reservas, nome, hospedadado);
    clientes.push_back(c);

}

void CriarFuncionarios() {
    Funcionario f(funcionarios.size(), "Felipe");
    funcionarios.push_back(f);
    Funcionario v(funcionarios.size(), "Valeria");
    funcionarios.push_back(v);
    Funcionario r(funcionarios.size(), "Rogerio");
    funcionarios.push_back(r);


}


void CriarQuarto(int qntCama,string tipoCama, string tipoQuarto, bool estado) {
    vector<Cama> camasQuarto;
    for (int n = 0; n < qntCama; n++) {
        Cama cam(tipoCama);
        camasQuarto.push_back(cam);
    }

    Quarto quarto(quartos.size(), estado, tipoQuarto, camasQuarto);
    quartos.push_back(quarto);


}

void RelatorioGeral() {
    cout << "Relatorio\n";

    for (Cliente n : clientes) {

        if (n.GetEstadoHospedagem()) {
            cout << "Cliente " << n.GetNome() << ", ID:  " << n.GetId() << " hospedado no quarto ID:" << n.GetQuartoHospedadoId() << " por " << quartos[n.GetQuartoHospedadoId()].GetNoitesReservadas() << " noites," << "funcionario que hospedou: " << n.GetNomeHospedor() << " por " << n.GetNoitesHospedados() << " noite.\n" ;


        }
        else {
            cout << "Cliente " << n.GetNome() <<", ID:  "<<  n.GetId() <<", Aguardando na recepcao.\n";
        }


    }
}
void RelatorioRecepcao() {
    for (Cliente n : clientes) {

        if (!n.GetEstadoHospedagem()) {
            cout << "Cliente " << n.GetNome() << ", ID:  " << n.GetId() << ", Aguardando na recepcao.\n";


        }
    }
}
void RelatorioHospedes() {
    for (Cliente n : clientes) {

        if (n.GetEstadoHospedagem()) {
            cout << "Cliente " << n.GetNome() << ", ID:  " << n.GetId() << " hospedado no quarto ID:" << n.GetQuartoHospedadoId() << " por " << quartos[n.GetQuartoHospedadoId()].GetNoitesReservadas() << " noites," << "funcionario que hospedou: " << n.GetNomeHospedor() << " por " << n.GetNoitesHospedados() << " noite.\n";


        }
    }
}

int main()
{
   
    CriarCliente(clientes.size(), 0, "Joao", false);
    CriarCliente(clientes.size(), 0, "Ana", false);
    CriarCliente(clientes.size(),1, "Ricardo", false);


    CriarQuarto(2,"Solteiro", "Simples",false);
    CriarQuarto(1,"Casal", "Simples",false);
    CriarQuarto(1,"Casal", "Luxo",false);
    CriarQuarto(1,"Casal", "Simples", false);

    CriarFuncionarios();


  //  funcionarios[0].HospedarCliente(clientes[2], quartos[3], 3,true);
    quartos[3].SetEstadoReserva(true);
    quartos[3].SetNoitesOcupadas(3);
    clientes[2].SetEstadoHospedagem(true);
    clientes[2].SetQuartoHospedadoId(3);
    clientes[2].SetNoitesHospedadas(3);
    clientes[2].SetFuncionarioAjudanteNome(funcionarios[0].GetNome());
    quartos[3].AdicionarHospede(clientes[2]);
   // clientes[2].AdicionarReserva();

    int meuId = clientes.size();
    string meuNome;
    cout << "Digite seu nome: \n";
    cin >> meuNome;
    CriarCliente(meuId, 0, meuNome,false);


    cout << "Seja bem vindo ao Hotel Tabajara, '"<< meuNome << "'.\n";

    Sleep(100);



    for (Funcionario x : funcionarios)
        cout << "Funcionario: " << x.GetNome() << ", ID: " << x.GetId() << endl;

    int funcinarioAtivo = 0;

    cout << "Digite o ID do funcionario que deseja te auxiliar:\n";

    cin >> funcinarioAtivo;

    while (funcinarioAtivo > 2)
    {
        cout << "Funcionario invalido, selecione novamente: \n";

        cin >> funcinarioAtivo;
    }

   



    for (Funcionario x : funcionarios)
        if(x.GetId() == funcinarioAtivo)
           cout << "Voce escolheu funcionario: " << x.GetNome() << ", ID: " << x.GetId() << endl;


    Sleep(1000);

    system("cls");


    int escolha;

    cout << "Ola, me chamo " << funcionarios[funcinarioAtivo].GetNome() << " em que posso te ajudar?\n";

  

    while (true) {

        while (!clientes[meuId].GetEstadoHospedagem())
        {
            cout << "Digite 1 Para reservar quarto\n";


            cin >> escolha;


            if (escolha == 1) {

                int quartoEscolhido;
                cout << "Quartos do Hotel\n";

                for (Quarto x : quartos) {
                    cout << "Quarto ID: " << x.GetQuartoID() << ", Possui " << x.GetQuantidadeCamas() << " camas de " << x.GetTipoCama() << ", Quarto classificado como: " << x.GetQualificacao() << ". " << x.VerificarOcupacao() << "\n";
                }


                cout << "Digite o ID do quarto que deseja se hospedar:\n";

                cin >> quartoEscolhido;

                while (quartoEscolhido > 3)
                {

                    cout << "Quarto Invalido, por favor escolha outro. \n";

                    cin >> quartoEscolhido;
                }

                while (quartos[quartoEscolhido].GetEstadoReserva())
                {

                    cout << "Este quarto ja esta reservado, por favor escolha outro. \n";

                    cin >> quartoEscolhido;
                }



                int noitesContratadas = 0;

                cout << "Digite o numero de noites que deseja reservar: \n";

                cin >> noitesContratadas;


                while (noitesContratadas < 1) {

                    cout << "Quantidade de noites invalidas, digite novamente:\n";

                    cin >> noitesContratadas;

                }


               // funcionarios[funcinarioAtivo].HospedarCliente(clientes[meuId], quartos[quartoEscolhido], noitesContratadas, true);

                clientes[meuId].SetEstadoHospedagem(true);
                quartos[quartoEscolhido].SetEstadoReserva(true);
                quartos[quartoEscolhido].SetNoitesOcupadas(noitesContratadas);
                clientes[meuId].SetFuncionarioAjudanteNome(funcionarios[funcinarioAtivo].GetNome());
                clientes[meuId].SetQuartoHospedadoId(quartoEscolhido);
                quartos[quartoEscolhido].AdicionarHospede(clientes[meuId]);
                clientes[meuId].SetNoitesHospedadas(noitesContratadas);
              //  clientes[meuId].AdicionarReserva();

                cout << "Voce se hospedou por "<< noitesContratadas<<" noites.\n" ;


            }


            while (true) {
                cout << "Digite 2 Para gerar um relatorio geral das reservas\n";
                cout << "Digite 3 Para listar apenas os hospedes\n";
                cout << "Digite 4 Para listar apenas os clientes da recepcao\n";

                cin >> escolha;

                if (escolha == 2) {

                    RelatorioGeral();

                }

                if (escolha == 3) {

                    RelatorioHospedes();


                }

                if (escolha == 4) {

                    RelatorioRecepcao();


                }

            }


      

        }

        



    }
   




}

