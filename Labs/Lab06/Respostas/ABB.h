#include <initializer_list>
using std::initializer_list;

// --------------------------------------------------------

struct No
{
	int chave;
	No * esq;
	No * dir;
	No * pai;
};

// --------------------------------------------------------

class ABB
{
private:
	No * raiz;
	void Destruir(No * pt);

public:
	ABB(initializer_list<int> lista);
	~ABB();

	void Inserir(int val);
	No * Buscar(int val);
};

// --------------------------------------------------------