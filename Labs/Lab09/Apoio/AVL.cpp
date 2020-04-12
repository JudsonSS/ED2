#include <iostream>
using namespace std;

// --------------------------------------------------------

// Nó da árvore AVL


// --------------------------------------------------------

// Protótipos das funções
// void Inserir(x, pt, h);
// void Destruir(No * pt);
// void Caso1(pt, h);
// void Caso2(pt, h);

// --------------------------------------------------------

int main()
{
	No * ptraiz = nullptr;
	bool altura = false;
	Inserir(3, ptraiz, altura);
	Inserir(7, ptraiz, altura);
	Inserir(1, ptraiz, altura);
	Inserir(2, ptraiz, altura);
	Inserir(6, ptraiz, altura);
	Inserir(5, ptraiz, altura);
	Inserir(4, ptraiz, altura);

	cout << "Destruindo na ordem: " << endl;
	Destruir(ptraiz);
	cout << endl;

	system("pause");
	return 0;
}

// --------------------------------------------------------

void Inserir(x, pt, h)
{
	if (pt == nullptr)
	{
		pt = new No;
		pt->esq = nullptr;
		pt->dir = nullptr;
		pt->chave = x;
		pt->bal = 0;
		h = true;
	}
	else
	{
		if (x == pt->chave)
		{
			cout << "Insercao invalida, chave existente" << endl;
		}
		else
		{
			if (x < pt->chave)
			{
				Inserir(x, pt->esq, h);
				if (h)
				{
					switch (pt->bal)
					{
					case  1: pt->bal = 0; h = false; break;
					case  0: pt->bal = -1; break;
					case -1: Caso1(pt, h); break;
					}
				}
			}
			else
			{
				Inserir(x, pt->dir, h);
				if (h)
				{
					switch (pt->bal)
					{
					case -1: pt->bal = 0; h = false; break;
					case  0: pt->bal = 1; break;
					case  1: Caso2(pt, h); break;
					}
				}
			}
		}
	}
}

// --------------------------------------------------------

void Destruir(No * pt)
{
	if (pt->esq != nullptr) Destruir(pt->esq);
	if (pt->dir != nullptr) Destruir(pt->dir);
	cout << pt->chave << " ";
	delete pt;
}

// --------------------------------------------------------

void Caso1(pt, h)
{
	NoAVL ptu = pt->esq;

	if (ptu->bal == -1)
	{
		pt->esq = ptu->dir;
		ptu->dir = pt;
		pt->bal = 0;
		pt = ptu;
	}
	else
	{
		NoAVL ptv = ptu->dir;
		ptu->dir = ptv->esq;
		ptv->esq = ptu;
		pt->esq = ptv->dir;
		ptv->dir = pt;

		if (ptv->bal == -1)
			pt->bal = 1;
		else
			pt->bal = 0;

		if (ptv->bal == 1)
			ptu->bal = -1;
		else
			ptu->bal = 0;

		pt = ptv;
	}
	pt->bal = 0;
	h = false;
}

// --------------------------------------------------------

void Caso2(pt, h)
{
	NoAVL ptu = pt->dir;

	if (ptu->bal == 1)
	{
		pt->dir = ptu->esq;
		ptu->esq = pt;
		pt->bal = 0;
		pt = ptu;
	}
	else
	{
		NoAVL ptv = ptu->esq;
		ptu->esq = ptv->dir;
		ptv->dir = ptu;
		pt->dir = ptv->esq;
		ptv->esq = pt;

		if (ptv->bal == 1)
			pt->bal = -1;
		else
			pt->bal = 0;

		if (ptv->bal == -1)
			ptu->bal = 1;
		else
			ptu->bal = 0;

		pt = ptv;
	}
	pt->bal = 0;
	h = false;
}

// --------------------------------------------------------
