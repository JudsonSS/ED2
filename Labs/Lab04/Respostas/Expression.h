// classe para representar expressões aritméticas

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
