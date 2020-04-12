#include <iostream> 
#include <chrono> 
#include <random>
#include <list>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std; 
using namespace std::chrono; 

// --------------------------------------------------------------------------
// variáveis globais
const int Tam = 1000;
list<int> numeros;

// --------------------------------------------------------------------------
// protótipos
void BuscarNormal(int);
void BuscarAuto(int);

// --------------------------------------------------------------------------

int main() 
{     
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> aleatorio(0, numeric_limits<int>::max());

	// escolha distribuição binomial ou uniforme
	//binomial_distribution<int> sorteio(999, 0.5);
	uniform_int_distribution<int> sorteio(0, 999);

	// gera números aleatórios
	for (int i = 0; i < Tam; ++i)
		numeros.push_back(aleatorio(mt));

	// vetor com cópia dos números aleatórios
	vector<int> vetor_numeros (begin(numeros), end(numeros));

	// gera sequência de busca dos elementos
	vector<int> buscas;
	for (int i = 0; i < Tam; ++i)
		buscas.push_back(vetor_numeros[sorteio(mt)]);

	// busca normal
	auto t0 = high_resolution_clock::now();
	// -------------------------------------------
	for (int i : buscas)
		BuscarNormal(i);
	// -------------------------------------------
	auto t1 = high_resolution_clock::now();       
	
	cout << "Busca Normal: "           
		 << duration_cast<milliseconds>(t1 - t0).count()
		 << " milisegundos" << endl; 

	// busca com autoajuste
	auto t2 = high_resolution_clock::now();
	// -------------------------------------------
	for (int i : buscas)
		BuscarAuto(i);
	// -------------------------------------------
	auto t3 = high_resolution_clock::now();

	cout << "Busca Auto: "
		<< duration_cast<milliseconds>(t3 - t2).count()
		<< " milisegundos" << endl;

	system("pause");     
	return 0; 
}

// --------------------------------------------------------------------------

void BuscarNormal(int num)
{
	auto i = find(begin(numeros), end(numeros), num);
}

// --------------------------------------------------------------------------

void BuscarAuto(int num)
{
	// implementando "mover para frente"
	auto i = find(begin(numeros), end(numeros), num);
	numeros.erase(i);
	numeros.insert(begin(numeros), num);
}
// --------------------------------------------------------------------------