#include "ABB.h"

// --------------------------------------------------------

void Destruir(No * pt)
{
	if (pt->esq != nullptr) Destruir(pt->esq);
	if (pt->dir != nullptr) Destruir(pt->dir);
	delete pt;
}

// --------------------------------------------------------

void Inserir(No * raiz, int val)
{
	// cria novo nó a ser inserido na árvore
	No * z = new No;
	z->chave = val;
	z->esq = nullptr;
	z->dir = nullptr;
	z->pai = nullptr;

	No * p = nullptr;
	No * pt = raiz;

	while (pt != nullptr)
	{
		p = pt;
		if (z->chave < pt->chave)
			pt = pt->esq;
		else
			pt = pt->dir;
	}
	z->pai = p;
	
	if (p == nullptr)
	{
		raiz = z;   // árvore vazia
	}
	else
	{
		if (z->chave < p->chave)
			p->esq = z;
		else
			p->dir = z;
	}
}

// --------------------------------------------------------

No * Buscar(No * pt, int x)
{
	while ((pt != nullptr) && (x != pt->chave))
	{
		if (x < pt->chave)
			pt = pt->esq;
		else
			pt = pt->dir;
	}

	return pt;
}

// --------------------------------------------------------
