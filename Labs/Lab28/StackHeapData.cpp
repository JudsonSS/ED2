#include <iostream>
using namespace std;

//int data[268435456] = { 0 };  // 1GB = Data OK

int main()
{
	//int stack[268435456] = { 0 };		// 1GB = Stack Overflow
	int * heap = new int[268435456];	// 1GB = Heap OK

	system("pause");
	return 0;
}