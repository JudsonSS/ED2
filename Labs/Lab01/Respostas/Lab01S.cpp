#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// -------------------------------------

void insertion(int[], int);
void bubble(int[], int);

// -------------------------------------

int main()
{
	// Insertion Sort
	int vetA[50] = 
	{ 
		49, 48, 47, 46, 45, 44, 43, 42, 41, 40,
		39, 38, 37, 36, 35, 34, 33, 32, 31, 30,
		29, 28, 27, 26, 25, 24, 23, 22, 21, 20,
		19, 18, 17, 16, 15, 14, 13, 12, 11, 10,
		9, 8, 7, 6, 5, 4, 3, 2, 1, 0 
	};
	auto t0 = high_resolution_clock::now();
	insertion(vetA, 50);
	auto t1 = high_resolution_clock::now();
	cout << "Insertion Sort: " << duration_cast<nanoseconds>(t1 - t0).count() << " nanosegundos" << endl;

	// Bubble Sort
	int vetB[50] =
	{
		49, 48, 47, 46, 45, 44, 43, 42, 41, 40,
		39, 38, 37, 36, 35, 34, 33, 32, 31, 30,
		29, 28, 27, 26, 25, 24, 23, 22, 21, 20,
		19, 18, 17, 16, 15, 14, 13, 12, 11, 10,
		9, 8, 7, 6, 5, 4, 3, 2, 1, 0
	};
	t0 = high_resolution_clock::now();
	bubble(vetB, 50);
	t1 = high_resolution_clock::now();
	cout << "Bubble Sort: "	<< duration_cast<nanoseconds>(t1 - t0).count() << " nanosegundos" << endl;

	system("pause");
	return 0;
}

// -------------------------------------


void insertion(int A[], int n) 
{
	for (int j = 1; j < n; ++j)
	{
		int chave = A[j];
		int i = j - 1;
		while (i >= 0 && A[i] > chave)
		{
			A[i + 1] = A[i];
			i = i - 1;
		}
		A[i + 1] = chave;
	}
}

// -------------------------------------


void trocar(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void bubble(int A[], int n)
{
	bool troca;
	do
	{
		troca = false;
		for (int i = 0; i < n - 1; ++i)
		{
			if (A[i] > A[i + 1])
			{
				trocar(A[i], A[i + 1]);
				troca = true;
			}
		}

	} while (troca);
}

// -------------------------------------

