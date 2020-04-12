#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Pessoa
{
	int id;
	string nome;
};

struct Id
{
	bool operator() (Pessoa a, Pessoa b) 
	{ return a.id < b.id; }
};

struct Name
{
	bool operator() (Pessoa a, Pessoa b) 
	{ return a.nome < b.nome; }
};

int main()
{
	ifstream fin;
	fin.open("alunos.txt");

	// testa se o arquivo foi aberto com sucesso
	if (!fin.is_open())
	{
		cout << "Arquivo nao encontrado!" << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	// lê conteúdo do arquivo para vetor
	vector<Pessoa> alunos;
	Pessoa temp;
	fin >> temp.id;
	while (fin.good())
	{
		fin >> temp.nome;
		alunos.push_back(temp);
		fin >> temp.id;
	}
	fin.close();

	// ordena vetor por Nome
	cout << "Ordem alfabetica: ";
	sort(alunos.begin(), alunos.end(), Name());
	for (auto elem : alunos)
		cout << elem.nome << " ";
	cout << endl;

	// ordena vetor por Id
	cout << "Ordem numérica: ";
	sort(alunos.begin(), alunos.end(), Id());
	for (auto elem : alunos)
		cout << elem.nome << " ";
	cout << endl;

	system("pause");
	return 0;
}