#ifndef BDados_ 
#define BDados_  
#include <iostream> 
#include <iomanip> 
#include <occi.h> 
#include <list>  
using namespace oracle::occi;
#include "Aluno.h"

class BDados {  
private:   Environment *env;  
		   Connection *ligacao;  
		   Statement *instrucao;   
public:    
	BDados(string user, string passwd, string db);  
	~ BDados();   
	list <Aluno> lerClientes(); // Método para ler uma lista de clientes };  
	BDados::BDados(string user, string passwd, string db) 
	{     env = Environment::createEnvironment (Environment::DEFAULT);     
	ligacao = env->createConnection (user, passwd, db); }  
	BDados::~BDados() 
	{     env->terminateConnection (ligacao);  
	Environment::terminateEnvironment (env); 
	} 
	list <Aluno> BDados::lerAlunos() { 
		list <Aluno> ret;     
		instrucao = ligacao->createStatement("SELECT * FROM Aluno"); 
		ResultSet *rset = instrucao->executeQuery ();    
		while (rset->next ())    
		{   Aluno a(rset->getInt(1), rset->getString(2));
		ret.push_back(a);     }   
		instrucao->closeResultSet (rset);  return ret; } 
#endif 