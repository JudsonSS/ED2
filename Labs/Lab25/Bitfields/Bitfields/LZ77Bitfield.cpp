#include <iostream>
using namespace std;

using ushort = unsigned short;

struct code
{
	ushort jump : 12;
	ushort length : 4;
};

int main()
{
	code n;
	n.jump = 4095;
	n.length = 15;
	cout << n.jump << " " << n.length << endl;
	n.jump++;
	n.length++;
	cout << n.jump << " " << n.length << endl;
	cout << sizeof(code) << endl;

	system("pause");
	return 0;
}