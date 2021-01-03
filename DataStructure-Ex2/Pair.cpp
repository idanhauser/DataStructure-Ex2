#include "Pair.h"

#include "Utils.h"
#define new MYDEBUG_NEW
#ifdef _DEBUG
#define MYDEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#else
#define MYDEBUG_NEW new
#endif
namespace HuffmanCoding
{
	Pair::Pair():_key(NON_PRINTABLE_CHARACTER),_freq(0)
	{
	}

	Pair::Pair(char key, int freq) : _key(key),
	                                   _freq(freq)
	{
	}

	Pair::Pair(const Pair& other)
	{
		_freq = other._freq;
		_key = other._key;
	}

	char Pair::getKey() const
	{
		return _key;
	}

	int Pair::getFreq() const
	{
		return _freq;
	}

	bool Pair::setKey(const char key) 
	{
		_key = key;
		return true;
	}

	bool Pair::setFreq(const int freq) 
	{
		_freq = freq;
		return true;
	}

	void Pair::operator++(int)
	{
		_freq++;
	}
}
