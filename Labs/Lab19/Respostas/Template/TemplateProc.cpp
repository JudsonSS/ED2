// ------------------------------------------------------------
// Fila de Prioridades - C++ orientado a objetos
// ------------------------------------------------------------

#include "FilaPrioTemplate.h"

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


int main()
{
	FilaPrio<Processo> fila;
	cout << "Insere 8 elementos..." << endl;
	fila.inserir({ 95, "notepad" });
	fila.inserir({ 60, "paint" });
	fila.inserir({ 78, "explorer" });
	fila.inserir({ 39, "calc" });
	fila.inserir({ 28, "word" });
	fila.inserir({ 66, "excel" });
	fila.inserir({ 70, "powerpoint" });
	fila.inserir({ 33, "onenote" });
	fila.exibir();
	cout << endl;

	cout << "Insere mais 1 elemento..." << endl;
	fila.inserir({ 50, "visualstudio" });
	fila.exibir();
	cout << endl;

	cout << "Remove 9 elementos..." << endl;
	cout << fila.remover() << " ";
	cout << fila.remover() << " ";
	cout << fila.remover() << " ";
	cout << fila.remover() << " ";
	cout << fila.remover() << " ";
	cout << fila.remover() << " ";
	cout << fila.remover() << " ";
	cout << fila.remover() << " ";
	cout << fila.remover() << " ";
	cout << endl << endl;

	system("pause");
	return 0;
}

