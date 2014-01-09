#ifndef BDados_ 
#define BDados_  
#include <iostream> 
#include <iomanip> 
#include <occi.h>
#include "Aluno.h"
#include "Mensagem.h"
#include "Utilizador.h"
//#include <list>
//#include <vector>
using namespace oracle::occi;


class BDados {  
private:  
	Environment *env;  
	Connection *ligacao;  
	Statement *instrucao;   
public:    

	BDados(string user, string passwd, string db);  
	~ BDados();   
	list <Aluno> lerAlunos(); // Método para ler uma lista de clientes
	vector<Mensagem> CarregaMsg();
	static Utilizador* login(string _usr, string _pw);


};
	BDados::BDados(string user, string passwd, string db) 
	{     
		env = Environment::createEnvironment (Environment::DEFAULT);     
		ligacao = env->createConnection (user, passwd, db);  
		cout << "*****ligacao efetuada*******" << endl;
	}
	BDados::~BDados() 
	{    
		env->terminateConnection (ligacao);  
		Environment::terminateEnvironment (env); 
	} 

	///
	static Utilizador* login(string _usr, string _pw)
	{
		Connection *ligacao;
		Statement *instrucao;
		
		string state = "SELECT * FROM UTILIZADOR WHERE COD_UTILIZADOR=" + _usr + " AND PW=" + _pw;
		instrucao = ligacao->createStatement(state);
			
		ResultSet *rset = instrucao->executeQuery ();   
		string cod = rset->getString(1);
		string nome = rset->getString(2);
		string tipo = rset->getString(3);
		string pass = rset->getString(4);
		vector<Mensagem> msg;
		Utilizador * uti = new Utilizador(nome, cod, tipo[0], msg);
		return uti;
	}

	//list <Aluno> BDados::lerAlunos() 
	//{ 
	//	list <Aluno> ret; 
	//	
	//	instrucao = ligacao->createStatement("SELECT * FROM ALUNO"); 
	//	ResultSet *rset = instrucao->executeQuery ();
	//	while (rset->next ())    
	//	{   
	//		int i=rset->getInt(1);
	//		string s=rset->getString(2);
	//		//Aluno a(i,s);
	//	ret.push_back(a);     
	//	}
	//	
	//	instrucao->closeResultSet (rset);  
	//	return ret; } 
	//Utilizador BDados::getDocente(string sigla) 
	//{ 
	//	Utilizador ret; 
	//	
	//	instrucao = ligacao->createStatement("SELECT * FROM UTILIZADOR WHERE SIGLA=COD_UTILIZADOR"); 
	//	ResultSet *rset = instrucao->executeQuery ();
	//	while (rset->next ())    
	//	{   
	//		string codigo=rset->getString(1);
	//		string nome=rset->getString(2);
	//		string data=rset->getString(3);
	//		char tipo=rset->getString(4)[0];
	//		string grau=rset->getString(5);
	//		string pw=rset->getString(6);
	//		ret(codigo,nome,data,tipo,grau,pw);
	//	}
	//	
	//	instrucao->closeResultSet (rset);  
	//	return ret;
	//}

	//string BDados::EscreveMsg(Utilizador doc)
	//{
	//	instrucao = ligacao->createStatement("SELECT count(*) FROM MENSAGEM ");
	//	ResultSet *rset = instrucao->executeQuery();

	//	int cod = rset->getInt(1);

	//	string msg;
	//	string dest;
	//	string assunto;
	//	cout << "introduza o assunto da mensagem  : "; cin >> assunto; cout << endl;
	//	cout << "introduza a sigla do destinatario  : "; cin >> dest; cout << endl;
	//	cout << "Mensagem : " << endl; cin >> msg; cout << endl;

	//	instrucao = ligacao->createStatement("INSERT INTO MENSAGEM( VALUES(:COD_DESTINO,:COD_ORIGEM,:COD_UC,:ASSUNTO,:MENSAGEM");
	//	instrucao->setInt(1, cod);
	//	instrucao->setString(2, dest);
	//	instrucao->setString(3, doc.getCod_utilizador());
	//	/*instrucao->setString(4,null);*/
	//	/*instrucao->setString(5, assunto);*/
	//	instrucao->setString(6, assunto);
	//	instrucao->setString(7, msg);
	//}
		
	/*void BDados::CarregaMsg(string cod_doc) 
	{ 
		vector <Mensagem> ret; 
		
		instrucao = ligacao->createStatement("SELECT * FROM MENSAGEM WHERE COD_DESTINO = cod_doc"); 
		ResultSet *rset = instrucao->executeQuery ();
		while (rset->next ())    
		{   
			int codigo=rset->getInt(1);
			string cod_destino=rset->getString(2);
			string cod_origem=rset->getString(3);
			string cod_uc=rset->getString(4);
			int cod_edicao=rset->getInt(5);
			string assunto=rset->getString(6);
			string texto=rset->getString(7);
			
			Mensagem a(codigo,texto,assunto,"",cod_destino,cod_origem,"","");
			ret.push_back(a);     
		}
		int i;
		int choice;
		do{for(i=0;i<ret.size();i++){
			cout<<i+1<< ".";
			ret[i].listar();
		}
		cin >>choice; 
		cout << ret[choice-1];
		

		instrucao->closeResultSet (rset);  
		return ret; } */
#endif 