#pragma once
#include <ostream>
using namespace std;
#define new MYDEBUG_NEW
#ifdef _DEBUG
#define MYDEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#else
#define MYDEBUG_NEW new
#endif
namespace HuffmanCoding
{
	class Pair
	{

	public:
		Pair();
		Pair(char key, int freq);
		Pair(const Pair& other);
		~Pair() = default;
		char getKey() const;
		int getFreq() const;
		const Pair& getPair() const;
		bool setKey(char key);
		bool setFreq(int freq);
		void operator++(int);
		friend ostream& operator<<(ostream& os, const Pair& pair);
		//good to use defult operator for =
	private:
		char _key;
		int _freq;
	};
}