#pragma once
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
		~Pair()=default;
		char getKey() const;
		int getFreq() const;
		bool setKey(const char key);
		bool setFreq(const int freq);
		void operator++(int );
		//good to use defult operator for =
	private:
		char _key;
		int _freq;
	};
}