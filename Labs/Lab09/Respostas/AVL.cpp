#include "AVLTree.h"
#include <iostream>
using namespace std;

// --------------------------------------------------------

int main()
{
	// bloco para destruir objeto antes do system("pause");
	{
		AVLTree t = { 3,7,1,2,6,5,4 };
		t.Insert(8);
		t.Insert(9);
	}

	system("pause");
	return 0;
}

// --------------------------------------------------------

