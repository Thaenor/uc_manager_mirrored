//
//  UC.h
//  UC_Manager
//
//  Created by Francisco Santos on 16/12/13.
//  Copyright (c) 2013 Grupo B6-5. All rights reserved.
//
#ifndef UC_
#define UC_

#include <vector>
#include <string>
#include <iostream>

using namespace std;

#include "Pessoa.h";
#include "Eventos.h";


class UC
{
private:
    string cod_uc;
    int edicao;
	int ano,semestre;
	string regente;
	vector<Pessoa*> alunos;
	vector<Pessoa*> docentes;
	vector<Eventos*> eventos;
	
    
public:
    UC();                           /* Construtor por Defeito */
    UC(string ID, string name, int ano, int semestre);     /* Construtor com parametros */
    ~UC();                          /* Destrutor */
    UC(const UC &other);            /* Construtor Copia */
    UC* clone() const;              /* construtor Clone */
    void print(ostream out) const;
    void write();                   /*write UC name*/
    
    string getCod()const;            /*Gets & set*/
    void setCod(int ID);
    string getRegente()const;
    void setRegente(string regente);
    
                                    /*      Operator Overl0ad!    */
    //virtual UC & operator = (const UC &l);
	bool operator > ( const UC &other) const;
	bool operator==(const UC& other) const;

	int getSemestre() const;
	void setSemestre(int val);
	int getAno() const;
	void setAno(int val);
	vector<Pessoa> getDocentes() const;
	void setDocentes(vector<Pessoa> docentes);
	vector<Pessoa> getAlunos() const;
	void setAlunos(vector<Pessoa> alunos);
	vector<Eventos> geteventos() const;
	void setEventos(vector<Eventos> eventos);
	string getRegente() const;
	void setRegente(string regente);
};

UC::UC()                            /* Construtor por Defeito */
{
    cod_uc = "";
    regente = "default";
}

UC::UC(string cod_uc, string regente, int ano, int semestre)         /* Construtor com parametros */
{
    this->cod_uc = cod_uc;
    this->regente = regente;
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
    cod_uc=other.getCod();
    regente=other.getRegente();
	ano= other.getAno();
	semestre= other.getSemestre();

	docentes = other.getDocentes();
	alunos = other.getAlunos();
	/// vector avaliação a implementar
	regente = other.getRegente();

}

	int UC::getSemestre() const { return semestre; }
	int UC::getAno() const { return ano; }
	vector<Pessoa> UC::getDocentes() const { return docentes; }
	vector<Pessoa> UC::getAlunos() const { return alunos; }
	vector<Eventos> UC::geteventos() const { return eventos; }
	string UC::getRegente() const { return regente; }

	void UC::setSemestre(int val) { semestre = val; }
	void UC::setAno(int val) { ano = val; }
	void UC::setDocentes(vector<Pessoa> docentes) { this->docentes = docentes; }
	void UC::setAlunos(vector<Pessoa> alunos) { this->alunos = alunos; }
	void UC::setEventos(vector<Eventos> eventos) { this->eventos = eventos; }
	void UC::setRegente(string regente) { this->regente = regente; }


void UC::print(ostream out) const
{
    out << "UC ID = " << cod_uc << " name: " << regente << ". ";
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
	if(&other!=this){
		cod_uc=other.cod_uc;
	}
	return *this;
}

/* Operator > overload - greater than */
bool UC::operator > ( const UC &other) const{
	return (cod_uc > other.cod_uc);
}


/****************************************...************************************************/

/*  Overl0ad print operator - NORMAL  */
ostream& operator<<(ostream& out, const UC* UC){
    UC->print(out);
    return out;
}

#endif
