#include <iostream>
#include <string>
#include <iomanip>
#include <occi.h>
using namespace std;
using namespace oracle::occi;
#include "Bdados.h"
#include "Aluno.h"
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
	 string bd = "gandalf.isep.ipp.pt:1521/pdborcl"; //ou em vez de ip, gandalf   
	 try {     cout << "Exemplo de ligacao: a ligar ..."        << endl; 
	 cout << "********************"<<endl;
	 BDados *exemplo = new BDados (utilizador, palavra, bd);  
	 list <Aluno> l = exemplo->lerAlunos(); 
	 cout << setw(5) << "COD." << " | "      << setw(12) << "Nome" << "         | "     << setw(6) << "NIF" << "    | "     << setw(14) << "Morada" << "       | " << endl; 
	 for (list<Aluno>::iterator it = l.begin(); it != l.end(); it++)   cout << *it;  cout << endl;     delete (exemplo);     cout << "Exemplo de ligacao: terminado" << endl;   
	 }   catch (SQLException erro) {    
		 cerr << "Erro: " << erro.getMessage() << endl; 
	 }   cin.get();  
	 return 0; 
}
