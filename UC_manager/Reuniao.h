#ifndef Reuniao_
#define Reuniao_

#include"Eventos.h"
#include <string>
#include<list>

class Reuniao : public Eventos{

private:
	int codigo;
	string sala;
	string cod_utilizador;
	list<string>cod_utilizadores;



public:
	Reuniao();
	Reuniao(int codigo, string s, string c, list<string>cod_utili);
	Reuniao(const Reuniao &r);
	~Reuniao();

	virtual Eventos* clone()const;
	int getCodigo()const;
	string getSala()const;
	string getCod_utilizador()const;
	list<string>getCod_utilizadoreres()const{ return cod_utilizadores };


	void setCodigo(int codigo);
	void setSala(int sala);
	void setCod_utilizador(string cod_utilizador);
	void setCod_utilizadores(list<string> val){ cod_utilizadores = val; }

	Reuniao& operator=(const Reuniao &r);
	bool operator==(const Reuniao &r)const;
	bool operator>(const Reuniao &r)const;
	void escrever(ostream &o)const;


};
Reuniao::Reuniao() {
	this->codigo = 0;
	this->sala = "";
	this->cod_utilizador = "";
}

Reuniao::Reuniao(int cod, string s, string c, list<string>cod_utili){
	codigo = cod;
	sala = s;
	cod_utilizador = c;
	cod_utilizadores = cod_utili;
}

Reuniao::Reuniao(const Reuniao & r){
	codigo = r.getCodigo();
	sala = r.getSala();
	cod_utilizador = r.getCod_utilizador();
	cod_utilizadores = r.getCod_utilizadores();


	Reuniao:: ~Reuniao(){
	}

	Reuniao* Reuniao::clone()const{
		return new Reuniao(*this);
	}
	void Reuniao::setCodigo(int cod){
		codigo = cod;
	}

	void Reuniao::setSala(int s){
		sala = s;
	}

	void Reuniao::setCod_utilizador(int cod_utili){
		cod_utilizador = cod_utili;
	}
	int Reuniao::getCodigo()const{
		return codigo;
	}
	int Reuniao::getSala()const{
		return codigo;
	}
	int Reuniao::getCod_utilizador()const{
		return cod_utilizador;
	}
	int Reuniao::getCod_utilizadores()const{
		return cod_utilizadores;
	}

	Reuniao& Reuniao:: operator=(const Reuniao &r){

		if (this != &r){
			codigo = r.codigo;
			sala = r.sala;
			cod_utilizador = r.cod_utilizador;
			cod_utilizadores = r.cod_utilizadores;
		}
		return *this;
	}

	bool Reuniao:: operator==(const Reuniao &r)const{

		if (codigo == r.codigo && sala == r.sala  && cod_utilizador == r.cod_utilizador && cod_utilizadores == r.cod_utilizadores)
			return true;
		return false;
	}

	ostream &operator<<(ostream & out, const Reuniao &r){
		r.escrever(out);
		return out;
	}

	void Reuniao::escrever(ostream &o)const{

		o << "Sala: " << getSala() << endl;
		o << "Docentes: " << getCod_utilizadores() << endl;
	}
#endif