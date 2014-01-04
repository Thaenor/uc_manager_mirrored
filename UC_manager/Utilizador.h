#ifndef Utilizador_
#define Utilizador_

#include <string>
#include <iostream>
#include <vector>

//using namespace std;

#include "Pessoa.h"
#include "UC.h"
#include "Aluno.h"

class Utilizador : public Pessoa
{
	private:
	string  cod_user;
	vector<UC> unidades_curriculares;
	char tipo; //1-docente, 2-regente
	string grau;
	string password;
	vector<Aluno> lista_alunos;
	vector<UC> UCs_visiveis;

	public:
	Utilizador();
	Utilizador(string cod_utilizador, string nome, string email, vector<UC> unidades, char type, int grau, string pw, vector<Aluno> alunos, vector<UC> visiveis);
	~ Utilizador();
	Utilizador(const Utilizador &other);            /* Construtor Copia */
	Utilizador* clone() const;						/* construtor Clone */

	void escreve(ostream out) const;
	void listar();

	string getCod_utilizador()const;
	void setCod_utilizador(string cod);

	vector<UC> getUnidades_curriculares()const;
	void setUnidades_curriculares(vector<UC> unidades);
	
	char  getTipo()const;
	void setTipo(char type);

	string getGrau()const;
	void setGrau(int grau);

	string getPassword()const;
	void setPassword(string pw);

	vector<Aluno> getLista_alunos()const;
	void setLista_alunos(vector<Aluno> alunos);

	vector<UC> getUCs_visiveis()const;
	void setUCs_visiveis(vector<UC> visiveis);
};

Utilizador::Utilizador()
{
	//ATRIBUIR ID	cod_utilizador = 0;
	tipo = 1;
	grau = "";
	password ="";
}

Utilizador::Utilizador(string cod_utilizador, string nome, string email, vector<UC> unidades, char type, int grau, string pw, vector<Aluno> alunos, vector<UC> visiveis) : Pessoa(cod_utilizador, nome, email)
{
	unidades_curriculares = unidades;
	tipo = type; 
	this->grau=grau; 
	password = pw; 
	lista_alunos = alunos; 
	UCs_visiveis = visiveis;
}

Utilizador::~Utilizador()         /* Destrutor */
{
}

Utilizador* Utilizador::clone()const
{
	return new Utilizador(*this);
}


Utilizador::Utilizador(const Utilizador &other){    /* Construtor Copia */
	cod_user = other.cod_user; 
	unidades_curriculares = other.unidades_curriculares;
	tipo = other.tipo; 
	grau = other.grau; 
	password = other.password; 
	lista_alunos = other.lista_alunos; 
	UCs_visiveis = other.UCs_visiveis;
}

	string Utilizador::getCod_utilizador()	const			{return this->cod_user;}
	vector<UC> Utilizador::getUnidades_curriculares()const	{return this->unidades_curriculares;}
	char Utilizador::getTipo()const							{return this->tipo;}
	string Utilizador::getGrau()const						{return this->grau;}
	string Utilizador::getPassword()const					{return this->password;}
	vector<Aluno> Utilizador::getLista_alunos()const			{return this->lista_alunos;}
	vector<UC> Utilizador::getUCs_visiveis()const			{return this->UCs_visiveis;}
	

	void Utilizador::setCod_utilizador(string cod)							{cod_user = cod;}
	void Utilizador::setUnidades_curriculares(vector<UC> unidades)		{unidades_curriculares = unidades;}
	void Utilizador::setTipo(char type)									{tipo = type;}
	void Utilizador::setGrau(int grau)									{grau = grau;}
	void Utilizador::setPassword(string pw)								{password = pw;}
	void Utilizador::setLista_alunos(vector<Aluno> alunos)				{lista_alunos = alunos;}
	void Utilizador::setUCs_visiveis(vector<UC> visiveis)				{UCs_visiveis = visiveis;}

	void Utilizador::escreve(ostream out) const
	{
		 out <<"Utilizador ID = "<<getCod_utilizador()<<" tipo: "<<getTipo()<<" grau "<<getGrau()<<endl;
	}

	void Utilizador::listar()
	{
		cout <<"Utilizador ID = "<<getCod_utilizador()<<" tipo: "<<getTipo()<<" grau "<<getGrau()<<endl;
	}
#endif