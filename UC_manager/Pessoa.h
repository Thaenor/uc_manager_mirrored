#ifndef UC_Manager_Pessoa_h
#define UC_Manager_Pessoa_h

using namespace std;
class Pessoa
{
private:
	string cod_utilizador;
    string nome;
	string email;
  //  Date data_de_nascimento;

public:
	Pessoa();
    Pessoa(string _cod, string _nome, string _email);
    ~Pessoa();
    Pessoa(const Pessoa& other);
    void escreve(ostream out) const;
  //  void escreve(); 



};

Pessoa::Pessoa(string _cod, string _nome, string _email){
	cod_utilizador = _cod;
	nome = _nome;
	email = _email;
}
#endif