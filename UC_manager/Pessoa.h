#ifndef UC_Manager_Pessoa_h
#define UC_Manager_Pessoa_h

class Pessoa
{
private:
	int cod_utilizador;
    string nome;
	string email;
  //  Date data_de_nascimento;

public:
	Pessoa();
    Pessoa(int cod_utilizador, string nome, string email);
    ~Pessoa();
    Pessoa(const Pessoa& other);
    void escreve(ostream out) const;
  //  void escreve(); 



}
#endif