#ifndef BDados_ 
#define BDados_  
//#include <iostream> 
#include <iomanip> 
#include <occi.h>
#include "Aluno.h"
#include "Mensagem.h"
#include "Utilizador.h"
//#include <list>
//#include <vector>
using namespace oracle::occi;
//using namespace std;

class BDados {  
private:  
	Environment *env;  
	Connection *ligacao;  
	Statement *instrucao;
public:    

	BDados(string user, string passwd, string db);  
	~ BDados();   
	list <Aluno> lerAlunos(); // M�todo para ler uma lista de clientes
	vector<Mensagem> CarregaMsg();
	Utilizador& login(string _usr, string _pw);

	Connection * Ligacao() const { return ligacao; }
	void Ligacao(Connection * val) { ligacao = val; }
	void enviaMsgBD(string _usr, string cod_destino, string assunto, string msg, string anexo);
};

	BDados::BDados(string user, string passwd, string db) 
	{     
		env = Environment::createEnvironment (Environment::DEFAULT);     
		ligacao = env->createConnection (user, passwd, db);  
		//cout << "*****ligacao efetuada*******" << endl;
	}
	BDados::~BDados() 
	{    
		env->terminateConnection (ligacao);  
		Environment::terminateEnvironment (env); 
	} 

	/// m�todo login
	Utilizador& BDados::login(string _usr, string _pw)
	{
		Statement *instruc;
		system("cls");
		cout << endl <<"A fazer login...." << endl;
		instruc = ligacao->createStatement();
		ResultSet *rset = instruc->executeQuery("SELECT * FROM UTILIZADOR");

		bool match = false;
		Utilizador* uti;
		vector<Mensagem> msg;
		while (rset->next()){
			string cod = rset->getString(1);
			string nome = rset->getString(2);
			string tipo = rset->getString(3);
			string pass = rset->getString(4);
			if (cod.compare(_usr) ==0 && pass.compare(_pw) ==0)
			{
				ResultSet* rset2 = instruc->executeQuery("SELECT * FROM MENSAGEM");
				while (rset2->next())
				{
					string cod_origem = rset2->getString(3);
					string cod_uc = rset2->getString(4);
					int cod_edicao = rset2->getInt(5);
					string assunto = rset2->getString(6);
					string mensagem = rset2->getString(7);
					string data_envio = rset2->getString(8);
					string data_leitura = rset2->getString(9);
					string data_limite = rset2->getString(10);
					string cod_ficheiro = rset2->getString(11);
					if (cod_origem != _usr)
					{
						Mensagem ms(cod_origem, assunto, mensagem, data_envio, cod_ficheiro);
						msg.push_back(ms);
					}
				}
				char i = tipo[0];
				uti = new Utilizador(nome, cod, i, msg);
				match = true;
				break;
			}
		}
		if (match){
			cout << "Sucesso";
			return *uti;
		}
		else{
			cout << "falhou login";
			return *uti;
		}		
	}
	void BDados::enviaMsgBD(string _usr, string cod_destino, string assunto, string msg, string anexo)
	{
		Statement *instruc;
		cout << "AAAAAAAAA" << endl;
		instruc = ligacao->createStatement("INSERT INTO MENSAGEM (COD_MENSAGEM,COD_ORIGEM,COD_DESTINO,ASSUNTO,MENSAGEM,COD_FICHEIRO) VALUES (SEQ_COD_MENSAGEM.NEXTVAL,:1,:2,:3,:4,:5)");
		instruc->setString(1, _usr);
		instruc->setString(2, cod_destino);
		instruc->setString(3, assunto);
		instruc->setString(4, msg);
		instruc->setString(5, anexo);
		
		ResultSet* rset2 = instruc->executeQuery();

		instruc = ligacao->createStatement("commit");
		rset2 = instruc->executeQuery();
		instruc->closeResultSet(rset2);
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