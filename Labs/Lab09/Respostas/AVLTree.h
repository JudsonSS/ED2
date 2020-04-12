#include <initializer_list>
using std::initializer_list;

struct No
{
	int chave;
	No * esq;
	No * dir;
	int bal;
};

using NoAVL = No*;

class AVLTree
{
private:
	NoAVL raiz;

	void Destruir(NoAVL pt);
	void Inserir(int x, NoAVL & pt, bool & h);
	void Caso1(NoAVL & pt, bool & h);
	void Caso2(NoAVL & pt, bool & h);

public:
	AVLTree();
	AVLTree(initializer_list<int> lista);
	~AVLTree();
	void Insert(int num);
};
