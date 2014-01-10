#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include"Bdados.h"
#include "Gestao.h"
#include <string>
#include <conio.h>

using namespace std;    


/*******************************************************************************************/
Gestao _gestao;
BDados *ligacao;
Utilizador* ut;

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
/*******************************************************************************************/

int main(void)
{
	system( "color 79" );
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
		 char c=' ';
		 cin  >> _user;
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
			 

			 ut = &ligacao->login(_user, _pw);
			 //cout << *ut;
			 string null = "";
			 
				 if (ut->getTipo() == 'D')
				 {
					 cout <<endl << "Bem-vindo " << ut->getNome() << endl;
					 cout << "Tipo de acesso: Docente"<<endl<<endl;
					 system("Pause");
					 janelaUC();
				 }
				 if (ut->getTipo() == 'R'){
					 cout <<endl<< "Bem-vindo " << ut->getNome() << endl;
					 cout << "Tipo de acesso: Regente" << endl<<endl;
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
		 }

		 
	 }

	 void janelaBV_Regente() //janela boas vindas
	 {
		 system("cls");
		 cout << "-----Bem-vindo-----" << endl << endl <<
			 "1-Entrar UC" << endl << "2-Adicionar UC" << endl << "3-Remover UC"<<endl <<"----------" 
			 <<endl <<"m-Mensagens"<< endl << endl << "A sua opcao: ";
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

	 void janelaGerirConteudo() //só acessivel pelo regente
	 {
		 char opc;
		 system("cls");
		 cout << "-----Gerir Conteudos-----" << endl << endl << "0-Voltar" << endl <<
			 "1-Gerir Eventos" << endl << "2-Gerir Docentes" << endl << "3-Gerir UC" << endl << "4-Gerir Alunos" << endl << "A sua opcao: ";
		 cin >> opc;
		 switch (opc)
		 {	
			 case '0':janelaBV_Regente();
			 case '1':janelaGerirEventos();
			 case '2': // falta criar janela gerir docentes
				 ;
			 case '3':janelaGerirConteudo(); // confirmar que é esta janela não tenho certeza
			 case '4': // associar janela...
			 case 'm':janelaMensagens();
			 default: janelaGerirConteudo(); // retorna á mesma janela.
		 }
	 }

		 void janelaGerirEventos()
		 {
			 char opc;
			 system("cls");
			 cout << "-----Gerir Eventos-----" << endl << endl << "0-Voltar" << endl <<
				 "1-Alterar" << endl << "2-Remover" << endl << "3-Adicionar" << endl << "A sua opcao: ";
			 
			cin >> opc;
		 switch (opc)
		 {	
			case '0':janelaGerirConteudo();
			 case '1':;
			 case '2':; 
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
				 "1-Caixa de entrada" << endl << "2-Escrever mensagem" << endl << "A sua opcao: ";
			 cin >> opc;
			 switch (opc)
			 {	
				case '0':janelaUC();
				case '1':janelaCaixaEntrada();
				case '2':janelaEnviarMensagem();
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
				 << endl << "6-Marcar aula extra" <<endl<< "7-Histórico"<<endl<< "A sua opcao: ";
			 cin >> opc;
		 switch (opc)
		 {	
			 case '0':;
			 case '1':;
			 case '2':;
			 case '3':;
			 case '4':;
			 case '5':;
			 case '6':;
		     case '7':;
			 case 'm':;
			 default: janelaUC();
		 }
		 }

		 void janelaVisualizacao()

		 {
			 char opc;
			 system("cls");
			 cout << "-----Visualizacao-----" << endl << endl << "0-Voltar" << endl <<
				 "1-Visualizar notas" << endl << "2-Visualizar sumarios" << endl << "A sua opcao: " ;
			 cin >> opc;
		 switch (opc)
		 {	
			 case '0':janelaUC();
			 case '1':;
			 case '2':;
			 case 'm':janelaMensagens();
			 default: janelaVisualizacao();
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
				 system("cls"); //metodo nao seguro, corrigir se possivel, pois caso o user utilize uma tecla que nao um numero ou "m" o programa não sabe o que fazer
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
			 cout << endl <<"Assunto ";
			 cin >> assunto;
			 cout << endl << "Mensagem: ";
			 cin >> mensagem;
			 anexo = "l";
			 while(anexo.compare("n") != 0 || anexo.compare("s") !=0)
			 {			 
				cout << endl << "Deseja anexo? (s/n)";
				cin >> anexo;
			 }
			 bool an = false;
			 if (anexo.compare("s")==0)
			 {
				 an = true;
				 cout <<endl<< "Nome anexo: ";
				 cin >> anexo;				  
			 }
			 if (an) /// cria mensagem com anexo
			 {
				 try{
					 ligacao->enviaMsgBD(ut->getCod_utilizador(), para, assunto, mensagem, anexo);
				 }
				 catch (int excp) 
				 {	 
					 cout << "Mensagem não enviada, tente de novo" << endl;
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
					 cout << "Mensagem não enviada, tente de novo" << endl;
					 system("PAUSE");
					 janelaCaixaEntrada();
				 }
			 }
		 }
		






