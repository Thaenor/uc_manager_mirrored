#ifndef Utilizador_
#define Utilizador_

//#include <iostream>
#include <vector>
//#include "Mensagem.h"
#include "Pessoa.h"

using namespace std;

//#include "Pessoa.h"

class Utilizador : public Pessoa
{
	private:
	string  cod_utilizador;
	char tipo; //1-docente, 2-regente,,
	vector<Mensagem> msg;
	public:
	Utilizador();
	Utilizador(string nome,string cod_utilizador, char tipo, vector<Mensagem>msg);
	Utilizador(string nome, string sigla);
	~ Utilizador();
	Utilizador(const Utilizador &other);            /* Construtor Copia */
	virtual Utilizador* clone() ;						/* construtor Clone */

	void escreve(ostream out) const;

	string getCod_utilizador()const;
	void setCod_utilizador(string cod);
	
	char  getTipo()const;
	void setTipo(char tipo);

	vector<Mensagem> getMsg()const;
	void setMsg(vector<Mensagem> msg);

	virtual Utilizador& operator=(const Utilizador &u);
};

Utilizador& Utilizador::operator=(const Utilizador &u)
{
	cod_utilizador = u.getCod_utilizador();
	tipo = u.getTipo();
	msg = u.getMsg();
	return *this;
}
Utilizador::Utilizador()
{
	cod_utilizador = "";
	tipo = 1;
}

Utilizador::Utilizador(string nome, string _cod_utilizador, char _tipo, vector<Mensagem>_msg) : Pessoa( nome)
{
	cod_utilizador = _cod_utilizador;
	tipo = _tipo; 
	msg = _msg;
}

Utilizador::Utilizador(string n, string c): Pessoa(n)
{
	cod_utilizador = c;
}

Utilizador::~Utilizador()         /* Destrutor */
{
}

Utilizador* Utilizador::clone()
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