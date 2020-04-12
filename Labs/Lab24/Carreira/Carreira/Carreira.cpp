#include <iostream>
#include <fstream>
#include <string>
using namespace std;

using uchar = unsigned char;

const uchar Marcador = '\x7F';	// caractere com código ASCII 127
const int   MaxSize = 255;		// valor máximo do unsigned char

void Encoder(ifstream & fin, ofstream & fout);
void Decoder(ifstream & fin, ofstream & fout);

int main()
{
	char option;

	do
	{
		cout << "___________________________\n\n";
		cout << "Comprimento de Carreira\n";
		cout << "___________________________\n\n";
		cout << "[C]odificar\n";
		cout << "[D]ecodificar\n";
		cout << "[S]air\n";
		cout << "___________________________\n\n";
		cout << "Escolha: ";
		cin >> option;
		option = tolower(option);

		if (option == 'c')
		{
			cout << endl;
			cout << "---------------------------\n";
			cout << "Codificador de Carreiras" << endl;
			cout << "---------------------------\n";

			// arquivo a ser comprimido 
			cout << "Comprimir: ";
			string entrada;
			cin >> entrada;

			ifstream fin(entrada, ios_base::in | ios_base::binary);
			if (fin.is_open())
			{
				// arquivo resultante da compressão
				cout << "Para arquivo: ";
				string saida;
				cin >> saida;

				ofstream fout(saida, ios_base::out | ios_base::trunc | ios_base::binary);

				if (fout.is_open())
				{
					cout << "Compactando arquivo...\n";
					Encoder(fin, fout);
					fin.close();
					fout.close();
					cout << "---------------------------\n";
					cout << endl;
				}
				else
				{
					fin.close();

					cout << endl;
					cout << "Falha na abertura!\n";
					cout << "---------------------------\n";
					cout << endl;
				}
			}
			else
			{
				cout << endl;
				cout << "Falha na abertura!\n";
				cout << "---------------------------\n";
				cout << endl;
			}
		}
		else if (option == 'd')
		{
			cout << endl;
			cout << "---------------------------\n";
			cout << "Decodificador de Carreiras" << endl;
			cout << "---------------------------\n";

			// arquivo a ser decodificado 
			cout << "Decodificar: ";
			string entrada;
			cin >> entrada;

			ifstream fin(entrada, ios_base::in | ios_base::binary);
			if (fin.is_open())
			{
				// arquivo resultante da compressão
				cout << "Para arquivo: ";
				string saida;
				cin >> saida;

				ofstream fout(saida, ios_base::out | ios_base::trunc | ios_base::binary);

				if (fout.is_open())
				{
					cout << "Descompactando arquivo...\n";
					Decoder(fin, fout);
					fin.close();
					fout.close();
					cout << "---------------------------\n";
					cout << endl;
				}
				else
				{
					fin.close();

					cout << endl;
					cout << "Falha na abertura!\n";
					cout << "---------------------------\n";
					cout << endl;
				}
			}
			else
			{
				cout << endl;
				cout << "Falha na abertura!\n";
				cout << "---------------------------\n";
				cout << endl;
			}
		}
	} while ((option != 's'));

	cout << endl;
	return 0;
}

// ------------------------------------------------------------------------------------

void Encoder(ifstream & fin, ofstream & fout)
{
	uchar ch;
	uchar ant;
	int tam = 1;

	// enquanto a leitura for bem sucedida
	fin.read((char*)&ch, sizeof(uchar));
	while (fin.good())
	{
		// acha tamanho da carreira
		ant = ch;
		while (fin.read((char*)&ch, sizeof(uchar)) && ant == ch)
			tam++;

		// se carreira é formada pelo marcador ou tem pelo menos tamanho 3
		if (ant == Marcador || tam >= 3)
		{
			// codifica a carreira como <m, n, ant>
			int n;
			do
			{
				n = tam > MaxSize ? MaxSize : tam;
				fout.write((char*)&Marcador, sizeof(uchar));
				fout.write((char*)&n, sizeof(uchar));
				fout.write((char*)&ant, sizeof(uchar));
				tam -= MaxSize;

			} while (tam > 0);
		}
		else
		{
			// carreira de tamanho 1 ou 2
			for (int i = 0; i < tam; ++i)
				fout.write((char*)&ant, sizeof(uchar));
		}
		tam = 1;
	}
}

// ------------------------------------------------------------------------------------

void Decoder(ifstream & fin, ofstream & fout)
{
	uchar m;
	uchar n;
	uchar c;

	// enquanto houver caracteres para ler
	while (fin.read((char*)&m, sizeof(uchar)))
	{
		if (m == Marcador)
		{
			// encontrado codificação <m, n, c>
			fin.read((char*)&n, sizeof(uchar));
			fin.read((char*)&c, sizeof(uchar));
			for (int i = 0; i < int(n); ++i)
				fout.write((char*)&c, sizeof(uchar));
		}
		else
		{
			// caractere literal encontrado
			fout.write((char*)&m, sizeof(uchar));
		}
	}
}