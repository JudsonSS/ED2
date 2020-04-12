#include <iostream>
#include <string>
using namespace std;

// ------------------------------------------------------------


struct Processo
{
	int chave;
	string nome;

	bool operator>(Processo p)
	{
		if (chave > p.chave)
			return true;
		else
			return false;
	}

	bool operator<(Processo p)
	{
		if (chave < p.chave)
			return true;
		else
			return false;
	}

	friend ostream & operator<<(ostream & os, Processo & p)
	{
		os << "(" << p.chave << " " << p.nome << ")";
		return os;
	}

};

// ------------------------------------------------------------


class FilaPrio
{
private:
	int n;
	int Max;
	Processo * heap;

	void subir(int);
	void descer(int);

public:
	FilaPrio();
	~FilaPrio();

	void inserir(Processo);
	Processo remover();
	void exibir();
};

// ------------------------------------------------------------


