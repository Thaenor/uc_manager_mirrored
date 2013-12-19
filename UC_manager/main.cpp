#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include "Bdados.h"
#include "Aluno.h"
#include "Pessoa.h"
#include "Utilizador.h"

using namespace std;



/*******************************************************************************************/
/*******************************************************************************************/
/*******************************************************************************************/



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