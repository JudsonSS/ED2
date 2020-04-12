// ------------------------------------------------------------
// Fila de Prioridades - C++ estruturado com variáveis globais
// ------------------------------------------------------------

#include <iostream>
using namespace std;

// ----------------------------------------------------
// protótipos

void inserir(int);
int  remover();
void subir(int);
void descer(int);
void exibir();

// ----------------------------------------------------

int n = 0;
int Max = 10;
int * heap = new int[Max];

// ----------------------------------------------------

int main()
{
	cout << "Insere 8 elementos..." << endl;
	inserir(95);
	inserir(60);
	inserir(78);
	inserir(39);
	inserir(28);
	inserir(66);
	inserir(70);
	inserir(33);
	exibir();
	cout << endl;

	cout << "Insere mais 1 elemento..." << endl;
	inserir(50);
	exibir();
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

	delete[] heap;

	system("pause");
	return 0;
}

// ----------------------------------------------------

void inserir(int x)
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

int remover()
{
	// maior valor da fila de prioridades
	int maximo = 0;

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
	int prior = heap[i];
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
	heap[i] = prior;
}

// ----------------------------------------------------

void descer(int i)
{
	int prior = heap[i];
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
	heap[i] = prior;
}

// ----------------------------------------------------

void exibir()
{
	for (int i = 0; i < n; ++i)
		cout << heap[i] << " ";
	cout << endl;
}

// ----------------------------------------------------