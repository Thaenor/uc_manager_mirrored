#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;

#include "Pessoa.h"
#include "Utilizador.h"

/*******************************************************************************************/
/*******************************************************************************************/
/*******************************************************************************************/

// Criacao de menus
void menuprincipal();

//Funções para compatibilidade entre Sistemas Operativos
void clear()
{
#ifdef _WIN64
    system("cls");
#elif _WIN32
    system("cls");
#else
    cout << string( 100, '\n' );
#endif
    
}

void pause()
{
#ifdef _WIN64
    system("pause");
#elif _WIN32
    system("pause");
#else
    cout << "paused, press any key to resume.";
    cin.get();
    cin.get();
#endif
}

/*******************************************************************************************/
/*******************************************************************************************/
/*******************************************************************************************/


int main(int argc, const char * argv[])
{

    // insert code here...
    //menuprincipal();

    cout << "Development test area!" << endl;
    
    Uc obj (1,"amata");
    Uc obj2 (2,"Aprog");
    Uc obj3 (3,"LAPR");
    Uc* apt_uc = new Uc();
    apt_uc = &obj3;
    
    obj.write();
    
    
    cout << endl;
    /////////////////////////BDADODS

	 string utilizador = "nfm";  
	 string palavra = "lapr3_nfm"; 
	 string bd = "193.136.62.27:1521/isepdb"; //ou em vez de ip, gandalf   
	 try {     cout << "Exemplo de ligacao: a ligar ..."        << endl;    
	 BDados *exemplo = new BDados (utilizador, palavra, bd);  
	 list <Cliente> l = exemplo->lerClientes(); 
	 cout << setw(5) << "COD." << " | "      << setw(12) << "Nome" << "         | "     << setw(6) << "NIF" << "    | "     << setw(14) << "Morada" << "       | " << endl; 
	 for (list<Cliente>::iterator it = l.begin(); it != l.end(); it++)   cout << *it;  cout << endl;     delete (exemplo);     cout << "Exemplo de ligacao: terminado" << endl;   
	 }   catch (SQLException erro) {    
		 cerr << "Erro: " << erro.getMessage () << endl; 
	 }   cin.get();  
	 return 0; 
}






void menuprincipal(){
    
    cout << "=========================" << endl << "| Welcome to UC Manager! |"  << endl << "=========================" << endl << endl;
    
	bool flag=false;
	
	int op;
	do{
		clear();
		cout << " Trabalho Pratico - ESINF 2013 \n" << endl<<endl;
		cout << " |_______________ MENU______________"<<endl;
		cout << " 1: In development " <<endl;
		cout << " 2: In development "<<endl;
		cout << " 3: In development     "<<endl;
		cout << " 0: Sair " <<endl;
		cout << " |__________________________________|"<<endl;
		cin>>op;
		switch (op)
		{
			case 0:
				exit(1);
			case 1:
				flag=true;
				clear();
            {
                // INSERT FUNCTION HERE
                cout <<endl;
            }
				pause();
				clear();
				break;
                
			case 2:
				clear();
				// INSERT FUNCTION HERE
				pause();
				break;
			case 3:
            {
                // INSERT FUNCTION HERE
				break;
            }
			default:
            {
				cout << "Opcao invalida!" << endl << endl;
				
				pause();
				
            }
        }
		
	}while(op!=0);
    
	pause();
}