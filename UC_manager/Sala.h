#ifdef UC_Sala_H
#define UC_Sala_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

#include "Pessoa.h"

class Sala
{
private:
	int cod_sala;
	int cod_evento;
	vector<Pessoa> presentes;
	int capacidade;

public:
	Sala();
	Sala(int cod_sala, int cod_evento, vector<Pessoa> presentes, int capacidade);
	~Sala();
	Sala(const Sala &other);
	Sala* clone() const;

	int getCod_sala();
	int getCod_evento();
	vector<Pessoa> getPresentes();
	int getCapacidade();

	void setCod_sala(int cod_sala);
	void setCod_evento(int cod_evento);
	void setPresentes(vector<Pessoa> presentes);
	void setCapacidade(int capacidade);

	void escreve(ostream out) const;
	void listar();
};

Sala::Sala()
{
	cod_sala = 0;
	cod_evento = 0;
	capacidade = 0;
}

Sala::Sala(int cod_sala, int cod_evento, vector<Pessoa> presentes, int capacidade)
{
	this->cod_sala = cod_sala;
	this->cod_evento = cod_evento;
	this->presentes = presentes;
	this->capacidade = capacidade;
}

Sala::~Sala(){}

Sala::Sala(const Sala &other)
{
	this->cod_sala = other.cod_sala;
	this->cod_evento = other.cod_evento;
	this->presentes = other.presentes;
	this->capacidade = other.capacidade;
}

Sala* Sala::clone() const
{
	return new Sala(*this);
}

int Sala::getCod_sala()					{ return cod_sala; }
int Sala::getCod_evento()				{ return cod_evento; }
vector<Pessoa> Sala::getPresentes()		{ return presentes; }
int Sala::getCapacidade()				{ return capacidade; }

void Sala::setCod_sala(int cod_sala)				{ this->cod_sala = other.cod_sala; }
void Sala::setCod_evento(int cod_evento)			{ this->cod_evento = other.cod_evento; }
void Sala::setPresentes(vector<Pessoa> presentes)	{ this->presentes = other.presentes; }
void Sala::setCapacidade(int capacidade)			{ this->capacidade = other.capacidade; }

void Sala::escreve(ostream out) const
{
	out << "Sala codigo: " << getCod_sala() << " com capacidade: " << getCapacidade() << endl;
}

void Sala::listar()
{
	cout << "Sala codigo: " << getCod_sala() << " com capacidade: " << getCapacidade() << endl;
}

#endif