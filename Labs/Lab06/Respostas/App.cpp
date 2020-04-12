#include <iostream>
#include "ABB.h"
using namespace std;

int main()
{
	ABB A = { 7,3,8,1,5,9,2,4,6 };

	cout << "Buscar elemento: ";
	int x;
	cin >> x;

	if (A.Buscar(x))
		cout << "Elemento encontrado" << endl;
	else
		cout << "Elemento ausente" << endl;

	system("pause");
	return 0;
}