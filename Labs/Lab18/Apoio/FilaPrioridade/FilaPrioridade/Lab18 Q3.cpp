#include <iostream>
using namespace std;

int main()
{
	int vet[] = { 66, 39, 78, 95, 60, 33, 70, 28 };

	system("pause");
	return 0;
}

// Algoritmo: Ordena��o por Heap(Heapsort)
//
//	arranjar(n)
//	m = n
//	enquanto m > 1 fa�a
//	| L[1] <=> L[m]
//	| m = m - 1
//	| descer(1, m)