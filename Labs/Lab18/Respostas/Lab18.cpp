#include <iostream>
using namespace std;

const int Tam = 8;
int heap[Tam] = { 66, 39, 78, 95, 60, 33, 70, 28 };

void heapsort(int n = Tam);
void arranjar(int n = Tam);
void descer(int i, int n = Tam);
void print(int v[], int tam = Tam);

int main()
{
	print(heap);
	arranjar();
	print(heap);
	heapsort();
	print(heap);
	system("pause");
	return 0;
}

void heapsort(int n)
{
	arranjar(n);
	int m = n-1;
	while (m > 0)
	{
		int temp = heap[0];
		heap[0] = heap[m];
		heap[m] = temp;
		descer(0, m);
		m = m - 1;
	}
}

void arranjar(int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		descer(i, n);
}

void descer(int i, int n)
{
	int aux = heap[i];
	int prior = heap[i];
	int j = 2 * i + 1;
	while (j < n)
	{
		if (j < n - 1)
			if (heap[j + 1] > heap[j])
				j = j + 1;
		
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

void print(int v[], int tam)
{
	for (int i = 0; i < tam; ++i)
		cout << v[i] << " ";
	cout << endl;
}