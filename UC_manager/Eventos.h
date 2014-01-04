#ifndef Eventos_
#define Eventos_
#include<string>
#include<iostream>
using namespace std;

class Eventos{

private:
	int codigo;
	string data;
	string hora;
	string descricao;
	int cod_uc;
	int prioridades;
	int edicao;


public:

	Eventos();
	Eventos(int cod, string d, string h, string des, int c, int pri, int ed);
	Eventos(const Eventos &e);
	~Eventos();
	virtual Eventos* clone()const;

	void setCodigo(int cod);
	void setData(string d);
	void setHora(string h);
	void setDescricao(string des);
	void setCod_uc(int c);
	void setPrioridades(int pri);
	void setEdicao(int ed);


	int getCodigo()const;
	string getData()const;
	string getHora()const;
	string getDescricao()const;
	int getCod_uc()const;
	int getPrioridades()const;
	int getEdicao()const;

	virtual void listar()const;
	virtual Eventos& operator=(const Eventos &e);
	virtual bool operator==(const Eventos &e)const;
	virtual bool operator>(const Eventos &e)const;
	void escrever(ostream &e)const;

	const Eventos& operator+=(const Eventos &e);

};

Eventos::Eventos(){
	this->codigo = 0;
	this->data = "";
	this->hora = "";
	this->descricao = "";
	this->cod_uc = 0;
	this->prioridades = 0;
	this->edicao = 0;
}

Eventos::Eventos(int cod, string d, string h, string des, int c, int pri, int ed){
	codigo = cod;
	data = d;
	hora = h;
	descricao = des;
	cod_uc = c;
	prioridades = pri;
	edicao = ed;

}

Eventos::Eventos(const Eventos &e){
	codigo = e.getCodigo();
	data = e.getData();
	hora = e.getHora();
	descricao = e.getDescricao();
	cod_uc = e.getCod_uc();
	prioridades = e.getPrioridades();
	edicao = e.getEdicao();


}

Eventos:: ~Eventos(){
}

Eventos* Eventos::clone()const{
	return new Eventos(*this);
}

void Eventos::setCodigo(int cod){
	codigo = cod;
}

void Eventos::setData(string d){
	data = d;
}

void Eventos::setHora(string h){
	hora = h;
}

void Eventos::setDescricao(string des){
	descricao = des;
}
void Eventos::setCod_uc(int c){
	cod_uc = c;
}
void Eventos::setPrioridades(int pri){
	prioridades = pri;
}
void Eventos::setEdicao(int ed){
	edicao = ed;
}

int Eventos::getCodigo()const{
	return codigo;
}

string Eventos::getData()const{
	return data;
}
string Eventos::getHora()const{
	return hora;
}

string Eventos::getDescricao()const{
	return descricao;
}
int Eventos::getCod_uc()const{
	return cod_uc;
}
int Eventos::getPrioridades()const{
	return prioridades;
}
int Eventos::getEdicao()const{
	return edicao;
}

Eventos& Eventos:: operator=(const Eventos &e){

	if (this != &e){
		codigo = e.codigo;
		data = e.data;
		hora = e.hora;
		descricao = e.descricao;
		cod_uc = e.cod_uc;
		prioridades = e.prioridades;
		edicao = e.edicao;
	}
	return *this;
}

bool Eventos:: operator==(const Eventos &e)const{

	if (codigo == e.codigo && data == e.data  && hora == e.hora && descricao == e.descricao && cod_uc == e.cod_uc && prioridades == e.prioridades && edicao == e.edicao)
		return true;
	return false;
}
bool Eventos:: operator>(const Eventos &e)const{

	if (prioridades > e.prioridades)
		return true;
	return false;
}


ostream &operator<<(ostream & out, const Eventos &e){
	e.escrever(out);
	return out;
}



void Eventos::escrever(ostream &o)const{

	o << "Evento: " << getDescricao() << endl;
	o << "Data: " << getData() << endl;
	o << "Unidade curricular: " << getCod_uc() << endl;
	o << "Edição: " << getEdicao() << endl;

}

#endif