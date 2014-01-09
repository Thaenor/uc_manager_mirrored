#ifndef UC_Manager_Aluno_h
#define UC_Manager_Aluno_h

using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include "Pessoa.h"
//#include"Gestao.h"


class Aluno : public Pessoa
{
private:
	int numero;
	vector<float> notas;

public:
	Aluno();
	Aluno(string nome, int numero,vector <float> notas);
	Aluno(int numero, vector <float> notas);
	~Aluno();
    Aluno(const Aluno& other);
    void escreve(ostream &out) const;

	virtual Aluno* clone()const;

	void setNumero(int numero);
	void setNotas(vector<float> notas);

	int getNumero()const;
	vector<float> getNotas()const;

	virtual Aluno& operator=(const Aluno &a);
	virtual bool operator==(const Aluno &a)const;
	virtual bool operator>(const Aluno &a)const;
	void escrever(ostream &a)const;
	const Aluno& operator+=(const Aluno &a);
};


Aluno :: Aluno() 
{
	numero =0;
}

Aluno::Aluno(string nome, int num,vector <float>_notas) :Pessoa(nome)
{
	numero = num;
	notas = _notas;
}

Aluno::Aluno(int _numero, vector <float> _notas)
{
	numero = _numero;
	notas = _notas;
}

Aluno* Aluno::clone()const{
	return new Aluno(*this);
}

Aluno:: ~Aluno(){}

Aluno:: Aluno(const Aluno& a)
{
	this->numero = a.numero;
	this->notas = a.notas;
}

void Aluno::setNumero(int num){
	numero = num;
}
void Aluno::setNotas(vector <float>not){
	notas = not;
}

int Aluno::getNumero()const{
	return numero;
}
vector<float> Aluno::getNotas()const{
	return notas;
}
Aluno& Aluno:: operator=(const Aluno &a){

	if (this != &a){
		numero = a.numero;
		notas = a.notas;
	}
	return *this;
}

bool Aluno:: operator==(const Aluno &a)const{

	if (numero == a.numero && notas == a.notas)
		return true;
	return false;
}
bool Aluno:: operator>(const Aluno &a)const{

	if (numero> a.numero && notas > a.notas)
		return true;
	return false;
}


ostream &operator<<(ostream & out, const Aluno &a){
	a.escrever(out);
	return out;
}

void Aluno::escrever(ostream &o)const{
	o << "Numero: " << getNumero() << endl;
	//o << "Notas: " << vector(notas) << endl;
}
#endif