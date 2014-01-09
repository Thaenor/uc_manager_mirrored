#ifndef Gestao_
#define Gestao_

#include <fstream>
#include "Aluno.h"
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
	void ListarVectores(vector<Aluno> al);

	//leitura Teste
	vector<Aluno> LerTeste(string fich);
};

//construtor e destrutor
Gestao::Gestao()
{
}

Gestao::Gestao(const Gestao &g){

}
Gestao::~Gestao(){}

void Gestao::ListarVectores(vector<Aluno> t)
{
	vector<Aluno>::const_iterator it;

	for (it = t.begin(); it != t.end(); it++) {

		cout << "Nome: " << *it << "\n";

	}
}


vector<Aluno> Gestao::LerTeste(string fich)
{
	int inic = 0;
	string linha;
	fstream fx;

	//dados importados
	vector<float> cotacoes;
	list<float> notas;
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
				float n = stof(nota);
				notas.push_back(n);
			}

		}
	}

	for (vector<int> ::iterator it = numeros.begin(); it != numeros.end(); it++)
	{
		vector<float> n;

		for (int i = 0; i < n_al; i++)
		{
			n.push_back(notas.front());
			notas.pop_front();
		}
		vector<float> nota;
		nota.push_back(calcAlineas(n, cotacoes));

		alunos.push_back(Aluno(*it, nota));
	}
	ListarVectores(alunos);
	return alunos;
}

float calcAlineas(vector<float> notas, vector<float> cota)
{
	float nota;
	vector<float> ::iterator itn = notas.begin();
	vector<float> ::iterator itc = cota.begin();
	for (int i = 0; i < notas.size(); i++)
	{
		nota += (*(itn + i)) * (*(itc + i));
	}
	return nota;
}
#endif
