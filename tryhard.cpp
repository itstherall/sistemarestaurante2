#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "funcionario.hpp"
#include "gerente.hpp"
#include "prat.hpp"
#include "garcom.hpp"

using namespace std;


class Prat{
private:
	string nome;
	string preco;
	string qnt;
public:
	
	Prat(string nome, string preco, string qnt)
	{
		this->nome = nome;
		this->preco = preco;
		this->qnt = qnt;
	}

	string Rnome() { return nome; };
	string Rpreco() { return preco; };
	string Rqnt() { return qnt; };
};


class Funcionario{
private:
	string nome;
	string cpf;
	
public:
	
	Funcionario(string nome, string cpf){
		this->nome = nome;
		this->cpf = cpf;
	}

	string Rnome() { return nome; };
	string Rcpf() { return cpf; };
};

class Garcom: public Funcionario{
private:
	string id;
	string salarioGar;

public:
	Garcom(string nome, string cpf, string id, string salGar) : Funcionario{nome,cpf} {
		this->id = id;
		this->salarioGar = salGar; 
	}

	string Rsalariogar(){ return salarioGar; };
	string Ridgar(){return id; };
};


class Gerente : public Funcionario{
private:
	string salarioGer;

public:
	string id;
	Gerente(string nome, string cpf, string id, string salGer) : Funcionario{nome,cpf} {
		this->id = id;
		this->salarioGer = salGer;
	}

	string Rsalarioger() { return salarioGer; };
	string Ridger() { return id; };

	void addPrato(vector<Prat> *Pratos){
		string nometmp = " ";
		string precotmp = " ";
		string qnttmp = " ";
		cout << "Qual nome do prato para registra?:\n";
		cin >> nometmp;

		cout << "Qual o preço do prato?\n";
		cin >> precotmp;

		qnttmp = "0";

		if(nometmp != " " && precotmp != " " && qnttmp != " ")
		{
			Prat tmp{nometmp, precotmp, qnttmp};
			Pratos->push_back(tmp);
		}
	}	

	void RemoverPrato(vector<Prat> *Pratos, int escolha)
	{
		Pratos->erase(Pratos->begin() + escolha);
	}

	void addGarcom(vector<Garcom> *Garcons){
		string nomeGartmp = " ";
		string cpfGartmp  = " ";
		string idGartmp = " ";
		cout << "Qual nome do Garcom para registra?:\n";
		cin >> nomeGartmp;

		cout << "Qual o cpf?\n";
		cin >> cpfGartmp;

		cout << "Qual ID o garcom vai receber?\n";
		cin >> idGartmp;

		if(nomeGartmp != " " && cpfGartmp != " " && idGartmp != " ")
		{
			Garcom tmp{nomeGartmp, cpfGartmp, idGartmp, "900"};
			Garcons->push_back(tmp);
		}
	}
};


class Hist{
private:
public:
	Hist(vector<Ped> pedi, ofstream histD)

};

class Pedido{
private:
public:


};

class Mesa{
private:
public:
	string num;

	Mesa(string num){
		this->num = num;
	}

	void FazerP(){
		//definir fazer pedido:
		//mostra quais os itens dispostos a venda;
	}
};



class Res{
public:
	string NomeR;

	Res(string NomeR){
		this->NomeR = NomeR;
	}

	//return nome:
	string Rnome() { return NomeR; };

