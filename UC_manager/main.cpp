#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Bdados.h"
#include "Gestao.h"
#include "Eventos.h"
#include <string>
#include <conio.h>

using namespace std;


/*******************************************************************************************/
Gestao _gestao;
BDados *ligacao;
Pessoa* ut;
string cod_uc;
string cod_edicao;

void janelaUC();
void janelaLogin();
void janelaBV_Regente();
void janelaMensagens();
void janelaGerirConteudo();
void janelaDisciplina();
void janelaCaixaEntrada();
void janelaEnviarMensagem();
void janelaVisualizacao();
void janelaGerirEventos();
void janelaGerirAlunos();
void janelaAdicionarUC();
void janelaFecharUC();
void janelaGerirDocente();
void CarregaTeste();
void carregarAlunos();
void marcarReuniao();
void alterarLogin();
void janelaGerirEventosDocente();
void janelaAdicionarEventos();
void janelaMarcarAval();
void marcarConferencia();
void marcarCurso();
void marcarWorkshop();
void marcarAulaExtra();
void marcarTeste();
void marcarTP();
void marcarVisitaEstudo();
void CarregaTeste();
void carregarAlunos();
void marcarReuniao();
void alterarLogin();
void FechaUC();


/*******************************************************************************************/

int main(void)
{
	system("color 79");
	system("cls");
	janelaLogin();
	return 0;
}


void janelaLogin()
{
	cout << "############################" << endl;
	cout << "######## UC Manager ########" << endl;
	cout << "############################" << endl << endl;
	cout << "Digite nome de utilizador: ";
	string _user;
	string _pw;
	char c = ' ';
	cin >> _user;
	cout << endl << "Password: ";
	int StarNum = 0;
	cin >> _pw;
	string utilizador = "B6_5";
	string palavra = "xico";
	string bd = "193.136.62.27:1521/pdborcl"; //ou em vez de ip, gandalf   
	try {

		// cout << "Exemplo de ligacao: a ligar ..." << endl;
		ligacao = new BDados(utilizador, palavra, bd);
		//cout << "ligacao estabelecida" << endl;
		// cout << endl << endl << "Prima enter para continuar";
		//system("PAUSE");
		cin.get();


		ut = ligacao->login(_user, _pw);
		_gestao.setUser(ut);
		//_gestao.set_cod_user(ut->getCod_utilizador());
		string null = "";

		if (ut->getTipo() == 'D')
		{
			cout << endl << "Bem-vindo " << ut->getNome() << endl;
			cout << "Tipo de acesso: Docente" << endl << endl;
			system("Pause");
			janelaUC();
		}
		if (ut->getTipo() == 'R'){
			cout << endl << "Bem-vindo " << ut->getNome() << endl;
			cout << "Tipo de acesso: Regente" << endl << endl;
			system("Pause");
			janelaBV_Regente();
		}

		cout << "Login incorreto" << endl;
		system("Pause");
		system("cls");
		janelaLogin();
		delete ligacao;

	}
	catch (SQLException erro) {
		cerr << "Erro: " << erro.getMessage() << endl;
		system("pause");
	}


}


void janelaBV_Regente() //janela boas vindas
{
	system("cls");
	cout << "-----Bem-vindo-----" << endl << endl << "0-Sair da aplicacao" << endl <<
		"1-Entrar UC" << endl << "2-Adicionar UC" << endl << "3-Fechar UC" << endl << "4-Janela UC" << endl << "----------"
		<< endl << "m-Mensagens" << endl << endl << "A sua opcao: ";
	char opc;
	cin >> opc;
	switch (opc)
	{
	case '0':exit(0);
	case '1':janelaGerirConteudo();
	case '2':janelaAdicionarUC();
	case '3':janelaFecharUC();
	case '4':janelaUC();
	case 'm':janelaMensagens();
	default:cout << endl << ("Opcao incorreta!!!   ");
		system("pause");
		system("cls");
		janelaBV_Regente();
	}
}


