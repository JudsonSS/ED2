#include <iostream>
#include <string>
using namespace std;

// ------------------------------------------------------------

template <typename Type>
class FilaPrio
{
private:
	int n;
	int Max;
	Type * heap;

	void subir(int);
	void descer(int);

public:
	FilaPrio();
	~FilaPrio();

	void inserir(Type);
	Type remover();
	void exibir();
};

// ----------------------------------------------------

template <typename Type>
FilaPrio<Type>::FilaPrio() : n(0), Max(0), heap(nullptr)
{
}

template <typename Type>
FilaPrio<Type>::~FilaPrio()
{
	if (heap)
		delete[] heap;
}


// ----------------------------------------------------

template <typename Type>
void FilaPrio<Type>::inserir(Type x)
{
	if (n >= Max)
	{
		Max = (n == 0 ? 1: 2 * n);
		Type * newHeap = new Type[Max];
		for (int i = 0; i < n; ++i)
			newHeap[i] = heap[i];
		delete[] heap;
		heap = newHeap;
	}

	heap[n] = x;
	subir(n);
	n = n + 1;
}

// ----------------------------------------------------

template <typename Type>
Type FilaPrio<Type>::remover()
{
	// valor maximo da fila de prioridades
	Type maximo = Type();

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

template <typename Type>
void FilaPrio<Type>::subir(int i)
{
	Type aux = heap[i];
	Type prior = heap[i];
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

template <typename Type>
void FilaPrio<Type>::descer(int i)
{
	Type aux = heap[i];
	Type prior = heap[i];
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

template <typename Type>
void FilaPrio<Type>::exibir()
{
	for (int i = 0; i < n; ++i)
		cout << heap[i] << " ";
	cout << endl;
}

// ----------------------------------------------------