	//aqui comeca a inicialização dos pratos:
	void InPrat(vector<Prat> *vetorPrat){
		//auxiliar para abrir arquivo de pratos:
		ifstream pratos;

		//retirando info do arq:
		pratos.open("pratos.txt");
		if(!pratos.is_open())
		{
			cout << "ERRO AO ABRIR ARQUIVO!!!\n";
		}

		vector<string> stractor;
		string aux;
		while(pratos.good()){
			getline(pratos, aux , ',');
			stractor.push_back(aux);
		}

		//strings tbm auxiliares para inicializar os pedidos:	
		string nomePrat, precoPrat, qntPrat;

		nomePrat = " ";
		precoPrat = " ";
		qntPrat = " ";
		for(int i = 0; i < stractor.size(); ++i)
		{
			if(i%3 == 0 && i > 0){
				nomePrat = " ";
				precoPrat = " ";
				qntPrat = " ";
			}

			if(i%3 == 0)
			{
				nomePrat = stractor[i]; 
			}
			else if(i%3 == 1)
			{
				precoPrat = stractor[i];
			}
			else if(i%3 == 2)
			{
				qntPrat = stractor[i];
			}

			if(nomePrat != " " && precoPrat != " " && qntPrat != " ")
			{	
				//Inicializa todos os objetos de Prat de acordo com a lista de pratos:	
		    	Prat tmp{nomePrat, precoPrat, qntPrat};
		 		
		 		//adiciona os pratos ao vector para se tornar acessivel os obj,
		 		//vector dos OBJ esta incializado no main por conta do destructor
		    	vetorPrat->push_back(tmp) ;
			}
		}

		pratos.close();		
	}

	void InGer(vector<Gerente> *vetorGerentes){
		//tipo ifstream para abrir arquivo de Gerente:
		ifstream gerente;
		//string e vector de string p/ auxiliar para ajudar na extração dos componenetes do arquivo:
		string aux;
		vector<string> stractor;

		//abrindo e testando a abertura de arquivo do obj Gerente:
		gerente.open("gerente.txt");
		if(!gerente.is_open())
		{
			cout << "ERRO NA ABERTURA DO ARQUIVO DE GERENTES!!!\n";
			exit(1);
		}

		while(gerente.good()){
			getline(gerente, aux , ',');
			stractor.push_back(aux);
		}

		//variaveis auxiliares para separação e inicialização dos gerentes;
		string nomeGer = " ";
		string cpfGer = " ";
		string idGer = " ";
		string salarioGer = "1.200";
		//inicializar gerente aqui

		for(int i = 0; i < stractor.size() ; ++i)
		{
			if(i%3 == 0 && i > 0)
			{
				nomeGer = " ";
				cpfGer = " ";
				idGer = " ";			
			}

			if(i%3 == 0)
			{
				nomeGer = stractor[i];
			}
			else if(i%3 == 1)
			{
				cpfGer = stractor[i];
			}
			else if(i%3 == 2)
			{
				idGer = stractor[i];
			}

			if(nomeGer != " " && cpfGer != " " &&  idGer != " " && salarioGer != " ")
			{
				Gerente tmp{nomeGer, cpfGer, idGer, salarioGer};
				vetorGerentes->push_back(tmp);
			}
		}
	}

	void InGar(vector<Garcom> *vetorGarcons){
			//tipo ifstream para abrir arquivo de Gerente:
		ifstream garcom;
		//string e vector de string p/ auxiliar para ajudar na extração dos componenetes do arquivo:
		string aux;
		vector<string> stractor;

		//abrindo e testando a abertura de arquivo do obj Gerente:
		garcom.open("garcom.txt");
		if(!garcom.is_open())
		{
			cout << "ERRO NA ABERTURA DO ARQUIVO DE GERENTES!!!\n";
			exit(1);
		}

		while(garcom.good()){
			getline(garcom, aux , ',');
			stractor.push_back(aux);
		}

		//variaveis auxiliares para separação e inicialização dos gerentes;
		string nomeGar = " ";
		string cpfGar = " ";
		string idGar = " ";
		string salarioGar = "900";
		//inicializar gerente aqui

		for(int i = 0; i < stractor.size() ; ++i)
		{
			if(i%3 == 0 && i > 0)
			{
				nomeGar = " ";
				cpfGar = " ";
				idGar = " ";			
			}

			if(i%3 == 0)
			{
				nomeGar = stractor[i];
			}
			else if(i%3 == 1)
			{
				cpfGar = stractor[i];
			}
			else if(i%3 == 2)
			{
				idGar = stractor[i];
			}

			if(nomeGar != " " && cpfGar != " " &&  idGar != " " && salarioGar != " ")
			{
				Garcom tmp{nomeGar, cpfGar, idGar, salarioGar};
				vetorGarcons->push_back(tmp);
			}
		}
	}

/*
	void salvaralt(vector<Ger> &Gerentes, vector<Gar> &Garcons, vector<Prat> &Pratos)
	{

		ofstream pratoss;
		ofstream gerentess;
		ofstream garconss;

		//testando a abertura dos arquivos:
		pratoss.open("pratos.txt");
		if(!pratoss.is_open())
		{
			cout << "ERRO NA ABERTURA DE DOS PRATOS PARA SALVAR\n";
		}

		gerentess.open("pratos.txt");
		if(!gerentess.is_open())
		{
			cout << "ERRO NA ABERTURA DE DOS GERENTES PARA SALVAR\n";
		}

		garconss.open("pratos.txt");
		if(!garconss.is_open())
		{
			cout << "ERRO NA ABERTURA DE DOS GARCONS PARA SALVAR\n";
		}
	}
	*/
};


