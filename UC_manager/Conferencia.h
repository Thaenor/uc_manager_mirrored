#ifndef Conferencia_
#define Conferencia_

#include"Eventos.h"
#include"Pessoa.h"
#include"Sala.h"
#include"Gestao.h"

#include <string>
#include<list>
#include<vector>
using namespace std;

class Conferencia : public Eventos{

private:
	Sala sala;
	vector<Pessoa*> oradores;



public:
	Conferencia();
	Conferencia(int cod, string data_inicio, string data_fim, string des, int pri,Sala s, vector<Pessoa*>orad);
	Conferencia(const Conferencia &c);
	~Conferencia();

	virtual Conferencia* clone()const;

	Sala getSala()const;
	vector<Pessoa*>getOradores()const;

	void setSala(Sala sala);
	void setOradores(vector<Pessoa*> oradores);

	Conferencia& operator=(const Conferencia &c);
	bool operator==(const Conferencia &c)const;
	bool operator>(const Conferencia &c)const;
	void escrever(ostream &o)const;


};
Conferencia::Conferencia() {
}

Conferencia::Conferencia(int cod, string data_inicio, string data_fim, string des, int pri, Sala s, vector<Pessoa*>orad) :Eventos(cod,data_inicio,data_fim,des,pri){
	sala = s;
	oradores = orad;
}

Conferencia::Conferencia(const Conferencia & c){
	sala = c.getSala();
	oradores = c.getOradores();
}


	Conferencia:: ~Conferencia(){
	}

	Conferencia* Conferencia::clone()const{
		return new Conferencia(*this);
	}

	void Conferencia::setSala(Sala s){
		sala = s;
	}
	void Conferencia::setOradores(vector<Pessoa*> orad){
		oradores = orad; 
	}
	
	Sala Conferencia::getSala()const{
		return sala;
	}
	vector<Pessoa*> Conferencia::getOradores()const{
		return this->oradores; 
	}

	Conferencia& Conferencia:: operator=(const Conferencia &c){

		if (this != &c){
			sala = c.sala;
			oradores = c.oradores;
		}
		return *this;
	}

	bool Conferencia:: operator==(const Conferencia &c)const{

		if (sala == c.sala && oradores == c.oradores)
			return true;
		return false;
	}

	ostream &operator<<(ostream & out, const Conferencia &c){
		c.escrever(out);
		return out;
	}

	void Conferencia::escrever(ostream &o)const{
		Gestao <Pessoa> g;
		o << "Sala: " << sala.getCod_sala() << endl;
		o << "Oradores: " << g.ListarVectores(oradores) << endl;
	}
#endif