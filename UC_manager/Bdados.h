#ifndef BDados_ 
#define BDados_  
//#include <iostream> 
#include <iomanip> 
#include <occi.h>
#include "Aluno.h"
//#include "Mensagem.h"
#include "Utilizador.h"
#include "UC.h"
#include "Avaliacao.h"
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
	vector<Aluno> lerAlunos(string uc); // M�todo para ler uma lista de clientes
	vector<Mensagem> CarregaMsg();
	Pessoa* login(string _usr, string _pw);

	//existe Avaliacao
	Avaliacao getAval(string uc, string ed, string mom);
	void regAval(Avaliacao aval);
	void regAval_Notas(	int	it, double nota,Avaliacao aval);

	Connection * Ligacao() const { return ligacao; }
	void Ligacao(Connection * val) { ligacao = val; }
	void enviaMsgBD(string _usr, string cod_destino, string assunto, string msg, string anexo);

	// regAluno
	bool jaExisteAluno(int numero );
	void regAluno(Pessoa * aluno);

	// regDocente
	bool jaExisteDocente(string  cod );
	void regDocente(Pessoa * doc);

	//uc
	bool jaExisteCadeira(string  cod);
	void registarUC(UC * uc);
	void addSumario(string cod_uc, string cod_edicao, string cod_utilizador, string texto);
	vector<UC*> carregarUCs(string cod_u);
	vector<string> carregarSumarios(string cod_uc, string cod_edicao);

	//alterar Login
	void alterarLogin(Pessoa * user, string pw);
	void registarReuniao(string data_inicio, string data_fim, string des, string cod_user, string cod_uc, string cod_edicao, string cod_sala);
	void adicionarSala(string cod_sala, int capacidade);

	void fecharUC(string cod_uc,string cod_edicao);
	vector<double> getAval_Aluno(int a);
	//
	void registarTesteBD(string cod_aval, string tipo, string cod_uc, string cod_edicao, string data_realizada);
    void registarTPBD(string cod_aval, string tipo, string cod_uc, string cod_edicao, string data_realizada);
	void BDados::registarEventoBD(string data_inicio, string data_fim, string des, string cod_user, string cod_uc, string cod_edicao, string cod_sala);
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
	Pessoa* BDados::login(string _usr, string _pw)
	{
		Statement *instruc;
		system("cls");
		cout << endl <<"A fazer login...." << endl;
		instruc = ligacao->createStatement();
		ResultSet *rset = instruc->executeQuery("SELECT * FROM UTILIZADOR");

		bool match = false;
		Utilizador  * uti;
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
			return uti;
		}
		else{
			cout << "falhou login";
			return uti;
		}		
	}
	void BDados::enviaMsgBD(string _usr, string cod_destino, string assunto, string msg, string anexo)
	{
		Statement *instruc;
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

	bool BDados :: jaExisteAluno(int numero )
	{
		

		Statement *instruc;

		instruc = ligacao->createStatement("SELECT * FROM ALUNO WHERE COD_ALUNO=:1");
		instruc->setInt(1, numero);
		ResultSet *rset = instruc->executeQuery();
		if (!rset->next()) return false;
		
		return true;
	}

	void BDados :: regAluno(Pessoa * aluno)
	{
		Statement *instruc;
		if (aluno->getNumero() == 0)
		{
			instruc = ligacao->createStatement("INSERT INTO ALUNO (COD_ALUNO,NOME) VALUES (SEQ_COD_ALUNO.NEXTVAL,:1)");
			instruc->setString(1, aluno->getNome());
			ResultSet* rset2 = instruc->executeQuery();

		}
		else
		{
			instruc = ligacao->createStatement("INSERT INTO ALUNO (COD_ALUNO,NOME) VALUES (:1, :2)");
			instruc->setString(2, aluno->getNome());
			instruc->setInt(1, aluno->getNumero());
			ResultSet* rset2 = instruc->executeQuery();

			

		}
		ligacao->commit();
		
	}

	bool BDados :: jaExisteDocente(string  cod )
	{
		

		Statement *instruc;

		instruc = ligacao->createStatement("SELECT * FROM UTILIZADOR WHERE COD_UTILIZADOR=:1");
		instruc->setString(1, cod);
		ResultSet *rset = instruc->executeQuery();
		if (!rset->next()) return false;
		
		return true;
	}

	bool BDados::jaExisteCadeira(string  cod)
	{


		Statement *instruc;

		instruc = ligacao->createStatement("SELECT * FROM UC WHERE COD_UC=:1");
		instruc->setString(1, cod);
		ResultSet *rset = instruc->executeQuery();
		if (!rset->next()) return false;

		return true;
	}

	void BDados :: regDocente(Pessoa * doc)
	{
		Statement *instruc;
		
			instruc = ligacao->createStatement("INSERT INTO UTILIZADOR (COD_UTILIZADOR,NOME) VALUES (:1,:2)");
			instruc->setString(1, doc->getCod_utilizador());
			instruc->setString(2, doc->getNome());
			ResultSet* rset2 = instruc->executeQuery();

		
		ligacao->commit();
		
	}

	void BDados::registarUC(UC * uc)
	{
		Statement *instruc;

		instruc = ligacao->createStatement("INSERT INTO UC (COD_UC,COD_EDICAO,NOME,ANO,SEMESTRE) VALUES (:1,:2,:3,:4,:5)");
		instruc->setString(1, uc->Cod_uc());
		instruc->setString(2, uc->Edicao());
		instruc->setString(3, uc->Nome());
		instruc->setString(4, uc->Ano());
		instruc->setString(5, uc->getSemestre());
		ResultSet* rset2 = instruc->executeQuery();
		ligacao->commit();
		cout << endl << "Cadeira inserida com sucesso" << endl;

	}

	void BDados::addSumario(string cod_uc, string cod_edicao, string cod_utilizador, string texto)
	{
		Statement *instruc;
		instruc = ligacao->createStatement("INSERT INTO SUMARIO (COD_SUMARIO,COD_UC,COD_EDICAO,COD_UTILIZADOR, DESCRICAO) VALUES (SEQ_COD_SUMARIO.NEXTVAL,:1,:2,:3,:4)");

		instruc->setString(1, cod_uc);
		instruc->setString(2, cod_edicao);
		instruc->setString(3, cod_utilizador);
		instruc->setString(4, texto);
		ResultSet* rset2 = instruc->executeQuery();

		ligacao->commit();
		cout << endl << "Sumario inserido com sucesso" << endl;
		instruc->closeResultSet(rset2);
	}

	vector<UC*> BDados::carregarUCs(string cod_u)
	{
		
		Statement *instruc;
		instruc = ligacao->createStatement("SELECT * FROM UC WHERE COD_UC IN (SELECT COD_UC FROM DOCENTE_UC WHERE COD_UTILIZADOR =(:1)) OR REGENTE =:1");
		instruc->setString(1, cod_u);
		ResultSet* rset = instruc->executeQuery();

		vector<UC*> cadeiras;
		while (rset->next())
		{
			string cod_uc= rset->getString(1);
			string cod_ed = rset->getString(2);
			string nome = rset->getString(3);
			string ano = rset->getString(4);
			string semestre = rset->getString(5);
			string regente = rset->getString(6);
			UC* u = new UC(regente,cod_uc,nome,cod_ed,ano,semestre);
			cadeiras.push_back(u);
		}
		
		return cadeiras;
	}

	void BDados :: alterarLogin(Pessoa * user,string pw)
	{
		Statement *instruc;

		instruc = ligacao->createStatement("UPDATE UTILIZADOR SET pw=:1 WHERE cod_utilizador=:2");
		instruc->setString(1,pw);
		instruc->setString(2,user->getCod_utilizador());

	}

	Avaliacao BDados ::getAval(string uc,string ed, string mom)
	{
		Statement *instruc;

		instruc = ligacao->createStatement("SELECT * FROM AVALIACAO WHERE TIPO=:1 AND COD_UC=:2 AND COD_EDICAO=:3");
		instruc->setString(1, mom);
		instruc->setString(2, uc);
		instruc->setString(3, ed);

		ResultSet *rset = instruc->executeQuery();

		int cod_aval = rset->getInt(1);
		string tipo =rset->getString(2);
		string cod_uc = rset->getString(3);
		string cod_edicao = rset->getString(4);

		Avaliacao a(cod_aval,mom,uc,ed);		

		return a;

	}

	void BDados :: regAval(Avaliacao aval)
	{
		Statement *instruc;
		instruc = ligacao->createStatement("INSERT INTO AVALIACAO(COD_AVAL,TIPO,COD_UC,COD_EDICAO) VALUES(SEQ_COD_AVAL.NEXTVAL, :1, :2,:3)");
		instruc->setString(1, aval.getTipo());
		instruc->setString(2,  (aval.getUC())->Cod_uc());
		instruc->setString(3, (aval.getUC())->Edicao());
		ResultSet* rset2 = instruc->executeQuery();

		ligacao->commit();
		cout << endl << "Avaliacao registada com sucesso" << endl;
		instruc->closeResultSet(rset2);

	}

	void BDados :: regAval_Notas(int it, double nota,Avaliacao aval)
	{
		Statement *instruc;
		instruc = ligacao->createStatement("INSERT INTO AVALIACAO_ALUNO(COD_AVAL,COD_ALUNO,NOTA_FINAL) VALUES( :1, :2,:3)");
		instruc->setInt(1, aval.getCod_avaliacao());
		instruc->setInt(2,  it);
		instruc->setDouble(3, nota);
		ResultSet* rset2 = instruc->executeQuery();

		ligacao->commit();
		cout << endl << "Avaliacao registada com sucesso" << endl;
		instruc->closeResultSet(rset2);
	}

	vector<string> BDados::carregarSumarios(string cod_uc, string cod_edicao)
	{
		Statement *instruc;
		instruc = ligacao->createStatement("SELECT * FROM SUMARIO WHERE COD_UC =:1 AND COD_EDICAO =:2");
		instruc->setString(1, cod_uc);
		instruc->setString(2, cod_edicao);
		ResultSet* rset2 = instruc->executeQuery();
		vector<string> sumarios;
		while (rset2->next())
		{
			sumarios.push_back(rset2->getString(6));
		}
		
		instruc->closeResultSet(rset2);
		return sumarios;
	}

	void BDados::registarReuniao(string data_inicio, string data_fim, string des, string cod_user, string cod_uc, string cod_edicao, string cod_sala)
	{
		Statement *instruc;
		instruc = ligacao->createStatement("INSERT INTO EVENTO(COD_EVENTO,COD_UC,COD_EDICAO,COD_SALA,COD_UTILIZADOR,DESCRICAO,DATA_INICIO,DATA_FIM) VALUES(SEQ_COD_AVAL.NEXTVAL,:1,:2,:3,:4,:5,:6,:7)");
		instruc->setString(1, cod_uc);
		instruc->setString(2, cod_edicao);
		instruc->setString(3, cod_sala);
		instruc->setString(4, cod_user);
		instruc->setString(5, des);
		instruc->setString(6, data_inicio);
		instruc->setString(7, data_fim);
		ResultSet* rset2 = instruc->executeQuery();

		ligacao->commit();
		cout << endl << "Reuniao marcada com sucesso" << endl;
		instruc->closeResultSet(rset2);
	}
	void BDados::adicionarSala(string cod_sala,int capacidade)
	{
		Statement *instruc;
		instruc = ligacao->createStatement("INSERT INTO SALA(COD_SALA,CAPACIDADE)VALUES(:1,:2)");
		instruc -> setString(1, cod_sala);
		instruc -> setInt(2, capacidade);
		ResultSet* rset2 = instruc->executeQuery();

		ligacao->commit();
		cout << endl << "Sala adicionada com sucesso" << endl;
		instruc->closeResultSet(rset2);
	}


	void BDados :: fecharUC(string cod_uc,string cod_edicao)
	{
		Statement *instruc;
		instruc = ligacao->createStatement("BEGIN P_FECHA_UC(:1,:2) ;END;");
		instruc->setString(1, cod_uc);
		instruc->setString(2,  cod_edicao);
		ResultSet* rset2 = instruc->executeQuery();
		ligacao->commit();

		instruc->closeResultSet(rset2);

	}

	vector<double> BDados ::getAval_Aluno(int a)
	{
		vector<double> notas;
		Statement *instruc;
		instruc = ligacao->createStatement("SELECT nota FROM AVALIACAO_ALUNO WHERE COD_ALUNO =:1 ");
		instruc->setInt(1, a);
		ResultSet* rset2 = instruc->executeQuery();
		while (rset2->next())
		{
			
			string nota= rset2->getString(1);
			double n = stod(nota);
			notas.push_back(n);
			
		}
		instruc->closeResultSet(rset2);
		return notas;
	}

	vector<Aluno> BDados :: lerAlunos(string uc)
	{
		vector<Aluno> alunos;
		Statement *instruc;
		instruc = ligacao->createStatement("SELECT cod_aluno FROM ALUNO_UC WHERE COD_UC =:1");
		instruc->setString(1, uc);
		ResultSet* rset2 = instruc->executeQuery();
		while (rset2->next())
		{
			
			string a= rset2->getString(1);
			int n = stoi(a);
			Aluno al;
			al.setNumero(n);
			alunos.push_back(al);
			
		}
		instruc->closeResultSet(rset2);
		return alunos;
	}
	

void BDados::registarTesteBD(string cod_aval, string tipo, string cod_uc, string cod_edicao, string data_realizada)
	{
		Statement *instruc;
		instruc = ligacao->createStatement("INSERT INTO AVALIACAO(COD_AVAL,TIPO,COD_UC,COD_EDICAO,DATA_REALIZACAO) VALUES(SEQ_COD_AVAL.NEXTVAL,:1,:2,:3,:4)");
		instruc->setString(1, tipo);
		instruc->setString(2, cod_uc);
		instruc->setString(3, cod_edicao);
		instruc->setString(4, data_realizada);
		ResultSet* rset2 = instruc->executeQuery();

		ligacao->commit();
		cout << endl << "Teste marcado com sucesso" << endl;
		instruc->closeResultSet(rset2);
	}

void BDados::registarTPBD(string cod_aval, string tipo, string cod_uc, string cod_edicao, string data_realizada)
	{
		Statement *instruc;
		instruc = ligacao->createStatement("INSERT INTO AVALIACAO(COD_AVAL,TIPO,COD_UC,COD_EDICAO,DATA_REALIZACAO) VALUES(SEQ_COD_AVAL.NEXTVAL,'TP',:1,:2,:3)");
		instruc->setString(1, cod_uc);
		instruc->setString(2, cod_edicao);
		instruc->setString(3, data_realizada);
		ResultSet* rset2 = instruc->executeQuery();

		ligacao->commit();
		cout << endl << "Teste marcado com sucesso" << endl;
		instruc->closeResultSet(rset2);
	}

void BDados::registarEventoBD(string data_inicio, string data_fim, string des, string cod_user, string cod_uc, string cod_edicao, string cod_sala)
	{
		Statement *instruc;
		instruc = ligacao->createStatement("INSERT INTO EVENTO(COD_EVENTO,COD_UC,COD_EDICAO,COD_SALA,COD_UTILIZADOR,DESCRICAO,DATA_INICIO,DATA_FIM) VALUES(SEQ_COD_AVAL.NEXTVAL,:1,:2,:3,:4,:5,:6,:7)");
		instruc->setString(1, cod_uc);
		instruc->setString(2, cod_edicao);
		instruc->setString(3, cod_sala);
		instruc->setString(4, cod_user);
		instruc->setString(5, des);
		instruc->setString(6, data_inicio);
		instruc->setString(7, data_fim);
		ResultSet* rset2 = instruc->executeQuery();

		ligacao->commit();
		cout << endl << "Reuniao marcada com sucesso" << endl;
		instruc->closeResultSet(rset2);
	}


#endif 