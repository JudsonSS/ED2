#include "Expression.h"
#include <iostream>
#include <stack>
using std::stack;
using std::cout;
using std::endl;

// --------------------------------------------------------

void Expression::Destroy(Vertex * pt)
{
	if (pt->esq != nullptr) Destroy(pt->esq);
	if (pt->dir != nullptr) Destroy(pt->dir);
	cout << pt->inf << " ";
	delete pt;
}

// --------------------------------------------------------

Expression::Expression(string exp)
{
	stack<Vertex*> pilha;

	for (unsigned i = 0; i < exp.size(); ++i)
	{
		if (exp[i] == ')')
		{
			Vertex * dir = pilha.top();	pilha.pop();
			Vertex * op  = pilha.top(); pilha.pop();
			Vertex * esq = pilha.top();	pilha.pop();
			op->esq = esq;
			op->dir = dir;
			pilha.push(op);
		}
		else if (exp[i] != '(')
		{
			Vertex * novo = new Vertex;
			novo->inf = exp[i];
			novo->esq = nullptr;
			novo->dir = nullptr;
			pilha.push(novo);
		}
	}

	raiz = pilha.top();
	pilha.pop();
}

// --------------------------------------------------------

Expression::~Expression()
{
	cout << "Destruindo arvore binaria na ordem:\n";
	Destroy(raiz);
	cout << endl;
}

// --------------------------------------------------------