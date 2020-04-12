// testa a classe Expression

#include <iostream>
#include <string>
#include "Expression.h"
using namespace std;

int main()
{	
	cout << " Digite Expressao: ";
	string entrada;
	cin >> entrada;

	// bloco força destruição do objeto antes do system("pause")
	{
		Expression exp = Expression(entrada);
	}

	system("pause");
	return 0;
}