int main(){
	//containers necessário para inicializar as informações do restaurante:
	vector<Prat> Pratos;
	vector<Gerente> Gerentes;
	vector<Garcom> Garcons;

	//Inicializando um restaurante:
	Res a{"ComeuMorreu"};
	cout << "# # # # SEJA BEM VINDO AO RESTAURANTE " << a.Rnome() << " # # # #\n";
	
	//incializando o sistema com seus componentes:
	a.InPrat(&Pratos);
	a.InGer(&Gerentes);
	a.InGar(&Garcons);
	//funcionando até aqui!!!!


	cout << Garcons[2].Ridgar() << endl;

	//variaveis para iniciar as opções dependendo do seu cargo dentro do restaurante:
	string ID_Funcionario;

	cout << "Por favor informe o id: \n";
	cin >> ID_Funcionario;

	//funcionando ooooooooooooooooooooooo:
	//achar o funcionario:

	//var auxiliar:
	int gerr = 0;
	int garr = 0;
	int decGerente = 0;
	int decGarcom = 0;

	for(gerr; gerr < Gerentes.size(); ++gerr)
	{
		if(Gerentes[gerr].Ridger() == ID_Funcionario)
		{
			decGerente = 1;	
			break;
		}
	}

	/*for(garr ; garr < Garcons.size(); ++garr)
	{
		if(Garcons[garr].Ridgar() == ID_Funcionario)
		{
			decGarcom = 1;
			break;
		}
	}
*/

	//int para decisão do que fazer se Gerente:
	int Dec = 0;
	if(decGerente == 1){
		cout << "Para: \n1 - adicionar prato;\n2 - remover prato;\n3 - adicionar garcom;\n4 - remover garcom;\n";
		cout << "5 - mostrar hitorico diario;\n6 - salvar alterações\n7 - Sair;\n";
		cin >> Dec;
		
		while(Dec != 7)
		{
			if(Dec == 0)
			{
				cout << "Deseja fazer algo mais?: \n";
				cout << "1 - adicionar prato;\n2 - remover prato;\n3 - adicionar garcom;\n4 - remover garcom;\n";
				cout << "5 - mostrar hitorico diario;\n6 - salvar alterações;\n7 - Sair;\n";
				cin >> Dec;
			}
			if(Dec == 1)
			{
				//add função para adicionar prato;
				//para pratos precisamos de nome, preco e qnt:
				Gerentes[garr].addPrato(&Pratos);
				Dec = 0;
			}
			else if (Dec == 2)
			{
				//add função para remover um prato;
				//mostrandos os pratos disponiveis 
				for(int i = 0; i < Pratos.size(); ++i)
				{
					cout << i << " - " << Pratos[i].Rnome() << endl;
				}
				
				int escolha;
				cout << "Qual pratos deseja excluir?\n";
				cin >> escolha;

				Gerentes[garr].RemoverPrato(&Pratos, escolha);
				
				//Para interatividade no Menu o Dec recebe valor 0; 
				Dec = 0;
			}
			else if (Dec == 3)
			{
				//add função para adicionar garcom;
				Gerentes[garr].addGarcom(&Garcons);
				Dec = 0;
			}
			else if(Dec == 4)
			{
				//add função para remover garcom;
			}
			else if(Dec == 5)
			{
				//add mostrar historico;
			}
			else if(Dec == 6)
			{

			}
			else if(Dec == 7)
			{

			}
		}
	}
}

