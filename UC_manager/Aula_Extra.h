#ifndef Aula_Extra_
#define Aula_Extra_

#include"Eventos.h"
#include <list>
using namespace std;
#include "Sala.h"
#include "Aluno.h"

class Aula_Extra : public Eventos{

private:
	Sala sala;
	Pessoa* professor;

public:
	Aula_Extra();
	Aula_Extra(int cod, string data_inicio, string data_fim, string des, int pri,Sala sala,Pessoa professor);
	~Aula_Extra();
	Aula_Extra(const Aula_Extra &other);
	void escreve(ostream &out) const;
	virtual Aula_Extra* clone()const;
	Sala getSala()const;
	Pessoa* getProfessor()const;

	void setSala(Sala sala);
	void setProfessor(Pessoa prefessor);

	Aula_Extra& operator=(const Aula_Extra &a);
	bool operator==(const Aula_Extra &a)const;
	bool operator>(const Aula_Extra &a)const;
	void escrever(ostream &o)const;


};
Aula_Extra::Aula_Extra() {
}
Aula_Extra::Aula_Extra(int cod, string data_inicio, string data_fim, string des, int pri, Sala sala, Pessoa professor) :Eventos(cod, data_inicio, data_fim, des, pri){
	sala = sala;
	professor = professor;
}

Aula_Extra::Aula_Extra(const Aula_Extra & a){
	sala = a.getSala();
	professor = a.getProfessor();
}


Aula_Extra:: ~Aula_Extra(){
}

Aula_Extra* Aula_Extra::clone()const{
	return new Aula_Extra(*this);
}

void Aula_Extra::setSala(Sala s){
	sala = s;
}
void Aula_Extra::setProfessor(Pessoa professor){
	professor = professor;
}

Sala Aula_Extra::getSala()const{
	return sala;
}
Pessoa* Aula_Extra ::getProfessor()const{
	return this->professor;
}

Aula_Extra& Aula_Extra:: operator=(const Aula_Extra &a){

	if (this != &a){
		sala = a.sala;
		professor = a.professor;
	}
	return *this;
}

bool Aula_Extra:: operator==(const Aula_Extra &a)const{

	if (sala == a.sala && professor == a.professor)
		return true;
	return false;
}

ostream &operator<<(ostream & out, const Aula_Extra &a){
	a.escrever(out);
	return out;
}

void Aula_Extra::escrever(ostream &o)const{

	//o << "Sala: " << getSala() << endl;
	//o << "Professor: " << getProfessor () << endl;
}
#endif