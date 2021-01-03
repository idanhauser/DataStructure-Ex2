#pragma once
#include <fstream>

#define new MYDEBUG_NEW
#ifdef _DEBUG
#define MYDEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#else
#define MYDEBUG_NEW new
#endif
#include "BSTree.h"
#include "MinHeap.h"
using namespace std;
namespace HuffmanCoding
{


	class HuffmanCode
	{
	public:
		void checkInput() const;
		HuffmanCode()=delete;
		HuffmanCode(const HuffmanCode& other)=delete;
		const HuffmanCode& operator=(const HuffmanCode& other)=delete;
		HuffmanCode(const string& nameFile);
		~HuffmanCode();
		void ReadFromFile();
		void buildHuffman();
		void GenerateHuffmanCode();
		void convertBSTtoMinHeap(TreeNode* treeNode);
		void printCodes(TreeNode& huffNode, int* arr,const int top);
	private:
		int _sum;
		int _maxSizeOfqueue;
		BSTree _charsCounter;
		MinHeap _queue;
		ifstream _infile;
		string _Output;
		bool _isValid;
		TreeNode* _huffTree;
		int heapSizeConst;
		int _heapSizeConst;

	};
}    