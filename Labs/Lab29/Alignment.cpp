#include <iostream>
using namespace std;

struct Data
{
	char ch;		// 1 -> 8
	double frac;	// 8 -> 8
	int num;		// 4 -> 8
};

struct Memo
{
	double frac;	// 8 -> 8
	int num;		// 4 -> 4
	char ch;		// 1 -> 4
};

struct Code
{
	char   ch1;		// 1 -> 2
	short  sho;		// 2 -> 2
	char   ch2;		// 1 -> 4
	float  flo;		// 4 -> 4
	int    num;		// 4 -> 4
	char   ch3;		// 1 -> 8
	//double dbl;   // 8 -> 8
};

struct Perf
{
	//double dbl;   // 8 -> 8
	float  flo;		// 4 -> 4
	int    num;		// 4 -> 4
	short  sho;		// 2 -> 2
	char   ch1;		// 1 -> 1	
	char   ch2;		// 1 -> 1	
	char   ch3;		// 1 -> 4
};

int main()
{
	cout << "Data\n";
	cout << "----------------------------------------------\n";
	cout << "Tamanho: " << sizeof(Data) << " bytes\n";
	cout << "Alinhamento: " << alignof(Data) << " bytes\n";
	cout << "----------------------------------------------\n\n";

	cout << "Memo\n";
	cout << "----------------------------------------------\n";
	cout << "Tamanho: " << sizeof(Memo) << " bytes\n";
	cout << "Alinhamento: " << alignof(Memo) << " bytes\n";
	cout << "----------------------------------------------\n\n";

	cout << "Code\n";
	cout << "----------------------------------------------\n";
	cout << "Tamanho: " << sizeof(Code) << " bytes\n";
	cout << "Alinhamento: " << alignof(Code) << " bytes\n";
	cout << "----------------------------------------------\n\n";

	cout << "Perf\n";
	cout << "----------------------------------------------\n";
	cout << "Tamanho: " << sizeof(Perf) << " bytes\n";
	cout << "Alinhamento: " << alignof(Perf) << " bytes\n";
	cout << "----------------------------------------------\n\n";

	system("pause");
	return 0;
}