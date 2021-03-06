#ifndef Avaliacao_
#define Avaliacao_

#include "Sala.h"
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
	UC * uc;
	string uni;
	string edi;
	
public:

	Avaliacao();
	~Avaliacao();
	Avaliacao(int c, string t, string di, string df, int es, vector<Sala*> sa, vector<Pessoa*> moni, int doc);
	Avaliacao(string _tipo, UC * _uc, int cod);
	Avaliacao(int c, string t, string uc, string edi_);
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
	UC * Avaliacao :: getUC();


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

Avaliacao :: Avaliacao(int c, string t, string uc, string edi_)
{
	uni = uc;
	edi = edi_;
	cod_avaliacao = c;
	tipo = t;
}



Avaliacao :: Avaliacao(string _tipo, UC * _uc, int cod)
{
	tipo = _tipo;
	uc = _uc->clone();
	cod_avaliacao = cod;
}


Avaliacao& Avaliacao::operator=(const Avaliacao &c)
{
	cod_avaliacao = c.getCod_avaliacao();
	tipo = c.getTipo();
	data_inicio = c.getData_inicio();
	data_fim = c.getData_fim();
	estado = c.getEstado();
	salas = c.getSalas();
	monitores = c.getMonitores();
	docentes_sala = c.getDocentes_sala();
	return *this;
}

bool Avaliacao::operator==(const Avaliacao &c) const
{
	if (cod_avaliacao == c.getCod_avaliacao())
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
	if (cod_avaliacao > c.getCod_avaliacao())
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

UC * Avaliacao :: getUC()
{
	return uc;
}


#endif
