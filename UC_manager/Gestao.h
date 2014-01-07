#ifndef Gestao_
#define Gestao_
template <class T>
class Gestao
{
private:
	
	void destroy();

public:
	//Construtor e destrutor
	Gestao();
	Gestao(const Gestao &g);
	~Gestao();
	//metodo ordenar
	ListarVectores(vector<T*> t);
};

//construtor e destrutor
Gestao::Gestao()
{
}
Gestao::Gestao(const Gestao &g){

}

Gestao::~Gestao(){}

template <class T>
void ListarVectores(vector<T*> t){
	vector<Pessoa*>::const_iterator it;

	for (it = t.begin(); it != t.end(); it++) {

		cout << "Nome: " << **it << "\n";

	}
#endif
