#ifndef Conferencia_
#define Conferencia_

#include"Eventos.h"
#include <string>
#include<list>

class Conferencia : public Eventos{

private:
	int codigo;
	string sala;
	string cod_utilizador;
	list<string>cod_utilizadores;



public:
	Conferencia();
	Conferencia(int codigo, string s, string c, list<string>cod_utili);
	Conferencia(const Conferencia &c);
	~Conferencia();

	virtual Eventos* clone()const;
	int getCodigo()const;
	string getSala()const;
	string getCod_utilizador()const;
	list<string>getCod_utilizadoreres()const{ return cod_utilizadores };


	void setCodigo(int codigo);
	void setSala(int sala);
	void setCod_utilizador(string cod_utilizador);
	void setCod_utilizadores(list<string> val){ cod_utilizadores = val; }

	Conferencia& operator=(const Conferencia &c);
	bool operator==(const Conferencia &c)const;
	bool operator>(const Conferencia &c)const;
	void escrever(ostream &o)const;


};
Conferencia::Conferencia() {
	this->codigo = 0;
	this->sala = "";
	this->cod_utilizador = "";
}

Conferencia::Conferencia(int cod, string s, string c, list<string>cod_utili){
	codigo = cod;
	sala = s;
	cod_utilizador = c;
	cod_utilizadores = cod_utili;
}

Conferencia::Conferencia(const Conferencia & c){
	codigo = c.getCodigo();
	sala = c.getSala();
	cod_utilizador = c.getCod_utilizador();
	cod_utilizadores = c.getCod_utilizadores();
}


	Conferencia:: ~Conferencia(){
	}

	Conferencia* Conferencia::clone()const{
		return new Conferencia(*this);
	}
	void Conferencia::setCodigo(int cod){
		codigo = cod;
	}

	void Conferencia::setSala(int s){
		sala = s;
	}

	void Conferencia::setCod_utilizador(int cod_utili){
		cod_utilizador = cod_utili;
	}
	int Conferencia::getCodigo()const{
		return codigo;
	}
	int Conferencia::getSala()const{
		return codigo;
	}
	int Conferencia::getCod_utilizador()const{
		return cod_utilizador;
	}
	int Conferencia::getCod_utilizadores()const{
		return cod_utilizadores;
	}

	Conferencia& Conferencia:: operator=(const Reuniao &c){

		if (this != &c){
			codigo = c.codigo;
			sala = c.sala;
			cod_utilizador = c.cod_utilizador;
			cod_utilizadores = c.cod_utilizadores;
		}
		return *this;
	}

	bool Conferencia:: operator==(const Reuniao &c)const{

		if (codigo == c.codigo && sala == c.sala  && cod_utilizador == c.cod_utilizador && cod_utilizadores == c.cod_utilizadores)
			return true;
		return false;
	}

	ostream &operator<<(ostream & out, const Reuniao &c){
		c.escrever(out);
		return out;
	}

	void Conferencia::escrever(ostream &o)const{

		o << "Sala: " << getSala() << endl;
		o << "Docentes: " << getCod_utilizadores() << endl;
	}
#endif