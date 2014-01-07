#ifndef Avaliacao_
#define Avaliacao_
#include<vector>
#include <string>
#include<list>

#include"Eventos.h"
#include"Sala.h"
#include"Pessoa.h"
using namespace std;

class Avaliacao{

private:
	int cod_avaliacao;
	
	string tipo;
	
	string data_inicio
		;
	
	string data_fim;

	int estado;
	int Estado() const { return estado; }
	void Estado(int val) { estado = val; }
	vector<Sala*> salas;
	vector<Pessoa*> monitores;
	int docentes_sala;
	
public:

	Avaliacao();
	~Avaliacao();
	Avaliacao(int c, string t, string di, string df, int es,vector<Sala*> sa, vector<Pessoa*> moni, int doc);

	int Docentes_sala() const { return docentes_sala; }
	void Docentes_sala(int val) { docentes_sala = val; }
	vector<Pessoa*> Monitores() const { return monitores; }
	void Monitores(vector<Pessoa*> val) { monitores = val; }
	vector<Sala*> Salas() const { return salas; }
	void Salas(vector<Sala*> val) { salas = val; }
	std::string Data_fim() const { return data_fim; }
	void Data_fim(std::string val) { data_fim = val; }
	std::string Data_inicio() const { return data_inicio; }
	void Data_inicio(std::string val) { data_inicio = val; }
	std::string Tipo() const { return tipo; }
	void Tipo(std::string val) { tipo = val; }
	int Cod_avaliacao() const { return cod_avaliacao; }
	void Cod_avaliacao(int val) { cod_avaliacao = val; }

	Avaliacao& operator=(const Avaliacao &c);
	bool operator==(const Avaliacao &c)const;
	bool operator>(const Avaliacao &c)const;
	void escrever(ostream &o)const;
};

Avaliacao::Avaliacao()
{

}

Avaliacao::~Avaliacao(){}

Avaliacao::Avaliacao(int c, string t, string di, string df, int es, vector<Sala*> sa, vector<Pessoa*> moni, int doc)
{
	cod_avaliacao = c;
	tipo = t;
	data_inicio = di;
	data_fim = df;
	estado = es;
	salas = sa;
	monitores = moni;
	docentes_sala = doc;
}

Avaliacao& Avaliacao::operator=(const Avaliacao &c)
{
	cod_avaliacao = c.Cod_avaliacao();
	tipo = c.Tipo();
	data_inicio = c.Data_inicio();
	data_fim = c.Data_fim();
	estado = c.Estado();
	salas = c.Salas();
	monitores = c.Monitores();
	docentes_sala = c.Docentes_sala();
}

bool Avaliacao::operator==(const Avaliacao &c) const
{
	if (cod_avaliacao == c.Cod_avaliacao())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Avaliacao::operator>(const Avaliacao &c) const
{
	if (cod_avaliacao > c.Cod_avaliacao())
	{
		return true;	
	}
	else{ return false; }
}

ostream &operator<<(ostream & out, const Avaliacao &c){
	c.escrever(out);
	return out;
}
void Avaliacao::escrever(ostream &o)const
{
	o << "Codigo de avaliacao:" << cod_avaliacao<<endl;
}

#endif