void janelaGerirDocente() //s� acessivel pelo regente
{
	char opc;
	system("cls");
	cout << "-----Gerir Docente-----" << endl << endl << "0-Voltar" << endl <<
		"1-Adicionar Docente" << endl << "----------" << endl << "m-Mensagens" << endl << "A sua opcao: ";
	cin >> opc;
	switch (opc)
	{
	case '0':janelaGerirConteudo();
	case '1':_gestao.criarDocente(); janelaGerirDocente();
	case 'm':janelaMensagens();
	default: cout << endl << ("Opcao incorreta!!!   ");
		system("pause");
		system("cls");
		janelaGerirDocente();
	}
}

void janelaGerirAlunos() //s� acessivel pelo regente
{
	char opc;
	system("cls");
	cout << "-----Gerir Alunos-----" << endl << endl << "0-Voltar" << endl <<
		"1-Adicionar aluno" << endl << "2-Adicionar alunos" << endl << "----------" << endl << "m-Mensagens" << endl << "A sua opcao: ";
	cin >> opc;
	switch (opc)
	{
	case '0':janelaBV_Regente();
	case '1':_gestao.criarAluno();
	case '2':carregarAlunos();
	case 'm':janelaMensagens();
	default: cout << endl << ("Opcao incorreta!!!   ");
		system("pause");
		system("cls");
		janelaGerirAlunos();
	}
}



void janelaGerirEventos()
{
	char opc;
	system("cls");
	cout << "-----Gerir Eventos-----" << endl << endl << "0-Voltar" << endl <<
		"1-Alterar Eventos"  << endl << "2-Adicionar Eventos" << endl <<
		"----------" << endl << "m-Mensagens" << endl << "A sua opcao: ";

	cin >> opc;
	switch (opc)
	{
	case '0':janelaGerirConteudo();
	case '1':janelaAdicionarEventos();
	case '2':janelaAdicionarEventos();
	case 'm':janelaMensagens();
	default:cout << endl << ("Opcao incorreta!!!   ");
		system("pause");
		system("cls");
		janelaGerirEventos();
	}
}

void janelaAdicionarEventos()
{
	char opc;
	system("cls");
	cout << "-----Adicionar Eventos-----" << endl << endl << "0-Voltar" << endl <<
		"1-Marcar Reunioes" << endl << "2-Marcar cursos" << endl << "3-Marcar workshops " << endl << "4-Marcar conferencias"<<endl<<
		"5-Marcar aula extra" <<endl<<"----------" << endl << "m-Mensagens" << endl << "A sua opcao: ";

	cin >> opc;
	switch (opc)
	{
	case '0':janelaGerirEventos();
	case '1':marcarReuniao();
	case '2':marcarCurso();
	case '3':marcarWorkshop();
	case '4':marcarConferencia();
	case '5':marcarAulaExtra();
	case 'm':janelaMensagens();
	default:cout << endl << ("Opcao incorreta!!!   ");
		system("pause");
		system("cls");
		janelaGerirEventos();
	}
}

void janelaUC()
{
	char opc;
	system("cls");
	if (_gestao.getUser()->getTipo() == 'D'){
		cout << "-----Janela UC-----" << endl << endl << "0-Sair da aplicacao" << endl <<
			"1-Leccionadas" << endl << "2-Historico" <<endl<< "----------" << endl << "m-Mensagens" << endl << "A sua opcao: ";
		cin >> opc;
		switch (opc)
		{
		case '0':exit(0);
		case '1':janelaDisciplina();
		case '2':janelaVisualizacao();
		case 'm':janelaMensagens();
		default:cout << endl << ("Opcao incorreta!!!");
			system("pause");
			system("cls");
			janelaUC();
		}
	}
	else{
		cout << "-----Janela UC-----" << endl << endl << "0-Sair da aplicacao" << endl <<
			"1-Leccionadas" << endl << "2-Historico" << endl << endl <<"3-Janela BV Regente"<<endl<< "----------" << endl << "m-Mensagens" << endl << "A sua opcao: ";
		cin >> opc;
		switch (opc)
		{
		case '0':exit(0);
		case '1':janelaDisciplina();
		case '2':janelaVisualizacao();
		case '3':janelaBV_Regente();
		case 'm':janelaMensagens();
		default:cout << endl << ("Opcao incorreta!!!");
			system("pause");
			system("cls");
			janelaUC();
		}

	}
}


