#ifndef Visita_de_estudo_
#define Visita_de_estudo_

#include"Eventos.h"
#include"Pessoa.h"
#include <string>
#include<list>
#include<vector>
using namespace std;

class Visita_de_estudo : public Eventos{

private:
	string local;
	vector<Pessoa>monitores;



public:
	Visita_de_estudo();
	Visita_de_estudo(int cod, string data_inicio, string data_fim, string des, int pri,string local, vector<Pessoa>monitores);
	Visita_de_estudo(const Visita_de_estudo &v);
	~Visita_de_estudo();

	virtual Visita_de_estudo* clone()const;
	string getLocal()const;
	vector<Pessoa>getMonitores()const;

	void setLocal(string local);
	void setMonitores(vector<Pessoa> monitores);

	Visita_de_estudo& operator=(const Visita_de_estudo &v);
	bool operator==(const Visita_de_estudo &v)const;
	bool operator>(const Visita_de_estudo &v)const;
	void escrever(ostream &o)const;


};
Visita_de_estudo::Visita_de_estudo() {
	this->local = "";
}

Visita_de_estudo::Visita_de_estudo(int cod, string data_inicio, string data_fim, string des, int pri, string local, vector<Pessoa>monitores) :Eventos(cod, data_inicio, data_fim, des, pri){
	local = local;
	monitores = monitores;

}

Visita_de_estudo::Visita_de_estudo(const Visita_de_estudo & v){
	local = v.getLocal();
	monitores = v.getMonitores();
}


	Visita_de_estudo:: ~Visita_de_estudo(){
	}

	Visita_de_estudo* Visita_de_estudo::clone()const{
		return new Visita_de_estudo(*this);
	}

	void Visita_de_estudo::setLocal(string l){
		local = l;
	}
	void Visita_de_estudo::setMonitores(vector<Pessoa>  monit){
		monitores = monit;
	}
	

	string Visita_de_estudo::getLocal()const{
		return local;
	}
	vector<Pessoa> Visita_de_estudo::getMonitores()const{
		return monitores;

	}

	Visita_de_estudo& Visita_de_estudo:: operator=(const Visita_de_estudo &v){

		if (this != &v){
			local = v.getLocal();
			monitores = v.getMonitores();
		}
		return *this;
	}

	bool Visita_de_estudo:: operator==(const Visita_de_estudo &v)const{

		if (monitores==v.getMonitores() && local == v.getLocal())
			return true;
		return false;
	}

	ostream &operator<<(ostream & out, const Visita_de_estudo &v){
		v.escrever(out);
		return out;
	}

	void Visita_de_estudo::escrever(ostream &o)const{

		o << "Local:" << getLocal() << endl
			;// falta lista de monitores !!! 
	}
#endif