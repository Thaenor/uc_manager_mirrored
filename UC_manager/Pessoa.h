#ifndef UC_Manager_Pessoa_h
#define UC_Manager_Pessoa_h

#include "Mensagem.h"
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

	virtual Pessoa* clone();

	void setNome(string nome);

	//heranca
	virtual string getNome()const;
	virtual string getCod_utilizador()const;
	virtual int getNumero()const;
	virtual char  getTipo()const;
	virtual vector<Mensagem> getMsg()const;
	virtual void setNumero(int num);

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

Pessoa* Pessoa::clone(){
	return new Pessoa(*this);
}

void Pessoa::setNome(string n){
	nome = n;
}

string Pessoa::getNome()const{
	return nome;
}

void Pessoa ::  setNumero(int num)
{
}





string Pessoa::getCod_utilizador()const
{	
	return "";
}
int Pessoa::getNumero()const
{
	return 0;
}

char Pessoa:: getTipo()const
{
	return 'P';
}

vector<Mensagem> Pessoa:: getMsg()const
{
	vector<Mensagem> m;
	return m;
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

Pessoa& Pessoa:: operator=(const Pessoa &c){

	if (this != &c){
		nome = c.getNome();
	}
	return *this;
}

#endif