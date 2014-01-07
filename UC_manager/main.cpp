#include <iostream>
#include <string>

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
	 try {     cout << "Exemplo de ligacao: a ligar ..."        << endl;    
	 BDados *ligacao = new BDados (utilizador, palavra, bd); 
	 cout << "ligaçao estabelecida" << endl;
	 delete ligacao;


	// int opcao;
	// string sigla;
	// char user;
	// cin >> sigla;/*ligacao->Login(username,password);*/

	// Utilizador doc=ligacao->getDocente(sigla);
	// user=doc.getTipo();
	// if (user=='R')
	// {
	//		cout << "Bem Vindo =)"<< endl<<endl;
	//		do{
	//		cout << "escolha uma das seguintes opcoes:" << endl<< endl ;
	//		cout << "1. Consultar Mensagens InBox" << endl;
	//		cout << "2. Enviar Mensagem/Pedido" << endl;
	//		cout << "3. Marcar Reuniao" << endl;
	//		cout << "4. Marcar Teste" << endl;
	//		cout << "0. Logout" <<endl;
	//		cin >> opcao;

	//		
	//			switch(opcao)
	//			{
	//			case 1:
	//				cout << opcao << endl;
	//				ligacao->CarregarMsg(doc);
	//				break;

	//			case 2:
	//				cout << opcao << endl;
	//				ligacao->EscreveMsg();
	//				break;

	//			case 3:
	//				cout << opcao << endl;
	//				//ligacao->MarcaReuniao();
	//				break;
	//			case 4:
	//				cout << opcao << endl;
	//				//ligacao->MarcaTeste();
	//				break;
	//			case 0:
	//				break;
	//			default:
	//				cout << "Opcao Incorreta"<< endl;
	//			}
	//		}while(opcao !=0);
	// }

	// else if(user =='D')
	// {
	//	 cout << "Docente login"<< endl<<endl;
	//	do{
	//		cout << "Bem Vindo =)"<< endl << endl << "escolha uma das seguintes opcoes:" << endl ;
	//		cout << "1. Consultar Mensagens InBox" << endl;
	//		cout << "2. Enviar Mensagem/Pedido" << endl;
	//		cout << "3. Marcar Teste" << endl;
	//		cout << "4. Marcar Apresentacao/Defesa de Trabalho Pratico" << endl;
	//		cout << "0. Logout" <<endl;
	//		cin >> opcao;
	//		
	//		
	//			switch(opcao)
	//			{
	//			case 1:
	//				ligacao->CarregarMsg();
	//				cout << opcao << endl;
	//				break;

	//			case 2:
	//				ligacao->EscreveMsg();
	//				cout << opcao << endl;
	//				break;

	//			case 3:
	//				cout << opcao << endl;
	//				//ligacao->MarcaTeste();
	//				break;
	//			case 4:
	//				cout << opcao << endl;
	//				//ligacao->MarcaReuniao();
	//				break;
	//			case 0:
	//				break;
	//			}
	//		}while(opcao !=0);
	// }
	//delete (ligacao);     cout << "Exemplo de ligacao: terminado" << endl;   
	 }   catch (SQLException erro) {    
		 cerr << "Erro: " << erro.getMessage () << endl; 
	 } 
	 
	 void menu()
	 {

	 }
	return 0; 
	}

	 



