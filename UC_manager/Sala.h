#ifndef UC_Sala_H
#define UC_Sala_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

#include "Pessoa.h"

class Sala
{
private:
	string cod_sala;
	std::string getCod_sala() const { return cod_sala; }
	void setCod_sala(std::string val) { cod_sala = val; }
	int capacidade;
	int getCapacidade() const { return capacidade; }
	void setCapacidade(int val) { capacidade = val; }


public:
	Sala();
	Sala(int c, int cap);
	~Sala();
	Sala(const Sala &other);
	Sala* clone() const;
	
	string getCod_sala()const;
	int getCapacidade()const;

	void setCod_sala(string cod_sala);
	void setCapacidade(int capacidade);

	Sala& operator=(const Sala &c);
	bool operator==(const Sala &c)const;

	void escreve(ostream out) const;
	void listar();
};

Sala::Sala()
{
}

Sala::Sala(int c, int cap)
{
	this->cod_sala = c;
	this->capacidade = cap;
}

Sala::~Sala(){}

Sala::Sala(const Sala &other)
{
	this->cod_sala = other.cod_sala;
	this->capacidade = other.capacidade;
}

Sala* Sala::clone() const
{
	return new Sala(*this);
}


void Sala::escreve(ostream out) const
{
	out << "Sala codigo: " << getCod_sala() << " com capacidade: " << getCapacidade() << endl;
}

void Sala::listar()
{
	cout << "Sala codigo: " << getCod_sala() << " com capacidade: " << getCapacidade() << endl;
}


Sala& Sala:: operator=(const Sala&c){

	if (this != &c){
		cod_sala= c.getCod_sala();
		capacidade = c.getCapacidade();
	}
	return *this;
}

bool Sala:: operator==(const Sala &c)const{

	if (cod_sala == c.getCod_sala())
		return true;
	return false;
}
#endif