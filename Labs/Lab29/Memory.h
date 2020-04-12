
#ifndef _MEMORY_ARENA_
#define _MEMORY_ARENA_

using byte = unsigned char;
using uint = unsigned int;

class Arena
{
private:
	const uint headerSize = sizeof(byte*);
	uint   blockCount;
	uint   blockSize;
	byte * memory;
	byte * head;

public:
	Arena(uint dataCount, uint dataSize);
	~Arena();

	void * Alloc(void);
	void   Free(void * mem);
};

void * operator new(size_t sz, Arena & mp);
void operator delete(void * mem, Arena & mp);

#endif
