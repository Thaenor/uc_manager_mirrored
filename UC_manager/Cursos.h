#ifndef Cursos_
#define Cursos_
#include<vector>
#include <string>
#include<list>

#include"Eventos.h"
#include"Sala.h"
#include"Pessoa.h"
#include "Gestao.h"
using namespace std;

class Cursos :Eventos{

private:
	Sala sala;
	vector<Pessoa*> formadores;
	

public:
	Cursos();
	Cursos(int cod, string data_inicio, string data_fim, string des, int pri,Sala sala, vector<Pessoa*>formad);
	Cursos(const Cursos &c);
	~Cursos();

	virtual Cursos* clone()const;
	Sala getSala()const;
	vector<Pessoa*>getFormadores()const;

	void setSala(Sala sala);
	void setFormadores(vector<Pessoa*>formadores);

	Cursos& operator=(const Cursos &c);
	bool operator==(const Cursos &c)const;
	bool operator>(const Cursos &c)const;
	void escrever(ostream &o) const;


};
Cursos::Cursos() {
}
Cursos::Cursos(int cod, string data_inicio, string data_fim, string des, int pri, Sala sala, vector<Pessoa*>formad) :Eventos(cod, data_inicio, data_fim, des, pri){
	sala = sala;
	formadores = formad;
}

Cursos::Cursos(const Cursos & c){
	sala = c.getSala();
	formadores = c.getFormadores();
}


Cursos:: ~Cursos(){
}

Cursos* Cursos::clone()const{
	return new Cursos(*this);
}

void Cursos::setSala(Sala s){
	sala = s;
}
void Cursos::setFormadores(vector<Pessoa*> formd){
	formadores = formd;
}

Sala Cursos::getSala()const{
	return sala;
}
vector<Pessoa*> Cursos::getFormadores()const{
	return this->formadores;
}

Cursos& Cursos:: operator=(const Cursos &c){

	if (this != &c){
		sala = c.sala;
		formadores = c.formadores;
	}
	return *this;
}

bool Cursos:: operator==(const Cursos &c)const{

	if (sala == c.sala && formadores == c.formadores)
		return true;
	return false;
}

ostream &operator<<(ostream & out, const Cursos &c){
	c.escrever(out);
	return out;
}

void Cursos::escrever(ostream &o)const{
	Gestao<Pessoa> g;
	o << "Sala: " << sala.getCod_sala() << endl;
	o << "Formadores: " <<  g.ListarVectores(formadores) << endl;
}
#endif