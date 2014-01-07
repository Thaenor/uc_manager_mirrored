//
//  Mensagem.h
//  Afonso Reis 
#include <string>
using namespace std;

class Mensagem
{
private:
	int cod_mensagem;
	string texto;
	string assunto;
	string anexo; //URL do anexo
	string cod_destino;
	string cod_origem;
	string data_ini;
	string data_limite;


public:
	Mensagem();
	Mensagem(int cod_mensagem, string texto,string assunto,string anexo,string cod_destino,string cod_origem, string data_ini, string data_limite);
	~Mensagem();
	Mensagem(const Mensagem& other);
	void escreve(ostream &out) const;
	//  void escreve(); 

	int getCod_mensagem() const { return cod_mensagem; }
	void setCod_mensagem(int val) { cod_mensagem = val; }
	string getTexto() const { return texto; }
	void setTexto(string val) { texto = val; }
	string getAssunto() const { return assunto; }
	void setAssunto(string val) { assunto = val; }
	string getAnexo() const { return anexo; }
	void setAnexo(string val) { anexo = val; }
	string getCod_destino() const { return cod_destino; }
	void setCod_destino(string val) { cod_destino = val; }
	string getCod_origem() const { return cod_origem; }
	void setCod_origem(string val) { cod_origem = val; }
	string getData_ini() const { return data_ini; }
	void setData_ini(string val) { data_ini = val; }
	string getData_limite() const { return data_limite; }
	void setData_limite(string val) { data_limite = val; }
	void listar();
};

Mensagem :: Mensagem() 
{
	assunto = "sem assunto";
	texto = "mensagem vazia de conteudo";
}

Mensagem :: Mensagem(int cod_mensagem, string texto,string assunto,string anexo,string cod_destino,string cod_origem, string data_ini, string data_limite) 
{
	this->cod_mensagem = cod_mensagem;
	this->texto = texto;
	this->assunto = assunto;
	this->anexo = anexo;
	this->cod_destino= cod_destino;
	this->cod_origem = cod_origem;
	this->data_ini=data_ini;
	this->data_limite= data_limite;
}

Mensagem:: ~Mensagem(){}

Mensagem:: Mensagem(const Mensagem& other)
{
	this->cod_mensagem = other.cod_mensagem;
	this->texto = other.texto;
	this->assunto = other.assunto;
	this->anexo = other.anexo;
	this->cod_destino= other.cod_destino;
	this->cod_origem = other.cod_origem;
	this->data_ini=other.data_ini;
	this->data_limite= other.data_limite;
	
}
void Mensagem::listar(){
	cout<<"Remetente: "<<this->getCod_origem();
	cout<<"Assunto: "<<this->getAssunto()<<endl;
}


void Mensagem :: escreve(ostream &out) const
{
	out << "MENSAGEM" << endl
		<< "De: " << cod_origem << endl
		<< "Assunto: " << anexo << endl
		<< "Mensagem " << texto << endl;
}

ostream &operator << (ostream &out, const Mensagem &a)
{
	a.escreve(out);
	return out;
}
