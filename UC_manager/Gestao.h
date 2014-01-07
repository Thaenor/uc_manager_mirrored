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
	void ListarVectores(vector<T*> t);
};

//construtor e destrutor
template <class T>
Gestao<T>::Gestao()
{
}

template <class T>
Gestao<T>::Gestao(const Gestao &g){

}
template <class T>
Gestao<T>::~Gestao(){}

template <class T>
void Gestao<T> ::ListarVectores(vector<T*> t)
{
	vector<Pessoa*>::const_iterator it;

	for (it = t.begin(); it != t.end(); it++) {

		cout << "Nome: " << **it << "\n";

	}
}
#endif
