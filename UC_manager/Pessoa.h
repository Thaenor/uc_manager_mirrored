#ifndef UC_Manager_Pessoa_h
#define UC_Manager_Pessoa_h

using namespace std;
class Pessoa
{
private:
    string nome;

public:
	Pessoa();
    Pessoa(string _nome);
    ~Pessoa();
    Pessoa(const Pessoa& other);

	virtual Pessoa* clone()const;

	void setNome(string nome);

	string getNome()const;

	virtual void listar()const;
	virtual Pessoa& operator=(const Pessoa &p);
	virtual bool operator==(const Pessoa &p)const;
	virtual bool operator>(const Pessoa &p)const;
	const Pessoa& operator+=(const Pessoa &p);
	void escrever(ostream &p)const;
};

Pessoa::Pessoa(){
	this->nome = "";
}

Pessoa::Pessoa(string n){
	nome = n;

}

Pessoa::Pessoa(const Pessoa &p){
	nome = p.getNome();
}

Pessoa:: ~Pessoa(){
}

Pessoa* Pessoa::clone()const{
	return new Pessoa(*this);
}

void Pessoa::setNome(string n){
	nome = n;
}

string Pessoa::getNome()const{
	return nome;
}


Pessoa& Pessoa:: operator=(const Pessoa &p){

	if (this != &p){
		nome = p.getNome();
	}
	return *this;
}

bool Pessoa:: operator==(const Pessoa &p)const{

	if (nome == p.nome)
		return true;
	return false;
}
bool Pessoa:: operator>(const Pessoa &p)const{

	if (nome > p.nome)
		return true;
	return false;
}


ostream &operator<<(ostream & out, const Pessoa &p){
	p.escrever(out);
	return out;
}



void Pessoa::escrever(ostream &o)const{
	o << "Nome: " << getNome() << endl;
}

Pessoa& Pessoa:: operator=(const Pessoa&c){

	if (this != &c){
		nome = c.getNome();
	}
	return *this;
}

#endif