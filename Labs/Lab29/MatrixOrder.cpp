#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

const unsigned int Size = 5000;

int matrix[Size][Size];

void ColumnOrder();
void RowOrder();

int main()
{
	// -----------------------------------------
	auto start = high_resolution_clock::now();
	// -----------------------------------------
	ColumnOrder();
	// -----------------------------------------
	auto end = high_resolution_clock::now();
	// -----------------------------------------
	cout << "Coluna: " << duration_cast<milliseconds>(end - start).count() << " milissegundos" << endl;

	////////////////////////////////////////////////////////////////////////////////////////////////////////

	// -----------------------------------------
	start = high_resolution_clock::now();
	// -----------------------------------------
	RowOrder();
	// -----------------------------------------
	end = high_resolution_clock::now();
	// -----------------------------------------
	cout << "Linha : " << duration_cast<milliseconds>(end - start).count() << " milissegundos" << endl;

	system("pause");
	return 0;
}

void ColumnOrder()
{
	for (int j = 0; j < Size; ++j)
		for (int i = 0; i < Size; ++i)
			matrix[i][j] = 0;
}

void RowOrder()
{
	for (int i = 0; i < Size; ++i)
		for (int j = 0; j < Size; ++j)
			matrix[i][j] = 0;
}
	