void janelaMensagens()
{
	char opc;
	system("cls");
	cout << "-----Mensagens-----" << endl << endl << "0-Voltar" << endl <<
		"1-Caixa de entrada" << endl << "2-Escrever mensagem" << endl << "A sua opcao: ";
	cin >> opc;
	switch (opc)
	{
	case '0':janelaUC();
	case '1':janelaCaixaEntrada();
	case '2':janelaEnviarMensagem();
	case 'm':janelaMensagens();
	default:cout << endl << ("Opcao incorreta!!!   ");
		system("pause");
		system("cls");
		janelaMensagens();
	}
}

void janelaDisciplina()
{
	char opc;
	system("cls");
	
	cout << "Escolha a disciplina" << endl;
	vector<UC*> cadeiras = ligacao->carregarUCs(_gestao.getUser()->getCod_utilizador());
	_gestao.ListarUC(cadeiras);
	cout << "Escolha UC : ";
	cin >> opc;
	int i = atoi(&opc);
	vector<UC*> ::iterator it = cadeiras.begin();
	i--;
	it += i;
	_gestao.setUc((*it)->clone());
	system("PAUSE");
	system("cls");
	cout << "-----Gestao Disciplina-----" << endl << endl << "0-Voltar" << endl <<
		"1-Marcar Avaliacao" << endl << "2-Publicar notas" << endl << "3-Visualizar notas" <<
		endl << "4-Escrever sumarios" << endl << "5-Visualizar Sumarios"
		<< endl << "6-Marcar aula extra" <<endl<<"7-Marcar workshops"<<endl<<"8-Marcar conferencias"<<
		endl<<"9-Marcar cursos"<<endl <<"10- Marcar visita de estudos"<< "----------" << endl <<"m-Mensagens" << endl << "A sua opcao: ";
	string _texto="";
	string _coduc="";
	string _coded="";
	string _coduti="";
	string _opc;
	cin >> opc;
	switch (opc)
	{
	case '0':janelaUC();
	case '1':janelaMarcarAval();
	case '2':CarregaTeste();
	case '3':;
	case '4':		
		system("cls");
		cout << "----Escrever sum�rio----" << endl;
		cout << "Texto (enter para terminar):";
		cin.ignore();
		getline(cin, _texto);

		cout << "Deseja enviar sum�rio?(s/n): ";
		cin >> _opc;
		if (_opc.compare("s") == 0)
		{
		//	_gestao.Uc()->adicionarSumario(_texto);
			cout << _texto << endl;
			system("PAUSE");
			_gestao.atualizarSumario(_texto, (*it)->Cod_uc(), (*it)->Edicao(), ut->getCod_utilizador() );
			cout << "Sum�rio adicionado" << endl;
			janelaDisciplina();

		}
		else{
			janelaDisciplina();
		}
		;
	case '5':
		(*it)->Sumarios(ligacao->carregarSumarios((*it)->Cod_uc(), (*it)->Edicao()));
		(*it)->visualizarSumario();
		system("PAUSE");
		janelaUC();
	case '6':marcarAulaExtra();
	case '7':marcarWorkshop();
	case '8':marcarConferencia();
	case '9':marcarCurso();
	case '10':marcarVisitaEstudo();
	case 'm':; janelaMensagens();
	default: cout << endl << ("Opcao incorreta!!!   ");
		system("pause");
		system("cls");
		janelaDisciplina();
	}
}

