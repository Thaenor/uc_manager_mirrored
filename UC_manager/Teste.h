#ifndef Teste_
#define Teste_

#include <string>
#include <iostream>
#include <vector>

using namespace std;

#include "Eventos.h"
#include "Utilizador.h"

class Teste : public Eventos
{
private:
	int cod_teste;
	vector <string> lista_salas;
	string cod_user;
	int n_docentes_sala;
	vector <Utilizador> lista_user;

public:
	Teste();
	Teste(const int cod_eventos, const string data, const int hora, int cod_teste, vector<string> lista_salas, string cod_user, int n_docentes_sala, vector <Utilizador> lista_user);
	~Teste();
	Teste(const Teste &other);
	Teste* clone() const;

	int getCod_teste()const;
	vector <string> getlista_salas()const;
	string getCod_user()const;
	int getN_docentes_sala()const;
	vector <Utilizador> getLista_user()const;

	void setCod_teste(int cod_teste);
	void setLista_salas(vector<string> lista_salas);
	void setCod_user(int cod_user);
	void setN_docentes_sala(int n_docentes_sala);
	void lista_user(vector <Utilizador> lista_user);

	void escreve(ostream out) const;
	void listar();
};


Teste::Teste()
{
	cod_teste = 0;
	cod_user = "";
	n_docentes_sala = 0;
}

Teste::Teste(const int cod_eventos, const string data, const int hora, int cod_teste, vector<string> lista_salas, string cod_user, int n_docentes_sala, vector <Utilizador> lista_user) : Eventos(/*cod_eventos,  data, hora*/)
{
	this->cod_teste = cod_teste;
	this->lista_salas = lista_salas;
	this->cod_user = cod_user;
	this->n_docentes_sala = n_docentes_sala;
	this->lista_user = lista_user;
}


Teste::~Teste(){}

Teste::Teste(const Teste &other)
{
	cod_teste = other.cod_teste;
	lista_salas = other.lista_salas;
	cod_user = other.cod_user;
	n_docentes_sala = other.n_docentes_sala;
	this->lista_user = other.lista_user;
}

Teste* Teste::clone() const
{
	return new Teste(*this);
}


int Teste::getCod_teste()			const		{ return cod_teste; }
vector <string> Teste::getlista_salas()	const	{ return lista_salas; }
string Teste::getCod_user()	const				{ return cod_user; }
int Teste::getN_docentes_sala()	const			{ return n_docentes_sala; }
vector<Utilizador> Teste::getLista_user()const		{ return this->lista_user; }

void Teste::setCod_teste(int cod_teste)						{ this->cod_teste = cod_teste; }
void Teste::setLista_salas(vector<string> lista_salas)		{ this->lista_salas = lista_salas; }
void Teste::setCod_user(int cod_user)						{ this->cod_user = cod_user; }
void Teste::setN_docentes_sala(int n_docentes_sala)			{ this->n_docentes_sala = n_docentes_sala; }
void Teste::lista_user(vector <Utilizador> lista_user)		{ this->lista_user = lista_user; }


void Teste::escreve(ostream out) const
{
	out << "Teste: \ncodigo: " << getCod_teste() << " marcado por: " << getCod_user() << ", " << getN_docentes_sala << " docentes vigiarao a prova" << endl;
}

void Teste::listar()
{
	cout << "Teste: codigo: " << getCod_teste() << " marcado por: " << getCod_user() << ", " << getN_docentes_sala << " docentes vigiarao a prova" << endl;
}

#endif