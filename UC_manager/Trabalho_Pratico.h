//// Afonso Reis
/// Trabalho_Pratico.h
//////////////////////////////////////////////////////////////////////////

#include <list>
using namespace std;
#include "Sala.h"
class Trabalho_Pratico
{
private:
	int cod_trabalho_pratico;
	list <Sala> salas;
	int cod_utilizador;
	list<string> cod_utilizadores;
	int docentes_sala;

public:
	Trabalho_Pratico();
	Trabalho_Pratico(int cod_trabalho_pratico, list <Sala> salas, int cod_utilizador, list<string> cod_utilizadores, int docentes_sala);
	~Trabalho_Pratico();
	Trabalho_Pratico(const Trabalho_Pratico &other);
	void escreve(ostream &out) const;

	//	int getCod_trabalho_pratico() const { return cod_trabalho_pratico; }
	void setCod_trabalho_pratico(int val) { cod_trabalho_pratico = val; }
	list<Sala> getSalas() const { return salas; }
	void setSalas(list<Sala> val) { salas = val; }
	int getCod_utilizador() const { return cod_utilizador; }
	void setCod_utilizador(int val) { cod_utilizador = val; }
	list<string> getCod_utilizadores() const { return cod_utilizadores; }
	void setCod_utilizadores(list<string> val) { cod_utilizadores = val; }
	int getDocentes_sala() const { return docentes_sala; }
	void setDocentes_sala(int val) { docentes_sala = val; }

};

Trabalho_Pratico::Trabalho_Pratico()
{

}

Trabalho_Pratico::Trabalho_Pratico(int cod_trabalho_pratico, list <Sala> salas, int cod_utilizador, list<string> cod_utilizadores, int docentes_sala)
{
	//this->cod_trabalho_pratico =cod_trabalho_pratico;
	this->salas = salas;
	this->cod_utilizador = cod_utilizador;
	this->cod_utilizadores = cod_utilizadores;
	this->docentes_sala = docentes_sala;
}

Trabalho_Pratico :: ~Trabalho_Pratico(){};

Trabalho_Pratico::Trabalho_Pratico(const Trabalho_Pratico &other)
{
	this->cod_trabalho_pratico = other.getCod_utilizadores();
	this->salas = other.getSalas();
	this->cod_utilizador = other.getCod_utilizador();
	this->cod_utilizadores = other.getCod_utilizadores();
	this->docentes_sala = other.getDocentes_sala();
}

void Trabalho_Pratico::escreve(ostream &out)const
{

	out << "Código de trabalho prático: " << cod_trabalho_pratico << endl
		<< "Salas: " << salas << endl
		<< "Docentes por sala :" << docentes_sala << endl;
}


ostream &operator << (ostream &out, const Trabalho_Pratico &a)
{
	a.escreve(out);
	return out;
}