void janelaMarcarAval()
{
	system("cls");
	char opc;
	cout << "---- Marcar Avaliacao ----"<< endl << endl << "0-Voltar" << endl <<
		"1-Marcar Teste" << endl << "2-Marcar apresentacao de trabalho pratico" << endl << "----------" << endl 
		<< "m-Mensagens" << endl << "A sua opcao: ";
	cin >> opc;
	switch (opc)
	{
	case '0':janelaMarcarAval();
	case '1': marcarTeste();
	case '2':marcarTP();
	case 'm':janelaMensagens();
	default:cout << endl << ("Opcao incorreta!!!   ");
		system("pause");
		system("cls");
		janelaMensagens();
	}
}

void janelaVisualizacao()

{
	char opc;
	cout << "Escolha a disciplina" << endl;
	vector<UC*> cadeiras = ligacao->carregarUCs(_gestao.getUser()->getCod_utilizador());
	_gestao.ListarUC(cadeiras);
	cout << "Escolha UC : ";
	cin >> opc;
	int i = atoi(&opc);
	vector<UC*> ::iterator it = cadeiras.begin();
	i--;
	it += i;
	_gestao.setUc((*it)->clone());
	system("PAUSE");
	system("cls");
	system("cls");
	cout << "-----Visualizacao-----" << endl << endl << "0-Voltar" << endl <<
		"1-Visualizar notas" << endl << "2-Visualizar sumarios" << endl << "----------" << endl << "m-Mensagens" << endl << "A sua opcao: ";
	cin >> opc;
	switch (opc)
	{
	case '0':janelaUC();
	case '1':;
	case '2':
		(*it)->Sumarios(ligacao->carregarSumarios((*it)->Cod_uc(), (*it)->Edicao()));
		(*it)->visualizarSumario();
		system("PAUSE");
		janelaUC();
		;
	case 'm':janelaMensagens();
	default:cout << endl << ("Opcao incorreta!!!   ");
		system("pause");
		system("cls");
		janelaVisualizacao();
	}
}

void janelaCaixaEntrada() // caixa de entrada de mensagens

{
	int opc;
	system("cls");
	cout << "-----Caixa de entrada-----" << endl;
	_gestao.ListarMensagem(ut->getMsg());
	cout << endl << "Qual deseja ler ? (0 para voltar): ";
	cin >> opc;
	switch (opc)
	{
	case 0:janelaUC();
	case 'm':janelaMensagens();
	default:
		system("cls"); //metodo nao seguro, corrigir se possivel, pois caso o user utilize uma tecla que nao um numero ou "m" o programa n�o sabe o que fazer
		cout << ut->getMsg()[opc - 1] << endl;
	}

	system("PAUSE");
	janelaMensagens();
}

void janelaEnviarMensagem() // enviar mensagem (completo)
{
	string para;
	string mensagem;
	string assunto;
	string anexo;
	system("cls");
	cout << "-----Enviar mensagem-----" << endl;
	cout << "Para? ";
	cin >> para;
	cout << endl << "Assunto ";
	cin >> assunto;
	cout << endl << "Mensagem: ";
	cin >> mensagem;
	anexo = "l";
	while (anexo.compare("n") != 0 && anexo.compare("s") != 0)
	{
		cout << endl << "Deseja anexo? (s/n)";
		cin >> anexo;
	}
	bool an = false;
	if (anexo.compare("s") == 0)
	{
		an = true;
		cout << endl << "Nome anexo: ";
		cin >> anexo;
	}
	if (an) /// cria mensagem com anexo
	{
		try{
			ligacao->enviaMsgBD(ut->getCod_utilizador(), para, assunto, mensagem, anexo);
		}
		catch (int excp)
		{
			cout << "Mensagem n�o enviada, tente de novo" << endl;
			system("PAUSE");
			janelaCaixaEntrada();
		}
	}
	if (an == false) /// cria mensagem sem anexo
	{
		try{
			anexo = "Sem anexo";
			ligacao->enviaMsgBD(ut->getCod_utilizador(), para, assunto, mensagem, anexo);
		}
		catch (int excp)
		{
			cout << "Mensagem n�o enviada, tente de novo" << endl;
			system("PAUSE");
			janelaCaixaEntrada();
		}
	}
}

