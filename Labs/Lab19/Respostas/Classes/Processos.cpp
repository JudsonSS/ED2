// ------------------------------------------------------------
// Fila de Prioridades - C++ orientado a objetos
// ------------------------------------------------------------

#include "FilaPrio.h"

int main()
{
	FilaPrio fila;
	cout << "Insere 8 elementos..." << endl;
	fila.inserir({ 95, "notepad" });
	fila.inserir({ 60, "paint" });
	fila.inserir({ 78, "explorer" });
	fila.inserir({ 39, "calc" });
	fila.inserir({ 28, "word" });
	fila.inserir({ 66, "excel" });
	fila.inserir({ 70, "powerpoint" });
	fila.inserir({ 33, "onenote" });
	fila.exibir();
	cout << endl;

	cout << "Insere mais 1 elemento..." << endl;
	fila.inserir({ 50, "visualstudio" });
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

