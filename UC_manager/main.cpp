#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include"Pessoa.h"
#include"Bdados.h"
#include"Aluno.h"
using namespace std;    
/*******************************************************************************************/
/*******************************************************************************************/
/*******************************************************************************************/

int main(void)
{

	cout << "Development test area!" << endl;


	cout << endl;
	/////////////////////////BDADODS

	string utilizador = "B6_5";
	string palavra = "xico";
	string bd = "193.136.62.27:1521/pdborcl"; //ou em vez de ip, gandalf   
	try {
		cout << "Exemplo de ligacao: a ligar ..." << endl;
		BDados *ligacao = new BDados(utilizador, palavra, bd);
		cout << "ligaçao estabelecida" << endl;
		delete ligacao;

	}
	catch (SQLException erro) {
		cerr << "Erro: " << erro.getMessage() << endl;
	}

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
	 }

	 void janelaBV_Regente() //janela boas vindas
	 {
		 system("cls");
		 cout << "---Bem-vindo--" << endl << endl <<
			 "1-Entrar UC" << endl << "2-Adicionar UC" << endl << "3-Remover UC" << endl << "A sua opcao:" << endl;
		 char opc;
		 cin >> opc;
		 if (opc > '3' || opc < '0')
		 {
			 janelaBV_Regente();
		 }
	 }

	 void janelaGerirConteudo()
	 {
		 char opc;
		 system("cls");
		 cout << "-----Gerir Conteudos-----" << endl << endl << "0-Voltar" << endl <<
			 "1-Gerir Eventos" << endl << "2-Gerir Docentes" << endl << "3-Gerir UC" << endl << "4-Gerir Alunos" << endl << "A susa opcao: " << endl;
		 if (opc == '0')
		 {
			 janelaBV();
		 }
		 if (opc == '4' || opc == '2' || opc == '3')
		 {
			 // abre janela
		 }
		 if (opc == '1')
		 {

		 }
	 }

		 void janelaGerirEventos()
		 {
			 char opc;
			 system("cls");
			 cout << "-----Gerir Eventos-----" << endl << endl << "0-Voltar" << endl <<
				 "1-Alterar" << endl << "2-Remover" << endl << "3-Adicionar" << endl << "A sua opcao: " << endl;
			 if (opc == '0')
			 {
				 janelaGerirConteudo();
			 }
		}

		 void janelaUC()
		 {
			 char opc;
			 system("cls");
			 cout << "-----Janela UC-----" << endl << endl << "0-Voltar" << endl <<
				 "Leccionadas" << endl << "Permissões/Histórico" << endl;
			 if (opc == '0')
			 {
				 // volta atras
			 }
		 }
		 void janelaMensagens()
		 {
			 char opc;
			 system("cls");
			 cout << "-----Mensagens-----" << endl << endl << "0-Voltar" << endl <<
				 "1-Caixa de entrada" << endl << "2-Escrever mensagem" << endl << "A sua opcao: " << endl;
			 if (opc == '0')
			 {
				 janelaUC();
			 }
		 }
		 
		 void janelaDisciplina()
		 {
			 char opc;
			 system("cls");
			 cout << "-----Gestão Disciplina-----" << endl << endl << "0-Voltar" << endl <<
				 "1-Marcar Avaliacao" << endl << "2-Publicar notas" << endl << "3-Visualizar notas" << endl << "4-Escrever sumarios" << endl  << "5-Visualizar Sumarios" 
				 << endl << "6-Marcar aula extra" <<endl<< "7-Histórico"<<endl<< "A sua opcao: " << endl;
			 if (opc == '0')
			 {
				 janelaUC();
			 }
		 }

		 void janelaVisualizacao()

		 {
			 char opc;
			 system("cls");
			 cout << "-----Visualizacao-----" << endl << endl << "0-Voltar" << endl <<
				 "1-Visualizar notas" << endl << "2-Visualizar sumarios" << endl << "A sua opcao: " << endl;
			 if (opc == '0')
			 {
				 janelaUC();
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






