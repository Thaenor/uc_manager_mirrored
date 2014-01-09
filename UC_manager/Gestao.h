#ifndef Gestao_
#define Gestao_

#include <fstream>
#include "Utilizador.h"
//#include <list>
using namespace std;

class Gestao
{
private:

	void destroy();

public:
	//Construtor e destrutor
	Gestao();
	Gestao(const Gestao &g);
	~Gestao();
	//metodo ordenar
	static void ListarTeste(vector<Aluno> al);

	//leitura Teste
	static vector<Aluno> LerTeste(string fich);
	static double calcAlineas(vector<double> notas, vector<double> cota);

	//leitra de docentes
	static vector<Pessoa*> lerDocentes(string fich);
	static void printDoc(vector<Pessoa*> vec);


};

//construtor e destrutor
Gestao::Gestao()
{
}

Gestao::Gestao(const Gestao &g){

}
Gestao::~Gestao(){}

void Gestao::ListarTeste(vector<Aluno> t)
{
	vector<Aluno>::iterator it;

	for (it = t.begin(); it != t.end(); it++) {

		cout << "Numero: " << it->getNumero() <<" Nota: " << (it->getNotas())[0] << "\n";

	}
}


vector<Aluno> Gestao::LerTeste(string fich)
{
	int inic = 0;
	string linha;
	ifstream fx;

	//dados importados
	vector<double> cotacoes;
	list<double> notas;
	vector<int> numeros;
	vector<Aluno> alunos;
	int n_al;
	int num;


	fx.open(fich);
	if (!fx)
	{
		cout << "Ficheiro de Alunos nao existe !" << endl;

	}

	//cotacoes por alinea
	getline(fx, linha, '\n');

	if (linha.size() > 0)
	{
		int	pos = linha.find(';', inic);
		string numero_alineas(linha.substr(inic, pos - inic));
		n_al = stof(numero_alineas);

		for (int i = 0; i < n_al; i++)
		{
			pos++;
			inic = pos;
			pos = linha.find(';', inic);
			string al(linha.substr(inic, pos - inic));
			cotacoes.push_back(stof(al));
		}

	}

	//numero e notas aluno
	while (!fx.eof())
	{
		getline(fx, linha, '\n');
		inic = 0;
		if (linha.size() > 0)
		{
			int	pos = linha.find(';', inic);
			string numero(linha.substr(inic, pos - inic));
			num = stoi(numero);
			numeros.push_back(num);
			for (int i = 0; i < n_al; i++)
			{
				pos++;
				inic = pos;
				pos = linha.find(';', inic);
				string nota(linha.substr(inic, pos - inic));
				double n = std::stod(nota);
				notas.push_back(n);
			}

		}
	}

	for (vector<int> ::iterator it = numeros.begin(); it != numeros.end(); it++)
	{
		vector<double> n;

		for (int i = 0; i < n_al; i++)
		{
			n.push_back(notas.front());
			notas.pop_front();
		}
		vector<double> nota;
		nota.push_back(calcAlineas(n, cotacoes));

		alunos.push_back(Aluno(*it, nota));
	}
	ListarTeste(alunos);
	return alunos;
}

double Gestao::calcAlineas(vector<double> notas, vector<double> cota)
{
	double nota=0; double a, b; double aux;
	vector<double> ::iterator itn = notas.begin();
	vector<double> ::iterator itc = cota.begin();
	for (int i = 0; i < notas.size(); i++)
	{
		a = *(itn + i);
		b = *(itc + i);
		aux = a*b;
		nota += aux;
	}
	return nota;
}

vector<Pessoa*> Gestao::lerDocentes(string fich)
{
	int inic = 0;
	string linha;
	ifstream fx;

	fx.open(fich);
	if (!fx)
	{
		cout << "Ficheiro de Alunos nao existe !" << endl;

	}
	
	vector <Pessoa*> users;
	while (!fx.eof())
	{
		inic = 0;
		getline(fx, linha, '\n');
		if (linha.size() > 0)
		{
			int	pos = linha.find(';', inic);
			string sigla(linha.substr(inic, pos - inic));
			pos++;
			inic = pos;
			string nome(linha.substr(inic, linha.size()));
			Utilizador * p = new Utilizador(nome, sigla);
			users.push_back(p);
			

		}
	}
	printDoc(users);
	return users;
}

void Gestao::printDoc(vector<Pessoa*> t)
{
	vector<Pessoa*>::iterator it;

	for (it = t.begin(); it != t.end(); it++) {

		cout << "Sigla: " << (**it).getCod_utilizador() << " Nome: " << (**it).getNome()<< "\n";

	}
}
#endif
