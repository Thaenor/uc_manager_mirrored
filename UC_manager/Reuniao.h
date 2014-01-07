#ifndef Reuniao_
#define Reuniao_

#include <string>
#include<list>
#include<vector>

#include"Sala.h"
#include"Pessoa.h"
#include"Eventos.h"
using namespace std;

class Reuniao : public Eventos{

private:
	Sala sala;
	vector<Pessoa*>docente;

public:
	Reuniao();
	Reuniao(int cod, string data_inicio, string data_fim, string des, int pri,Sala sala, vector<Pessoa>docente);
	Reuniao(const Reuniao &r);
	~Reuniao();

	virtual Eventos* clone()const;
	Sala getSala()const;
	vector<Pessoa>getDocente()const;


	void setSala(Sala sala);
	void setDocente(vector<Pessoa> docente);

	Reuniao& operator=(const Reuniao &r);
	bool operator==(const Reuniao &r)const;
	bool operator>(const Reuniao &r)const;
	void escrever(ostream &o)const;


};
Reuniao::Reuniao() {
}

Reuniao::Reuniao((int cod, string data_inicio, string data_fim, string des, int pri, Sala sala, vector<Pessoa>docente) : Eventos(cod, data_inicio, data_fim, des, pri){
	sala = sala;
	docente = decente;
}

Reuniao::Reuniao(const Reuniao & r){
	sala = r.getSala();
	docente = r.getDocente();


	Reuniao:: ~Reuniao(){
	}

	Reuniao* Reuniao::clone()const{
		return new Reuniao(*this);
	}

	void Reuniao::setSala(Sala s){
		sala = s;
	}

	void Reuniao::setDocente(vector<Pessoa> docente){
		docente = docente;
	}

	Sala Reuniao::getSala()const{
		return sala;
	}

	vector<Pessoa> Reuniao::getDocente()const{
		return docente;
	}

	Reuniao& Reuniao:: operator=(const Reuniao &r){

		if (this != &r){
			sala = r.sala;
			docente = r.docente;
		}
		return *this;
	}

	bool Reuniao:: operator==(const Reuniao &r)const{

		if (sala == r.sala  && docente == r.docente)
			return true;
		return false;
	}

	ostream &operator<<(ostream & out, const Reuniao &r){
		r.escrever(out);
		return out;
	}

	void Reuniao::escrever(ostream &o)const{

		o << "Sala: " << getSala() << endl;
		o << "Docentes: " << getDocente() << endl;
	}
#endif