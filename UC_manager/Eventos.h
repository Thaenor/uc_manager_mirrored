#ifndef Eventos_
#define Eventos_
//#include<iostream>
using namespace std;

class Eventos{

private:
	int codigo;
	string data_inicio;
	string data_fim;
	string descricao;
	int prioridades;


public:

	Eventos();
	Eventos(int cod, string data_inicio, string data_fim, string des, int pri);
	Eventos(const Eventos &e);
	~Eventos();
	virtual Eventos* clone()const;

	void setCodigo(int cod);
	void setDataFim(string data_fim);
	void setDataInicio(string data_inicio);
	void setDescricao(string des);
	void setPrioridades(int pri);


	int getCodigo()const;
	string getDataFim()const;
	string getDataInicio()const;
	string getDescricao()const;
	int getPrioridades()const;


	//virtual void listar()const;
	virtual Eventos& operator=(const Eventos &e);
	virtual bool operator==(const Eventos &e)const;
	virtual bool operator>(const Eventos &e)const;
	void escrever(ostream &e)const;

	const Eventos& operator+=(const Eventos &e);

};

Eventos::Eventos(){
	this->codigo = 0;
	this->data_inicio = "";
	this->data_fim = "";
	this->descricao = "";
	this->prioridades = 0;
}

Eventos::Eventos(int cod, string data_inicio, string data_fim, string des, int pri){
	codigo = cod;
	data_inicio = data_inicio;
	data_fim = data_fim;
	descricao = des;
	prioridades = pri;
}

Eventos::Eventos(const Eventos &e){
	codigo = e.getCodigo();
	data_inicio = e.getDataInicio();
	data_fim = e.getDataFim();
	descricao = e.getDescricao();
	prioridades = e.getPrioridades();
}

Eventos:: ~Eventos(){
}

Eventos* Eventos::clone()const{
	return new Eventos(*this);
}

void Eventos::setCodigo(int cod){
	codigo = cod;
}

void Eventos::setDataInicio(string data_inicio){
	data_inicio = data_inicio;
}

void Eventos::setDataFim(string data_fim){
	data_fim = data_fim;
}

void Eventos::setDescricao(string des){
	descricao = des;
}
void Eventos::setPrioridades(int pri){
	prioridades = pri;
}

int Eventos::getCodigo()const{
	return codigo;
}

string Eventos::getDataInicio()const{
	return data_inicio;
}
string Eventos::getDataFim()const{
	return data_fim;
}

string Eventos::getDescricao()const{
	return descricao;
}
int Eventos::getPrioridades()const{
	return prioridades;
}

Eventos& Eventos:: operator=(const Eventos &e){

	if (this != &e){
		codigo = e.codigo;
		data_inicio = e.data_inicio;
		data_fim = e.data_fim;
		descricao = e.descricao;
		prioridades = e.prioridades;
		
	}
	return *this;
}

bool Eventos:: operator==(const Eventos &e)const{

	if (codigo == e.codigo && data_inicio == e.data_inicio  && data_fim == e.data_fim && descricao == e.descricao && prioridades == e.prioridades)
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
	o << "Data Inicio: " << getDataInicio() << endl;
	o << "Data Fim: " << getDataFim() << endl;
	o << "Prioridade: " << getPrioridades() << endl;

}

#endif