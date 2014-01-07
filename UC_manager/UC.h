//
//  UC.h
//  UC_Manager
//
//  Created by Francisco Santos on 16/12/13.
//  Copyright (c) 2013 Grupo B6-5. All rights reserved.
//
#ifndef UC_
#define UC_

#include <list>


using namespace std;


class UC
{
private:
    string _ID;
    string _name;
	int ano,semestre;
	list<Utilizador> docentes;
	list <Aluno> alunos;
	/// list avaliação a implementar
	Utilizador regente;
	

    
public:
    UC();                           /* Construtor por Defeito */
    UC(string ID, string name);        /* Construtor com parametros */
    ~UC();                          /* Destrutor */
    UC(const UC &other);            /* Construtor Copia */
    UC* clone() const;              /* construtor Clone */
    void print(ostream out) const;
    void write();                   /*write UC name*/
    
    string getID()const;                    /*Gets & set*/
    void setID(int ID);
    string getName()const;
    void setID(string name);
    
                                    /*      Operator Overl0ad!    */
    //virtual UC & operator = (const UC &l);
	bool operator > ( const UC &other) const;
	bool operator==(const UC& other) const;

	int getSemestre() const { return semestre; }
	void setSemestre(int val) { semestre = val; }
	int getAno() const { return ano; }
	void setAno(int val) { ano = val; }
	list<Utilizador> getDocentes() const { return docentes; }
	void setDocentes(list<Utilizador> val) { docentes = val; }
	list<Aluno> getAlunos() const { return alunos; }
	void setAlunos(list<Aluno> val) { alunos = val; }
	Utilizador getRegente() const { return regente; }
	void setRegente(Utilizador val) { regente = val; }
};

UC::UC()                            /* Construtor por Defeito */
{
    _ID = "";
    _name = "default";
}

UC::UC(string ID, string name)         /* Construtor com parametros */
{
    _ID = ID;
    _name = name;

}

UC::~UC()         /* Destrutor */
{
}

UC* UC::clone()const  /* construtor Clone */
{
    return new UC(*this);
}


UC::UC(const UC &other){    /* Construtor Copia */
    _ID=other.getID();
    _name=other.getName();
	ano= other.getAno();
	semestre= other.getSemestre();

	docentes = other.getDocentes();
	alunos= other.getAlunos();
	/// list avaliação a implementar
	regente = other.getRegente();

}

string UC::getID() const {return _ID;}            /*Gets & set*/
void UC::setID(int ID){_ID = ID;}
string UC::getName()const  {return _name;}
void UC::setID(string name){_name = name;}

void UC::print(ostream out) const
{
    out << "UC ID = " << _ID << " name: " << _name << ". ";
}

void UC::write()
{
    cout << "Unidade curricular: " << _name;
}

/*******************************************************************************************/
/*      Operator Overl0ad!    */

/* Operator == overload - Comparison */
bool UC::operator==(const UC& other) const
{
	if (_ID == other._ID)
		return true;
	else
		return false;
}

/*
UC & UC::operator = (const UC &other){
	if(&other!=this){
		_ID=other._ID;
	}
	return *this;
}*/

/* Operator > overload - greater than */
bool UC::operator > ( const UC &other) const{
	return (_ID > other._ID);
}


/****************************************...************************************************/

/*  Overl0ad print operator - NORMAL  */
/*ostream& operator<<(ostream& out, const UC* UC){
    UC->print(out);
    return out;
}*/

#endif
