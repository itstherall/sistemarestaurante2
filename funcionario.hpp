#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
///Declaracao da classe funcionario
class Funcionario{
private:
	///Atributos da classe funcionario
	string nome;
	string cpf;

public:
	///Metodos da classe funcionario
	Funcionario(string nome, string cpf);
	string Rnome();
	string Rcpf();
};
