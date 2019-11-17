#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "funcionario.hpp"

using namespace std;

Funcionario::Funcionario(string nome, string cpf){
		this->nome = nome;
		this->cpf = cpf;
	}

string Funcionario::Rnome() { return nome; }

string Funcionario::Rcpf() { return cpf; }