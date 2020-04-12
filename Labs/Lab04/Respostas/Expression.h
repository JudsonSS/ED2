// classe para representar express�es aritm�ticas

#include <string>
using std::string;

// --------------------------------------------------------

struct Vertex
{
	char inf;
	Vertex * esq;
	Vertex * dir;
};

// --------------------------------------------------------

class Expression
{
private: 
	Vertex * raiz;
	void Destroy(Vertex * pt);

public:
	Expression(string exp);
	~Expression();	
};

// --------------------------------------------------------
