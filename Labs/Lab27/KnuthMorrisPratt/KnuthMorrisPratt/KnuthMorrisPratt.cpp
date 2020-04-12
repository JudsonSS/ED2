#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <locale>
#include <chrono>
#include "windows.h"
using namespace std;
using namespace std::chrono;

unsigned OpenFile(ifstream & ifs, string & file)
{
	ifs.open(file, ios_base::ate | ios_base::binary);

	unsigned size = 0;
	if (ifs.is_open())
	{
		size = static_cast<unsigned>(ifs.tellg());
		ifs.seekg(0);
	}

	return size;
}

void ReadFile(ifstream & fin, char vet[])
{
	int i = 0;
	char ch;
	while (fin.read((char*)&ch, sizeof(char)))
		vet[i++] = ch;
}

void PreCalcD(const char T[], const string & P, int D[])
{
	size_t m = P.size();
	D[0] = -1;
	int j = D[1] = 0;
	int k = 1;

	while (k < m)
	{
		if (P[k] == P[j])
		{
			k = k + 1;
			j = j + 1;
			D[k] = j;
		}
		else
		{
			if (j == 0)
			{
				k = k + 1;
				D[k] = 0;
			}
			else
			{
				j = D[j];
			}
		}
	}
}

vector<size_t> StringMatching(char T[], string & P)
{
	vector<size_t> matches;
	size_t n = strlen(T);
	size_t m = P.size();
	int * d = new int[m+1];
	
	// calcula vetor d
	PreCalcD(T, P, d);

	// casamento de cadeias
	size_t i = 0, j = 0;
	while (i <= n-m)
	{
		while (j == -1 || j < m && T[i] == P[j])
		{
			++i;
			++j;
		}
		if (j == m)
		{
			matches.push_back(i - m);
		}
		j = d[j];		
	}

	delete[] d;
	return matches;
}

int main()
{
	locale::global(locale("pt-BR"));
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "___________________________\n\n";
	cout << "Knuth Morris e Pratt\n";
	cout << "___________________________\n\n";

	cout << "Arquivo Texto: ";
	string file_name;
	cin >> file_name;

	// abre arquivo e captura seu tamanho em bytes
	ifstream fin;
	unsigned file_size = OpenFile(fin, file_name);

	if (file_size)
	{
		char * text = new char[file_size];

		// transfere texto do arquivo para um vetor
		ReadFile(fin, text);

		cout << "Padrão: ";
		string pattern;
		cin >> pattern;

		// busca padrão dentro do texto
		auto t0 = high_resolution_clock::now();
		// ---------------------------------------------------
		vector<size_t> positions = StringMatching(text, pattern);
		// ---------------------------------------------------
		auto t1 = high_resolution_clock::now();

		cout << "\nTempo de busca: " << duration_cast<microseconds>(t1 - t0).count() / double(1000) << " milissegundos\n";


		if (positions.size())
		{
			cout << "Total de casamentos: " << positions.size() << endl;
			cout << "-----------------------------------------------------------------------------\n";

			int i = 0;
			for (auto pos : positions)
			{
				// exibe texto até a posição do próximo casamento
				while (i < pos)
					cout << text[i++];

				// muda cor do texto para vermelho
				SetConsoleTextAttribute(hConsole, 12);
				// exibe texto casado
				while (static_cast<unsigned>(i) < pos + pattern.size())
					cout << text[i++];
				// volta a cor do texto para branco
				SetConsoleTextAttribute(hConsole, 7);
			}

			// exibe o resto do texto
			while (static_cast<unsigned>(i) < file_size)
				cout << text[i++];

			cout << endl;
			cout << "-----------------------------------------------------------------------------\n";
		}
		else
		{
			cout << "Nenhum casamento encontrado.\n\n";
		}
		delete[] text;
	}
	else
	{
		cout << "Arquivo vazio ou inexistente!\n\n";
	}

	system("pause");
	return 0;
}