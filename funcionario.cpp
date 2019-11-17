#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "funcionario.hpp"

using namespace std;

///Construtores da classe funcionarios
Funcionario::Funcionario(string nome, string cpf){
		this->nome = nome;
		this->cpf = cpf;
	}
///Metodo returnNome
string Funcionario::Rnome() { return nome; }

///Metodo returnCpf
string Funcionario::Rcpf() { return cpf; }