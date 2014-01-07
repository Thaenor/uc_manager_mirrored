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
	string data_inicio;
	string data_fim;
	int estado;
	vector<Sala*> salas;
	vector<Pessoa*> monitores;
	int docentes_sala;
	
public:

	Avaliacao();
	~Avaliacao();
	Avaliacao(int c, string t, string di, string df, int es,vector<Sala*> sa, vector<Pessoa*> moni, int doc);

	int getDocentes_sala() const { return docentes_sala; }
	void setDocentes_sala(int val) { docentes_sala = val; }
	vector<Pessoa*> getMonitores() const { return monitores; }
	void setMonitores(vector<Pessoa*> val) { monitores = val; }
	vector<Sala*> getSalas() const { return salas; }
	void setSalas(vector<Sala*> val) { salas = val; }
	std::string getData_fim() const { return data_fim; }
	void setData_fim(std::string val) { data_fim = val; }
	std::string getData_inicio() const { return data_inicio; }
	void setData_inicio(std::string val) { data_inicio = val; }
	std::string getTipo() const { return tipo; }
	void setTipo(std::string val) { tipo = val; }
	int getCod_avaliacao() const { return cod_avaliacao; }
	void setCod_avaliacao(int val) { cod_avaliacao = val; }
	int getEstado() const { return estado; }
	void setEstado(int val) { estado = val; }

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
	//o << "Codigo de avaliacao:" << cod_avaliacao<<endl;
}

#endif
