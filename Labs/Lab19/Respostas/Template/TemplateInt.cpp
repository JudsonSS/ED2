// ------------------------------------------------------------
// Fila de Prioridades - C++ orientado a objetos
// ------------------------------------------------------------

#include "FilaPrioTemplate.h"

// ------------------------------------------------------------


int main()
{
	FilaPrio<int> fila;

	cout << "Insere 8 elementos..." << endl;
	fila.inserir(95);
	fila.inserir(60);
	fila.inserir(78);
	fila.inserir(39);
	fila.inserir(28);
	fila.inserir(66);
	fila.inserir(70);
	fila.inserir(33);
	fila.exibir();
	cout << endl;

	cout << "Insere mais 1 elemento..." << endl;
	fila.inserir(50);
	fila.exibir();
	cout << endl;

	cout << "Remove 9 elementos..." << endl;
	cout << fila.remover() << " ";
	cout << fila.remover() << " ";
	cout << fila.remover() << " ";
	cout << fila.remover() << " ";
	cout << fila.remover() << " ";
	cout << fila.remover() << " ";
	cout << fila.remover() << " ";
	cout << fila.remover() << " ";
	cout << fila.remover() << " ";
	cout << endl << endl;

	system("pause");
	return 0;
}

