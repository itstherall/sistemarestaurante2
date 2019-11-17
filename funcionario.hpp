#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Funcionario{
private:
	string nome;
	string cpf;

public:
	
	Funcionario(string nome, string cpf);
	string Rnome();
	string Rcpf();
};
