#include "Memory.h" 
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

const int Max = 20000000;
int * vet[Max];

int main()
{
	cout << "Block Size: Header(";
	cout << sizeof(byte*) << ") + Data(" << sizeof(int) << ") = " << sizeof(byte*) + sizeof(int);
	cout << " bytes" << endl;

	// -----------------------------------------
	auto start = high_resolution_clock::now();
	// -----------------------------------------
	for (int i = 0; i < Max; ++i)
	{
		vet[i] = new int;
		*vet[i] = i;
	}
	for (int i = 0; i < Max; ++i)
	{
		delete vet[i];
	}
	// -----------------------------------------
	auto end = high_resolution_clock::now();
	// -----------------------------------------
	cout << "New: " << duration_cast<milliseconds>(end - start).count() << " milissegundos" << endl;

	////////////////////////////////////////////////////////////////////////////////////////////////

	Arena fast(Max, sizeof(int));
	
	// -----------------------------------------
	start = high_resolution_clock::now();
	// -----------------------------------------
	for (int i = 0; i < Max; ++i)
	{
		vet[i] = new(fast) int;
		*vet[i] = i;
	}
	for (int i = 0; i < Max; ++i)
	{
		// delete(fast) vet[i];
		operator delete(vet[i], fast);
	}
	// -----------------------------------------
	end = high_resolution_clock::now();
	// -----------------------------------------
	cout << "Arena: " << duration_cast<milliseconds>(end - start).count() << " milissegundos" << endl;

	system("pause");
	return 0;
}