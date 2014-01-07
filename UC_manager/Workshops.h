#ifndef Workshops_
#define Workshops_
#include <string>
#include<list>
#include<vector>

using namespace std;

#include"Eventos.h"
#include"Sala.h"
#include"Pessoa.h"

class Workshops: public Eventos{

private:	
	Sala sala;
	vector<Pessoa*> formador;


public:
	Workshops();
	Workshops(int cod, string data_inicio, string data_fim, string des, int pri,Sala sala,vector<Pessoa*>formador);
	Workshops(const Workshops &w);
	~Workshops();

	virtual Eventos* clone()const;
	
	Sala getSala()const;
	vector<Pessoa*>getFormador()const;


	
	void setSala(Sala sala);
	
	void setFormaodres(vector<Pessoa*> formador){ formador = formador; }

	Workshops& operator=(const Workshops &w);
	bool operator==(const Workshops &w)const;
	bool operator>(const Workshops &w)const;
	void escrever(ostream &o)const;


};
Workshops::Workshops() {
}

Workshops::Workshops(int cod, string data_inicio, string data_fim, string des, int pri, Sala sala, vector<Pessoa*>formador) :Eventos(cod, data_inicio, data_fim, des, pri){
	this->sala = sala;
	formador = formador;
}

Workshops::Workshops(const workshops & w){
	sala = w.getSala();
	formador = w.getFormador();


	Workshops:: ~Workshops(){
	}

	Workshops* Workshops::clone()const{
		return new Workshops(*this);
	}

	void Workshops::setSala(Sala s){
		sala = s;
	}

	void Workshops::setFormador(Pessoa p){
		formador = p;
	}

	int Workshops::getSala()const{
		return codigo;
	}
	int Workshops::getFormador()const{
		return formador;
	}

	Workshops& Workshops:: operator=(const Workshops &w){

		if (this != &w){
			sala = w.sala;
			formador = w.formador;
		}
		return *this;
	}

	bool Workshops:: operator==(const Workshops &w)const{

		if (sala == w.sala  && formador == w.formador)
			return true;
		return false;
	}

	ostream &operator<<(ostream & out, const Workshops &w){
		w.escrever(out);
		return out;
	}

	void Workshops::escrever(ostream &o)const{

		o << "Sala: " << getSala() << endl;
		o << "Formador: " << getFormador() << endl;
	}
#endif