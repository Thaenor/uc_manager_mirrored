#ifndef Gestao_
#define Gestao_

#include <fstream>
#include "UC.h"
#include <algorithm>
#include <stdexcept>
//#include "up_and_down.h"
#include "Avaliacao.h"
#include "Sala.h"

string app_key = "54lc1hrozp8u01k";
string app_secret = "8tuyvtv4y2dg072";
string token =  "304pyo06bbqdhtr1";
string token_secret = "hn4qk5vmeusmaes";
//#include <list>
using namespace std;

class Gestao
{
private:

	Pessoa * user;
	UC* uc;
	string cod_user;
	string cod_edicao;
	string cod_uc;
	

	void destroy();

public:
	//Construtor e destrutor
	Gestao();
	Gestao(Pessoa * user, UC * uc);
	Gestao(const Gestao &g);
	~Gestao();


	//sets/gets
	void setUser(Pessoa * user);
	Pessoa * getUser();
	//metodo ordenar
	void ListarTeste(vector<Aluno> al);
	void ListarMensagem(vector<Mensagem> ms);

	//ligacao
	BDados* ligar();

	void setUc(UC* val) { 
		this->uc = val;
		 }

	void setcod_uc(string cod, string edicao)
	{
		cod_uc = cod;
		cod_edicao = edicao;
	}
	void set_cod_user(string cod){ cod_user = cod; }

	string get_cod_uc(){ return cod_uc; }
	string get_cod_edicao(){ return cod_edicao; }
	string get_user(){ return cod_user; }
	//leitura Teste
	vector<Aluno> LerTeste(string fich,Avaliacao desc);
	double calcAlineas(vector<double> notas, vector<double> cota);

	void ListarUC(vector<UC*> cadeiras);

	Avaliacao getAval(string mom);

	//leitura de docentes
	vector<Pessoa*> lerDocentes(string fich);

	void printPessoa(vector<Pessoa*> vec);

	//leitura Alunos
	vector<Pessoa*> LerAlunos(string fich);

	//criar aluno
	void criarAluno();

	//Criar docente
	void criarDocente();

	//criar uc
	void criarUC();

	//alterar Login
	void alterarLogin(string pw);

	UC * Uc() const { return uc; }
	void Uc(UC * val) { uc = val; }
	void atualizarSumario(string texto, string ed, string cod, string codq);
};

//construtor e destrutor
Gestao::Gestao()
{
}

Gestao::Gestao(Pessoa * _user, UC * _uc)
{	
	user = _user;
	uc = _uc;
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

void Gestao::ListarMensagem(vector<Mensagem> ms)
{
	vector<Mensagem>::iterator it;
	int c = 1;
	for (it = ms.begin(); it != ms.end(); it++) {
		cout << "-"<<c<<"-	" ;
		it->listar() ;
		c++;

	}
}

void Gestao::ListarUC(vector<UC*> cadeiras)
{
	vector<UC*>::iterator it;
	int c = 1;
	for (it = cadeiras.begin(); it != cadeiras.end(); it++) {
		cout << "-" << c << "-	";
		(*it)->listar();
		c++;

	}
}
void Gestao :: setUser(Pessoa * _user)
{
	this->user = _user;
}

Pessoa * Gestao :: getUser()
{
	return this->user;
}



vector<Aluno> Gestao::LerTeste(string fich,Avaliacao aval)
{
	int inic = 0;
	string linha;
	ifstream fx;
	BDados *ligacao = ligar();

	string caminho = "D:\Dropbox\Aplicativos\UC_Manager_Link";
	caminho +=fich;
	//dados importados
	vector<double> cotacoes;
	list<double> notas;
	vector<int> numeros;
	vector<Aluno> alunos;
	int n_al;
	int num;

	fx.open(caminho);
	if (!fx)
	{
		cout << "Ficheiro de Teste nao existe !" << endl;

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
		
		ligacao->regAval_Notas(*it, nota[0], aval);
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
	
	string caminho = "D:\Dropbox\Aplicativos\UC_Manager_Link";
	caminho +=fich;

	//dropfuncs::dropbox::isep_credentials(app_key,app_secret,token,token_secret);						 
	//dropfuncs::dropbox::isep_down(fich, fich, false);

	BDados *ligacao = ligar();

	fx.open(fich);
	if (!fx)
	{
		cout << "Ficheiro de Docentes nao existe !" << endl;

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
			Utilizador * p = new Utilizador(nome, sigla, 'D');
			ligacao->regDocente(p);
			users.push_back(p);		

		}
	}
	//printPessoa(users);//tirar se nao funcionar
	return users;
}

void Gestao::printPessoa(vector<Pessoa*> t)
{
	vector<Pessoa*>::const_iterator it;
	if (strcmp(&(typeid(**it).name())[0], &("class Utilizador")[0]) == 0){
		for (it = t.begin(); it != t.end(); it++) {

			cout << "Sigla: " << (**it).getCod_utilizador() << " Nome: " << (**it).getNome() << "\n";
		}
	}
	if (strcmp(&(typeid(**it).name())[0], &("class Aluno")[0]) == 0)
	{
		for (it = t.begin(); it != t.end(); it++) {

			cout << "Numero: " << (**it).getNumero() << " Nome: " << (**it).getNome() << "\n";
		}
	}
}

vector<Pessoa*> Gestao::LerAlunos(string fich)
{
	int inic = 0;
	string linha;
	ifstream fx;
	string caminho = "D:/Dropbox/Aplicativos/UC_Manager_Link/";
	caminho +=fich;
	//dropfuncs::dropbox::isep_credentials(app_key,app_secret,token,token_secret);		
	//dropfuncs::dropbox::isep_up("hello1.txt", false);
	//			 
	//dropfuncs::dropbox::isep_down(fich, fich, false);

	BDados *ligacao = ligar();

	fx.open(caminho);
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
			string numero(linha.substr(inic, pos - inic));
			int num = stoi(numero);
			pos++;
			inic = pos;
			string nome(linha.substr(inic, linha.size()));
			Aluno * p = new Aluno(nome, num);
			ligacao->regAluno(p);
			users.push_back(p);


		}
	}
	//printPessoa(users);
	return users;
}

