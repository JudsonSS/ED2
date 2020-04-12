// ------------------------------------------------------------
// Fila de Prioridades - C++ estruturado com variáveis globais
// ------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

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

// ----------------------------------------------------
// protótipos

void inserir(Processo);
Processo remover();
void subir(int);
void descer(int);
void print();

// ----------------------------------------------------

int n = 0;
int Max = 10;
Processo * heap = new Processo[Max];

// ----------------------------------------------------

int main()
{
	cout << "Insere 8 elementos..." << endl;
	inserir({ 95, "notepad" });
	inserir({ 60, "paint" });
	inserir({ 78, "explorer" });
	inserir({ 39, "calc" });
	inserir({ 28, "word" });
	inserir({ 66, "excel" });
	inserir({ 70, "powerpoint" });
	inserir({ 33, "onenote" });
	print();
	cout << endl;

	cout << "Insere mais 1 elemento..." << endl;
	inserir({ 50, "visualstudio" });
	print();
	cout << endl;

	cout << "Remove 9 elementos..." << endl;
	cout << remover() << " ";
	cout << remover() << " ";
	cout << remover() << " ";
	cout << remover() << " ";
	cout << remover() << " ";
	cout << remover() << " ";
	cout << remover() << " ";
	cout << remover() << " ";
	cout << remover() << " ";
	cout << endl << endl;

	if (heap)
		delete[] heap;

	system("pause");
	return 0;
}

// ----------------------------------------------------

void inserir(Processo x)
{
	if (n < Max)
	{
		heap[n] = x;
		subir(n);
		n = n + 1;
	}
	else
		cout << "Fila de prioridades cheia" << endl;
}

// ----------------------------------------------------

Processo remover()
{
	// valor maximo da fila de prioridades
	Processo maximo = { 0, "" };

	if (n != 0)
	{
		maximo = heap[0];
		heap[0] = heap[n - 1];
		n = n - 1;
		descer(0);
	}
	else
		cout << "Fila de prioridades vazia" << endl;

	return maximo;
}

// ----------------------------------------------------

void subir(int i)
{
	Processo aux = heap[i];
	Processo prior = heap[i];
	int j = (i - 1) / 2;
	while (i > j)
	{
		if (prior > heap[j])
		{
			heap[i] = heap[j];
			i = j;
			j = (i - 1) / 2;
		}
		else
			j = i;
	}
	heap[i] = aux;
}

// ----------------------------------------------------

void descer(int i)
{
	Processo aux = heap[i];
	Processo prior = heap[i];
	int j = 2 * i + 1;
	while (j < n)
	{
		if (j < n - 1)
		{
			if (heap[j + 1] > heap[j])
				j = j + 1;
		}

		if (prior < heap[j])
		{
			heap[i] = heap[j];
			i = j;
			j = 2 * i + 1;
		}
		else
			j = n;
	}
	heap[i] = aux;
}

// ----------------------------------------------------

void print()
{
	for (int i = 0; i < n; ++i)
		cout << heap[i] << " ";
	cout << endl;
}

// ----------------------------------------------------