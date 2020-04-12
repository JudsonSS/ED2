#include "FilaPrio.h"

// ----------------------------------------------------

FilaPrio::FilaPrio()
{
	n = 0;
	Max = 10;
	heap = new Processo[Max];
}

FilaPrio::~FilaPrio()
{
	if (heap)
		delete [] heap;
}


// ----------------------------------------------------

void FilaPrio::inserir(Processo x)
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

Processo FilaPrio::remover()
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

void FilaPrio::subir(int i)
{
	Processo aux = heap[i];
	int j = (i - 1) / 2;
	while (i > j)
	{
		if (heap[i] > heap[j])
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

void FilaPrio::descer(int i)
{
	Processo aux = heap[i];
	int j = 2 * i + 1;
	while (j < n)
	{
		if (j < n - 1)
		{
			if (heap[j + 1] > heap[j])
				j = j + 1;
		}

		if (heap[i] < heap[j])
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

void FilaPrio::exibir()
{
	for (int i = 0; i < n; ++i)
		cout << heap[i] << " ";
	cout << endl;
}

// ----------------------------------------------------