void alterarLogin()
{
	system("cls");
	string pw;
	cout << "introduza a sua nova password : ";
	cin >> pw;

	_gestao.alterarLogin(pw);
}
void marcarCurso()
{
	system("cls");
	string data_ini; string data_fim; string hora_ini; string hora_fim;
	string cod_uc, cod_evento, cod_edicao, cod_sala, cod_utilzador, n_docentes, descricao;
	cout << "----Marcar Curso----" << endl;
	cout << "Data de inicio(ano.mes.dia:hora:minutos): ";
	cin >> data_ini;
	data_ini + " " + hora_ini;
	cout << "Data de fim(ano.mes.dia:hora:minutos): ";
	cin >> data_fim;
	data_fim + " " + hora_fim;
	cout << "Codigo da sala?: ";
	cin >> cod_sala;
	_gestao.criarEvento(data_ini, data_fim, "Curso", 2, cod_sala, "na", "na", "na");
	janelaAdicionarEventos();
}

void marcarAulaExtra()
{
	system("cls");

	string data_ini; string data_fim; string hora_ini; string hora_fim;
	string cod_uc, cod_evento, cod_edicao, cod_sala, cod_utilzador, n_docentes, descricao;
	cout << "----Marcar Aula Extra----" << endl;

	char opc;
	cout << "Escolha a disciplina" << endl;
	vector<UC*> cadeiras = ligacao->carregarUCs(_gestao.getUser()->getCod_utilizador());
	_gestao.ListarUC(cadeiras);
	cout << "Escolha UC : ";
	cin >> opc;
	int i = atoi(&opc);
	vector<UC*> ::iterator it = cadeiras.begin();
	i--;
	it += i;
	_gestao.setUc((*it)->clone());
	cout << "Data de inicio(ano.mes.dia:hora:minutos): ";
	cin >> data_ini;
	data_ini + " " + hora_ini;
	cout << "Data de fim(ano.mes.dia:hora:minutos): ";
	cin >> data_fim;
	data_fim + " " + hora_fim;
	cout << "Codigo da sala?: ";
	cin >> cod_sala;
	_gestao.criarEvento(data_ini, data_fim, "Aula Extra", 2, cod_sala, ut->getCod_utilizador(), (*it)->Cod_uc(), (*it)->Edicao());
	janelaAdicionarEventos();
}

void marcarWorkshop()
{
	system("cls");
	string data_ini; string data_fim; string hora_ini; string hora_fim;
	string cod_uc, cod_evento, cod_edicao, cod_sala, cod_utilzador, n_docentes, descricao;
	cout << "----Marcar Workshop----" << endl;
	cout << "Data de inicio(ano.mes.dia:hora:minutos): ";
	cin >> data_ini;
	data_ini + " " + hora_ini;
	cout << "Data de fim(ano.mes.dia:hora:minutos): ";
	cin >> data_fim;
	data_fim + " " + hora_fim;
	cout << "Codigo da sala?: ";
	cin >> cod_sala;
	_gestao.criarEvento(data_ini, data_fim, "Workshop", 2, cod_sala, "na", "na", "na");
	janelaAdicionarEventos();
}

void marcarConferencia()
{
	system("cls");
	string data_ini; string data_fim; string hora_ini; string hora_fim;
	string cod_uc, cod_evento, cod_edicao, cod_sala, cod_utilzador, n_docentes, descricao;
	cout << "----Marcar Conferencia----" << endl;
	cout << "Data de inicio(ano.mes.dia:hora:minutos): ";
	cin >> data_ini;
	data_ini + " " + hora_ini;
	cout << "Data de fim(ano.mes.dia:hora:minutos): ";
	cin >> data_fim;
	data_fim + " " + hora_fim;
	cout << "Codigo da sala?: ";
	cin >> cod_sala;
	_gestao.criarEvento(data_ini, data_fim, "Workshop", 2, cod_sala, "na", "na", "na");
	janelaAdicionarEventos();
}

