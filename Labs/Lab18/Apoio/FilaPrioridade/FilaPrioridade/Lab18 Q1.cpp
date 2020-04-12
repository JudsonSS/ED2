#include <iostream>
using namespace std;

int main()
{
	int heap[] = { 95, 60, 78, 39, 28, 66, 70, 33 };

	system("pause");
	return 0;
}

// Algoritmo: Descer por um caminho da �rvore
//
// procedimento descer(i, n)
//   aux : = T[i]
//   prior : = T[i].chave
//   j = 2 * i
//   enquanto j <= n fa�a
//   |  se j < n ent�o
//   |  |  se T[j + 1].chave > T[j].chave ent�o
//   |  |  |   j = j + 1
//   |  se prior < T[j].chave ent�o
//   |  |  T[i] : = T[j]
//   |  |  i : = j
//   |  |  j : = 2 * i
//   |  sen�o
//   |  |  j : = n + 1
//   T[i] = aux