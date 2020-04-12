#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

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

int main()
{
	// aloca e destrói 10 milhoões de inteiros na pilha
	auto start = high_resolution_clock::now();
	for (int i = 0; i < 10000000; ++i)
		stack();
	auto end = high_resolution_clock::now();
	cout << "Stack:  " << duration_cast<milliseconds>(end - start).count() << " milliseconds" << endl;

	// aloca e destrói 10 milhoões de inteiros na heap
	start = high_resolution_clock::now();
	for (int i = 0; i < 10000000; ++i)
		heap();
	end = high_resolution_clock::now();
	cout << "Heap:  " << duration_cast<milliseconds>(end - start).count() << " milliseconds" << endl;

	system("pause");
	return 0;
}