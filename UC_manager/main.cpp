#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include"Pessoa.h"
#include"Bdados.h"
#include"Aluno.h"
#include "Gestao.h"
using namespace std;    
/*******************************************************************************************/
/*******************************************************************************************/
/*******************************************************************************************/

void janelaLogin();
void janelaBV_Regente();
void janelaMensagens();
void janelaGerirConteudo();
void janelaDisciplina();
void janelaCaixaEntrada();
void janelaEnviarMensagem();
void janelaVisualizacao();
void janelaGerirEventos();

int main(void)
{
	system( "color 79" );
	cout << "Development test area!" << endl;


	cout << endl;
	/////////////////////////BDADODS
	cout << "*****"<<endl;
	Gestao ::lerDocentes("C:/Users/d4rk_sou1/Desktop/uc_manager/UC_manager/exemplo_Docentes.csv");
	cin.get();
	string utilizador = "B6_5";
	string palavra = "xico";
	string bd = "193.136.62.27:1521/pdborcl"; //ou em vez de ip, gandalf   
	try {
		cout << "Exemplo de ligacao: a ligar ..." << endl;
		BDados *ligacao = new BDados(utilizador, palavra, bd);
		cout << "ligacao estabelecida" << endl;
		cout << endl << endl << "Prima enter para continuar" ;
		system("PAUSE");
		//cin >> cont;
		delete ligacao;

	}
	catch (SQLException erro) {
		cerr << "Erro: " << erro.getMessage() << endl;
	}
	system("cls");
	janelaLogin();
	return 0;
}
	 
	 void janelaLogin()
	 {
		 cout << "######## UC Manager ########" << endl << endl;
		 cout << "Digite nome de utilizador: ";
		 string _user;
		 string _pw;
		 cin  >> _user;
		 cout << endl << "Password: ";
		 cin >> _pw;

		janelaBV_Regente();
	 }

	 void janelaBV_Regente() //janela boas vindas
	 {
		 system("cls");
		 cout << "-----Bem-vindo-----" << endl << endl <<
			 "1-Entrar UC" << endl << "2-Adicionar UC" << endl << "3-Remover UC"<<endl <<"----------" 
			 <<endl <<"m-Mensagens"<< endl << endl << "A sua opcao:" << endl;
		 char opc;
		 cin >> opc;
		 switch (opc)
		 {			 
			 case '1':janelaGerirConteudo();
			 case '2':
			 case '3':
			 case 'm':janelaMensagens();
			default: janelaGerirConteudo();	 

		 }

	 }

	 void janelaGerirConteudo()
	 {
		 char opc;
		 system("cls");
		 cout << "-----Gerir Conteudos-----" << endl << endl << "0-Voltar" << endl <<
			 "1-Gerir Eventos" << endl << "2-Gerir Docentes" << endl << "3-Gerir UC" << endl << "4-Gerir Alunos" << endl << "A sua opcao: " << endl;
		 cin >> opc;
		 switch (opc)
		 {	
			 case '0':janelaBV_Regente();
			 case '1':janelaGerirEventos();
			 case '2'://janelaGerirDocentes()/ 
				 ;
			 case '3':
			 case '4':
			 case 'm':janelaMensagens();
			 default: janelaGerirConteudo();
		 }
	 }

		 void janelaGerirEventos()
		 {
			 char opc;
			 system("cls");
			 cout << "-----Gerir Eventos-----" << endl << endl << "0-Voltar" << endl <<
				 "1-Alterar" << endl << "2-Remover" << endl << "3-Adicionar" << endl << "A sua opcao: " << endl;
			 
			cin >> opc;
		 switch (opc)
		 {	
			case '0':janelaGerirConteudo();
			 case '1':janelaGerirEventos();
			 case '2'://janelaGerirDocentes()/ 
				 ;
			 case '3':
			 case '4':
			 case 'm':janelaMensagens();
			 default: janelaGerirEventos();
		 }
		}

		 void janelaUC()
		 {
			 char opc;
			 system("cls");
			 cout << "-----Janela UC-----" << endl << endl << "0-Voltar" << endl <<
				 "1-Leccionadas" << endl << "2-Permissoes/Historico" << endl;
			 cin >> opc;
		 switch (opc)
		 {	
			case '0':janelaUC();
			case '1':janelaDisciplina();
			case '2':janelaVisualizacao();
			case '3':;
			case '4':;
			case 'm':janelaMensagens();
			 default: janelaUC();
		 }
		 }
		 void janelaMensagens()
		 {
			 char opc;
			 system("cls");
			 cout << "-----Mensagens-----" << endl << endl << "0-Voltar" << endl <<
				 "1-Caixa de entrada" << endl << "2-Escrever mensagem" << endl << "A sua opcao: " << endl;
			 cin >> opc;
			 switch (opc)
			 {	
				case '0':janelaUC();
				case '1':janelaCaixaEntrada();
				case '2':cout << "entrou"; janelaEnviarMensagem();
			 case '3':;
			 case '4':;
			 case 'm':janelaMensagens();
			 default: janelaMensagens();
		 }
		 }
		 
		 void janelaDisciplina()
		 {
			 char opc;
			 system("cls");
			 cout << "-----Gestão Disciplina-----" << endl << endl << "0-Voltar" << endl <<
				 "1-Marcar Avaliacao" << endl << "2-Publicar notas" << endl << "3-Visualizar notas" << endl << "4-Escrever sumarios" << endl  << "5-Visualizar Sumarios" 
				 << endl << "6-Marcar aula extra" <<endl<< "7-Histórico"<<endl<< "A sua opcao: " << endl;
			 cin >> opc;
		 switch (opc)
		 {	
			 case '0':;
			 case '1':;
			 case '2':;
			 case '3':;
			 case '4':;
			 case 'm':;
			 default: janelaUC();
		 }
		 }

		 void janelaVisualizacao()

		 {
			 char opc;
			 system("cls");
			 cout << "-----Visualizacao-----" << endl << endl << "0-Voltar" << endl <<
				 "1-Visualizar notas" << endl << "2-Visualizar sumarios" << endl << "A sua opcao: " << endl;
			 cin >> opc;
		 switch (opc)
		 {	
			 case '0':janelaUC();
			 case '1':;
			 case '2':;
			 case '3':;
			 case '4':;
			 case 'm':janelaMensagens();
			 default: janelaVisualizacao();
		 }
		 }

		 void janelaCaixaEntrada() // caixa de entrada de mensagens

		 {
			 char opc;
			 system("cls");
			 cout << "-----Caixa de entrada-----" << endl;
			 // falta completar
		 }

		 void janelaEnviarMensagem() // enviar mensagem

		 {
			 char opc;
			 system("cls");
			 cout << "-----Enviar mensagem-----" << endl;
			 // falta completar
		 }
		

		 void janelaMensagemRecebida() // ler mensagem

		 {
			 char opc;
			 system("cls");
			 cout << "-----Mensagem-----" << endl;
			 // falta completar
		 }






