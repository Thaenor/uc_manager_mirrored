#ifndef Utilizador_
#define Utilizador_

#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "Pessoa.h"
#include"Mensagem.h"

class Utilizador : public Pessoa
{
	private:
	string  cod_utilizador;
	char tipo; //1-docente, 2-regente
	vector<Mensagem> msg;

	public:
	Utilizador();
	Utilizador(string nome,string cod_utilizador, char tipo, vector<Mensagem>msg);
	~ Utilizador();
	Utilizador(const Utilizador &other);            /* Construtor Copia */
	Utilizador* clone() const;						/* construtor Clone */

	void escreve(ostream out) const;

	string getCod_utilizador()const;
	void setCod_utilizador(string cod);
	
	char  getTipo()const;
	void setTipo(char tipo);

	vector<Mensagem> getMsg()const;
	void setMsg(vector<Mensagem> msg);
};

Utilizador::Utilizador()
{
	cod_utilizador = "";
	tipo = 1;
}

Utilizador::Utilizador(string nome, string cod_utilizador, char tipo, vector<Mensagem>msg) : Pessoa( nome)
{
	cod_utilizador = cod_utilizador;
	tipo = tipo; 
	msg = msg;

}

Utilizador::~Utilizador()         /* Destrutor */
{
}

Utilizador* Utilizador::clone()const
{
	return new Utilizador(*this);
}


Utilizador::Utilizador(const Utilizador &other){    /* Construtor Copia */
	cod_utilizador = other.cod_utilizador; 
	tipo = other.tipo;  
	msg = other.msg;
}

	string Utilizador::getCod_utilizador()	const			{return this->cod_utilizador;}
	char Utilizador::getTipo()const							{return this->tipo;}
	vector<Mensagem> Utilizador::getMsg()const				{return this->msg;}	

	void Utilizador::setCod_utilizador(string cod)			{cod_utilizador = cod_utilizador;}
	void Utilizador::setTipo(char type)						{tipo = type;}
	void Utilizador::setMsg(vector<Mensagem> msg)				{msg = msg;}

	void Utilizador::escreve(ostream out) const
	{
		 out <<"Codigo do utilizador: = "<<getCod_utilizador()<<" tipo: "<<getTipo()<<endl;
	}

	/*void Utilizador::listar()
	{
		cout <<"Utilizador ID = "<<getCod_utilizador()<<" tipo: "<<getTipo()<<" grau "<<getGrau()<<endl;
	}*/
#endif