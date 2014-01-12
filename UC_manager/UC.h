//
//  UC.h
//  UC_Manager
//
//  Created by Francisco Santos on 16/12/13.
//  Copyright (c) 2013 Grupo B6-5. All rights reserved.
//
#ifndef UC_
#define UC_

#include "Eventos.h"
using namespace std;



class UC
{
private:
	string cod_uc;
	string nome;
	string edicao;
	string ano;

	string semestre;
	string regente;
	vector<Pessoa*> alunos;
	vector<Pessoa*> utilizador;
	vector<Eventos*> eventos;


public:
	UC();                           /* Construtor por Defeito */
	UC(string _regente, string _cod_uc, string _nome, string _edicao, string ano, string semestre);     /* Construtor com parametros */
	~UC();                          /* Destrutor */
	UC(const UC &other);            /* Construtor Copia */
	UC* clone() const;              /* construtor Clone */
	void print(ostream &out) const;
	void write();                   /*write UC name*/

	//string getCod()const;            /*Gets & set*/
	string getRegente()const;
	void setRegente(string regente);

	/*      Operator Overl0ad!    */
	//virtual UC & operator = (const UC &l);
	bool operator > (const UC &other) const;
	bool operator==(const UC& other) const;

	string Ano() const { return ano; }
	void Ano(string val) { ano = val; }

	string Nome() const { return nome; }
	void Nome(string val) { nome = val; }
	string getSemestre() const;
	void setSemestre(int val);
	string getAno() const;
	void setAno(string val);
	vector<Pessoa*> getUtilizador() const;
	void setUtilizador(vector<Pessoa*> Utilizador);
	vector<Pessoa*> getAlunos() const;
	void setAlunos(vector<Pessoa*> alunos);
	vector<Eventos*> geteventos() const;
	void setEventos(vector<Eventos*> eventos);
	UC &operator = (const UC &other);

	string Cod_uc() const { return cod_uc; }
	void Cod_uc(string val) { cod_uc = val; }
	string Edicao() const { return edicao; }
	void Edicao(string val) { edicao = val; }

	};

	UC::UC()                            /* Construtor por Defeito */
	{
		cod_uc = "";
		regente = "default";
	}

	UC::UC(string _regente, string _cod_uc, string _nome, string _edicao, string ano, string semestre)         /* Construtor com parametros */
	{
		this->cod_uc = _cod_uc;
		this->nome = _nome;
		this->regente = _regente;
		this->edicao = _edicao;
		this->ano = ano;
		this->semestre = semestre;

	}

	UC::~UC()         /* Destrutor */
	{
	}

	UC* UC::clone()const  /* construtor Clone */
	{
		return new UC(*this);
	}


	UC::UC(const UC &other){    /* Construtor Copia */
		//cod_uc = other.getCod();
		regente = other.getRegente();
		ano = other.getAno();
		semestre = other.getSemestre();

		utilizador = other.getUtilizador();
		alunos = other.getAlunos();
		/// vector avaliação a implementar
		regente = other.getRegente();

	}

	string UC::getSemestre() const { return semestre; }
	string UC::getAno() const { return ano; }
	vector<Pessoa*> UC::getUtilizador() const { return utilizador; }
	vector<Pessoa*> UC::getAlunos() const { return alunos; }
	vector<Eventos*> UC::geteventos() const { return eventos; }
	string UC::getRegente() const { return regente; }

	void UC::setSemestre(int semestre) { this->semestre = semestre; }
	void UC::setUtilizador(vector<Pessoa*> utilizador) { this->utilizador = utilizador; }
	void UC::setAlunos(vector<Pessoa*> alunos) { this->alunos = alunos; }
	void UC::setEventos(vector<Eventos*> eventos) { this->eventos = eventos; }
	void UC::setRegente(string regente) { this->regente = regente; }


	void UC::print(ostream &out) const
	{
		out << "Codigo UC = " << cod_uc << " regente: " << regente << ". ";
	}

	void UC::write()
	{
		cout << "Unidade curricular: " << regente;
	}

	/*******************************************************************************************/
	/*      Operator Overl0ad!    */

	/* Operator == overload - Comparison */
	bool UC::operator==(const UC& other) const
	{
		if (cod_uc == other.cod_uc)
			return true;
		else
			return false;
	}

	UC & UC::operator = (const UC &other){
		if (&other != this){
			cod_uc = other.cod_uc;
		}
		return *this;
	}

	/* Operator > overload - greater than */
	bool UC::operator > (const UC &other) const{
		return (cod_uc > other.cod_uc);
	}


	/****************************************...************************************************/

	/*  Overl0ad print operator - NORMAL  */
	ostream& operator<<(ostream& out,UC uc){
		uc.print(out);
		return out;
	}

#endif
