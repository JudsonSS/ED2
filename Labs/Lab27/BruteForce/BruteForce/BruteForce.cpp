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
	while (fin.read((char*) &ch, sizeof(char)))
		vet[i++] = ch;
}

vector<size_t> StringMatching(char T[], string & P)
{
	vector<size_t> matches;
	size_t n = strlen(T);
	size_t m = P.size();

	size_t l = 0;
	while (l <= n - m)
	{
		size_t i = 0;
		size_t j = l;
		while (i < m && T[j] == P[i])
		{
			++j;
			++i;
		}
		if (i == m)
		{
			matches.push_back(l);
		}
		++l;
	}
	return matches;
}

int main()
{	
	locale::global(locale("pt-BR"));
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "___________________________\n\n";
	cout << "Algoritmo Força Bruta\n";
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