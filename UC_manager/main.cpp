#include <iostream>
#include <string>
#include <vector>
#include <list>
#include<iostream>
#include<string>

using namespace std;
#include"Bdados.h"
#include"Aluno.h"


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


int main(void)
{

    // insert code here...
    //menuprincipal();

    cout << "Development test area!" << endl;
 
    
    cout << endl;
    /////////////////////////BDADODS

	 string utilizador = "B6_5";  
	 string palavra = "B6_5"; 
	 string bd = "193.136.62.27:1521/isepdb"; //ou em vez de ip, gandalf   
	 try {     cout << "Exemplo de ligacao: a ligar ..."        << endl;    
	 BDados *exemplo = new BDados (utilizador, palavra, bd);  
	 list <Aluno> l = exemplo->lerAlunos(); 
	 //cout << setw(5) << "COD." << " | "      << setw(12) << "Nome" << "         | "     << setw(6) << "NIF" << "    | "     << setw(14) << "Morada" << "       | " << endl; 
	 for (list<Aluno>::iterator it = l.begin(); it != l.end(); it++)   cout << *it;  cout << endl;     delete (exemplo);     cout << "Exemplo de ligacao: terminado" << endl;   
	 }   catch (SQLException erro) {    
		 cerr << "Erro: " << erro.getMessage () << endl; 
	 }   cin.get();  
	 return 0; 
}
