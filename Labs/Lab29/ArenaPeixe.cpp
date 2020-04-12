#include "Memory.h" 
#include <iostream>
#include <chrono>
#include <string>
using namespace std;
using namespace std::chrono;

struct peixe
{
	int tipo;
	int peso;
	int comp; 
};

const int Max = 20000000;
peixe * vet[Max];

int main()
{
	cout << "Block Size: Header(";
	cout << sizeof(byte*) << ") + Data(" << sizeof(peixe) << ") = " << sizeof(byte*) + sizeof(peixe);
	cout << " bytes" << endl;

	// -------------------------------------
	auto start = high_resolution_clock::now();
	// -------------------------------------
	for (int i = 0; i < Max; ++i)
	{
		vet[i] = new peixe { i, i, i };
	}
	for (int i = 0; i < Max; ++i)
	{
		delete vet[i];
	}
	// -------------------------------------
	auto end = high_resolution_clock::now();
	// -------------------------------------
	cout << "New: " << duration_cast<milliseconds>(end - start).count() << " milisegundos" << endl;

	///////////////////////////////////////////////////////////////////////////////////////////////

	Arena fast(Max, sizeof(peixe));

	// -------------------------------------
	start = high_resolution_clock::now();
	// -------------------------------------
	for (int i = 0; i < Max; ++i)
	{
		vet[i] = new(fast) peixe { i, i, i };
	}
	for (int i = 0; i < Max; ++i)
	{
		// delete(fast) vet[i];
		operator delete(vet[i], fast);
	}
	// -------------------------------------
	end = high_resolution_clock::now();
	// -------------------------------------
	cout << "Mem: " << duration_cast<milliseconds>(end - start).count() << " milisegundos" << endl;

	system("pause");
	return 0;
}