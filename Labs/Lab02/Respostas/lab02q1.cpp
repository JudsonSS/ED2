#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string texto;
	stack<char> pilha;

	cout << "Normal: ";
	cin >> texto;

	for (int i = 0; i < texto.size(); ++i)
		pilha.push(texto[i]);
	
	cout << "Invertido: ";
	while (!pilha.empty())
	{
		cout << pilha.top();
		pilha.pop();
	}
	cout << endl;

	system("pause");
	return 0;
}