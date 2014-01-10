//
//  Mensagem.h
//  Afonso Reis 
using namespace std;

class Mensagem
{
private:
	string emissor;
	string cod_origem;
	string texto;
	string assunto;
	string anexo; //URL do anexo
	string cod_destino;
	string data_envio;
	string data_leitura;


public:
	Mensagem();
	Mensagem(int cod_mensagem, string texto,string assunto,string anexo,string cod_destino,string cod_origem, string data_ini, string data_limite);
	Mensagem(string cod_origem, string assunto, string mensagem, string data_envio, string cod_ficheiro);
	~Mensagem();
	Mensagem(const Mensagem& other);
	void escreve(ostream &out) const;
	//  void escreve(); 

	string getEmissor() const { return emissor; }
	void setEmissor(int val) { emissor = val; }
	string getTexto() const { return texto; }
	void setTexto(string val) { texto = val; }
	string getAssunto() const { return assunto; }
	void setAssunto(string val) { assunto = val; }
	string getAnexo() const { return anexo; }
	void setAnexo(string val) { anexo = val; }
	string getCod_destino() const { return cod_destino; }
	void setCod_destino(string val) { cod_destino = val; }
	string getData_ini() const { return data_envio; }
	void setData_ini(string val) { data_envio = val; }
	string getData_limite() const { return data_leitura; }
	void setData_limite(string val) { data_leitura = val; }
	void listar();
};

Mensagem :: Mensagem() 
{
	assunto = "sem assunto";
	texto = "mensagem vazia de conteudo";
}

Mensagem :: Mensagem(int cod_mensagem, string texto,string assunto,string anexo,string cod_destino,string cod_origem, string data_ini, string data_limite) 
{
	this->emissor = cod_mensagem;
	this->texto = texto;
	this->assunto = assunto;
	this->anexo = anexo;
	this->cod_destino= cod_destino;

	this->data_envio=data_ini;
	this->data_leitura= data_limite;
}

Mensagem:: ~Mensagem(){}

Mensagem::Mensagem(string cod_origem, string assunto, string mensagem, string data_envio, string cod_ficheiro){
	this->emissor = cod_origem;
	this->assunto = assunto;
	this->texto = mensagem;
	this->data_envio = data_envio;
	this->anexo = cod_ficheiro;
}

Mensagem:: Mensagem(const Mensagem& other)
{
	this->emissor = other.emissor;
	this->texto = other.texto;
	this->assunto = other.assunto;
	this->anexo = other.anexo;
	this->cod_destino= other.cod_destino;

	this->data_envio=other.data_envio;
	this->data_leitura= other.data_leitura;
	
}
void Mensagem::listar(){
	cout << "Remetente: " << emissor << "	|	";
	cout<<"Assunto: "<<assunto<<endl;
}


void Mensagem :: escreve(ostream &out) const
{
	out << "MENSAGEM" << endl
		<< "De: " << getEmissor()<< endl
		<< "Assunto: " << getAssunto() << endl
		<< "Mensagem " << getTexto() << endl;
}

ostream &operator << (ostream &out, const Mensagem &a)
{
	a.escreve(out);
	return out;
}