void Gestao :: criarAluno()
{
	
	BDados *ligacao = ligar();

	string  nome;int numero;
	vector<double> notas;
	system("cls");
	cout << "introduza o nome : ";
	cin.ignore();
	getline(std::cin,nome);
	cout << "\n";
	cout << "\nintroduza o numero (0 - para gerar automaticamente): ";
	cin >> numero;

	if (!ligacao->jaExisteAluno(numero))
	{
		Aluno a(nome,numero,notas);
		ligacao->regAluno(&a);
	}
	else
	{
		cout << "O numero de aluno fornecido ja existe!!!";
		criarAluno();
	}
	delete ligacao;

}
void Gestao :: criarDocente()
{
	BDados *ligacao = ligar();

	string  nome;string sigla;
	vector<double> notas;
	system("cls");
	cout << "introduza o nome : ";
	cin.ignore();
	getline(cin,nome);
	cout << "\nintroduza a sigla : ";
	getline(cin,sigla);

	if (!ligacao->jaExisteDocente(sigla))
	{
		Utilizador u(nome,sigla,'D');
		ligacao->regDocente(&u);
	}
	else
	{
		cout << "A sigla de docente fornecido ja existe!!!";
		criarDocente();
	}
	cout << "Docente criado com sucesso..." << endl,
	system("pause");
	delete ligacao;

}

void Gestao :: criarUC()
{
	BDados *ligacao = ligar();

	string regente; string cod_uc; string nome; string edicao; string ano;string semestre	;
	system("cls");
	cout << "introduza o nome : ";
	cin.ignore();
	getline(cin,nome);
	cout << "\nintroduza a sigla : ";
	getline(cin,cod_uc);
	cout << "\nintroduza a edicao : ";
	getline(cin,edicao);
	cout << "\nintroduza o ano : ";
	getline(cin,ano);
	cout << "\nSemestre : ";
	getline(cin, semestre);
	cout << "\nSigla do regente : ";
	getline(cin, regente);

	//regente = user->getCod_utilizador; é feito atraves de um trigger na bdd

	if (!ligacao->jaExisteCadeira(cod_uc))
	{
		UC uc(regente, cod_uc, nome, edicao, ano, semestre);
		ligacao->registarUC(&uc);
	}
	else
	{
		cout << "Codigo UC já existe!";
		criarUC();
	}
	delete ligacao;

}

void Gestao::atualizarSumario(string texto, string ed, string cod, string codq)

{
	BDados* bd = ligar();
	bd->addSumario(ed,cod , user->getCod_utilizador(), texto);//era suposto passar o *uc mas nao foi possivel implementar
}


BDados* Gestao :: ligar()
{
	string utilizador = "B6_5";
	string palavra = "xico";
	string bd = "193.136.62.27:1521/pdborcl";
	BDados *ligacao = new BDados(utilizador, palavra, bd);
	return ligacao;
}

void Gestao :: alterarLogin(string pw)
{
	BDados *ligacao = ligar();
	ligacao->alterarLogin(user, pw);

}

Avaliacao Gestao :: getAval(string mom)
{
		BDados *ligacao = ligar();
		return ligacao->getAval(*uc,mom);

}
				

#endif