void marcarReuniao()
{
	system("cls");
	
	string data_ini; string data_fim; string hora_ini; string hora_fim;
	string cod_uc, cod_evento, cod_edicao, cod_sala, cod_utilzador, n_docentes, descricao;
	cout << "----Marcar Reuniao----" << endl;

	char opc;
	cout << "Escolha a disciplina" << endl;
	vector<UC*> cadeiras = ligacao->carregarUCs(_gestao.getUser()->getCod_utilizador());
	_gestao.ListarUC(cadeiras);
	cout << "Escolha UC : ";
	cin >> opc;
	int i = atoi(&opc);
	vector<UC*> ::iterator it = cadeiras.begin();
	i--;
	it += i;
	_gestao.setUc((*it)->clone());

	cout << "Data de inicio(ano.mes.dia:hora:minutos): ";
	cin >> data_ini;
	data_ini + " " + hora_ini;
	cout << "Data de fim(ano.mes.dia:hora:minutos): ";
	cin >> data_fim;
	data_fim + " " + hora_fim;
	cout << "Codigo da sala?: ";
	cin >> cod_sala;
	_gestao.criarEvento(data_ini, data_fim, "Reuniao", 2, cod_sala, ut->getCod_utilizador(), (*it)->Cod_uc(), (*it)->Edicao());
	janelaAdicionarEventos();

}

void carregarAlunos()
{
	string caminho;
	cout << "introduza o caminho do ficheiro de Alunos : ";
	cin.ignore();
	getline(cin,caminho);
	_gestao.LerAlunos(caminho);
}
void CarregaTeste()
{
	string mom;
	string fx;
	cout << "insira o momento de avaliacao(ex.:T1) : ";
	cin >> mom;
	Avaliacao a = _gestao.getAval(mom,cod_uc,cod_edicao);
	if(a.getTipo() == "")
	{
		cout << "Momento de avaliacao inexistente";
		system("PAUSE");
		CarregaTeste();
	}
	
	cout << "insira o nome do ficheiro";cin>>fx;
	_gestao.LerTeste(fx,a);
}

void marcarTeste()
{
	system("cls");

	string cod_aval; string tipo; string cod_uc; int cod_edicao; string data_realizada;
	cout << "----Marcar Teste----" << endl;

	char opc;
	cout << "Escolha a disciplina" << endl;
	vector<UC*> cadeiras = ligacao->carregarUCs(_gestao.getUser()->getCod_utilizador());
	_gestao.ListarUC(cadeiras);
	cout << "Escolha UC : ";
	cin >> opc;
	int i = atoi(&opc);
	vector<UC*> ::iterator it = cadeiras.begin();
	i--;
	it += i;
	_gestao.setUc((*it)->clone());
	cout << "insira o momento de avaliacao(ex.:T1) : ";
	cin >> tipo;
	cout << "Data de realizacao(ano.mes.dia:hora:minutos): ";
	cin >> data_realizada;
	_gestao.marcarAval(cod_aval, tipo, (*it)->Cod_uc(), (*it)->Edicao(), data_realizada);
	janelaMarcarAval();
}

