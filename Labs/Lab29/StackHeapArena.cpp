#include "Memory.h"
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

const int Max = 10000000;
Arena fast(Max, sizeof(int));

// aloca um inteiro na pilha
void stack()
{
	int a = 5;
}

// aloca um inteiro na heap
void heap()
{
	int * p = new int;
	*p = 5;
	delete p;
}

// aloca um inteiro na arena
void arena()
{
	int * p = new(fast) int;
	*p = 5;
	operator delete (p, fast);
}

int main()
{
	// aloca e destrói 10 milhoões de inteiros na pilha
	auto start = high_resolution_clock::now();
	// ------------------------------------------------------------------
	for (int i = 0; i < Max; ++i)
		stack();
	// ------------------------------------------------------------------
	auto end = high_resolution_clock::now();
	cout << "Stack: ";
	cout.width(4);
	cout << right; 
	cout << duration_cast<milliseconds>(end - start).count() << " milissegundos" << endl;

	// aloca e destrói 10 milhoões de inteiros na heap
	start = high_resolution_clock::now();
	// ------------------------------------------------------------------
	for (int i = 0; i < Max; ++i)
		heap();
	end = high_resolution_clock::now();
	// ------------------------------------------------------------------

	cout << "Heap:  "; 
	cout.width(4);
	cout << right;
	cout << duration_cast<milliseconds>(end - start).count() << " milissegundos" << endl;

	// aloca e destrói 10 milhoões de inteiros na arena
	start = high_resolution_clock::now();
	// ------------------------------------------------------------------
	for (int i = 0; i < Max; ++i)
		arena();
	end = high_resolution_clock::now();
	// ------------------------------------------------------------------

	cout << "Arena: ";
	cout.width(4);
	cout << right; 
	cout << duration_cast<milliseconds>(end - start).count() << " milissegundos" << endl;

	system("pause");
	return 0;
}