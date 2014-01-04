#ifndef UC_Manager_Aluno_h
#define UC_Manager_Aluno_h

using namespace std;

class Aluno
{
	private:
	int numero;
    string nome;
	//string email;
	//  Date data_de_nascimento;

public:
	Aluno();
	Aluno(int numero, string nome);
	~Aluno();
    Aluno(const Aluno& other);
    void escreve(ostream &out) const;
  //  void escreve(); 
};

Aluno :: Aluno() 
{
	numero =0;
	nome = " ";
}

Aluno :: Aluno(int num,string name)
{
	numero = num;
	nome = name;
}

Aluno:: ~Aluno(){}

Aluno:: Aluno(const Aluno& other)
{
	this->nome = other.nome;
	this->numero = other.numero;
	
}

void Aluno :: escreve(ostream &out) const
{
	out << nome  << "\n" << numero << endl;
}

ostream &operator << (ostream &out, const Aluno &a)
{
	a.escreve(out);
	return out;
}
#endif
