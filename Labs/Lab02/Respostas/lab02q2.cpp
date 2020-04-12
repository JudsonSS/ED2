#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("nums.txt");

	// testa se o arquivo foi aberto com sucesso
	if (!fin.is_open())
	{
		cout << "Arquivo nao encontrado!" << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	// l� conte�do do arquivo para vetor
	vector<int> vetnum;
	int num;
	fin >> num;
	while (fin.good())	
	{
		vetnum.push_back(num);
		fin >> num;
	}
	fin.close();

	// ordena vetor
	sort(vetnum.begin(), vetnum.end());

	// exibe n�meros ordenados
	for (auto elem : vetnum)
		cout << elem << " ";
	cout << endl;

	system("pause");
	return 0;
}