void marcarTP()
{
	system("cls");

	string cod_aval; string tipo; string cod_uc; int cod_edicao; string data_realizada;
	cout << "----Marcar trabalho pratico----" << endl;

	char opc;
	cout << "Escolha a disciplina" << endl;
	vector<UC*> cadeiras = ligacao->carregarUCs(_gestao.getUser()->getCod_utilizador());
	_gestao.ListarUC(cadeiras);
	cout << "Escolha UC : ";
	cin >> opc;
	int i = atoi(&opc);
	vector<UC*> ::iterator it = cadeiras.begin();
	i--;
	it += i;
	_gestao.setUc((*it)->clone());
	cout << "Data de realizacao(ano.mes.dia:hora:minutos): ";
	cin >> data_realizada;
	_gestao.marcarAval(cod_aval, tipo, (*it)->Cod_uc(), (*it)->Edicao(), data_realizada);
	janelaMarcarAval();
}
void marcarVisitaEstudo()
{
	system("cls");

	string data_ini; string data_fim; string hora_ini; string hora_fim;
	string cod_uc, cod_evento, cod_edicao, cod_sala, cod_utilzador, n_docentes, descricao;
	cout << "----Marcar visita de estudo----" << endl;

	char opc;
	cout << "Escolha a disciplina" << endl;
	vector<UC*> cadeiras = ligacao->carregarUCs(_gestao.getUser()->getCod_utilizador());
	_gestao.ListarUC(cadeiras);
	cout << "Escolha UC : ";
	cin >> opc;
	int i = atoi(&opc);
	vector<UC*> ::iterator it = cadeiras.begin();
	i--;
	it += i;
	_gestao.setUc((*it)->clone());

	cout << "Data de inicio(ano.mes.dia:hora:minutos): ";
	cin >> data_ini;
	data_ini + " " + hora_ini;
	cout << "Data de fim(ano.mes.dia:hora:minutos): ";
	cin >> data_fim;
	data_fim + " " + hora_fim;
	_gestao.criarEvento(data_ini, data_fim, "Visita de estudo", 2, cod_sala, ut->getCod_utilizador(), (*it)->Cod_uc(), (*it)->Edicao());
	janelaAdicionarEventos();
}




void criaFich()
{
	char opc;
	cout << "Escolha a disciplina" << endl;
	vector<UC*> cadeiras = ligacao->carregarUCs(_gestao.getUser()->getCod_utilizador());
	_gestao.ListarUC(cadeiras);
	cout << "Escolha UC : ";
	cin >> opc;
	int i = atoi(&opc);
	vector<UC*> ::iterator it = cadeiras.begin();
	i--;
	it += i;
	_gestao.setUc((*it)->clone());
	string nome = (*it)->Cod_uc()+"_"+(*it)->Edicao();
	_gestao.criarFich();

}




void FechaUC()
{
	string a;
	cout << "selecione a UC a Fechar" << endl;
	vector<UC*> ucs=ligacao->carregarUCs(ut->getCod_utilizador());
	_gestao.ListarUC(ucs);
	cin >> a;
	int i = stoi(a);
	vector<UC*> ::iterator it = ucs.begin();
	i--;
	it += i;
	cod_uc = (*it)->Cod_uc();cod_edicao=(*it)->Edicao();
	_gestao.fecharUC(cod_uc,cod_edicao);


}

void janelaAdicionarUC() //janela adiciona UC
{
	system("cls");
	cout << "-----Adicionar UC-----" << endl << endl << "0-Voltar" << endl
		<< endl << "m-Mensagens" << endl;
	_gestao.criarUC();
	janelaBV_Regente();
}

void janelaFecharUC() //janela adiciona UC
{
	system("cls");
	cout << "-----Fechar UC-----" << endl << endl << "0-Voltar" << endl
		<< endl << "m-Mensagens" << endl;
	char opc;
	cin >> opc;
	switch (opc)
	{
	case '0':janelaBV_Regente();
	case 'm':janelaMensagens();
	default:cout << endl << ("Opcao incorreta!!!   ");
		system("pause");
		system("cls");
		janelaFecharUC();
	}
}
void janelaGerirConteudo() //s� acessivel pelo regente
{
	char opc;
	system("cls");
	cout << "-----Gerir Conteudos-----" << endl << endl << "0-Voltar" << endl <<
		"1-Gerir Eventos" << endl << "2-Gerir Docentes" << endl << "3-Gerir UC" << endl
		<< "4-Gerir Alunos" << endl << "----------" << endl << "m-Mensagens" << endl << "A sua opcao: ";
	cin >> opc;
	switch (opc)
	{
	case '0':janelaBV_Regente();
	case '1':janelaGerirEventos();
	case '2':janelaGerirDocente();
	case '3':janelaGerirConteudo(); // confirmar que � esta janela n�o tenho certeza
	case '4':janelaGerirAlunos();
	case 'm':janelaMensagens();
	default: cout << endl << ("Opcao incorreta!!!   ");
		system("pause");
		system("cls");
		janelaGerirConteudo();
	}
}








