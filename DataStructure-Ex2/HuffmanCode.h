#pragma once
#include <fstream>

#define new MYDEBUG_NEW
#ifdef _DEBUG
#define MYDEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#else
#define MYDEBUG_NEW new
#endif
#include <sstream>
#include <string>
#include "BSTree.h"
#include "MinHeap.h"
using namespace std;
namespace HuffmanCoding
{


	class HuffmanCode
	{
	public:
		HuffmanCode(const string& nameFile);
		void checkInput() const;
		HuffmanCode()=delete;
		HuffmanCode(const HuffmanCode& other)=delete;
		const HuffmanCode& operator=(const HuffmanCode& other)=delete;
		~HuffmanCode();
		void GenerateHuffmanCode();
		string getCodesTable() const;
		bool isValid() const;
		int getWeightOfHuffman() const;
		friend ostream& operator<<(ostream& os, const HuffmanCode& table);

		
	private:
	//members:
		int _sum;
		int _phySizeOfqueue;
		BSTree _charsCounter;
		MinHeap _mQueue;
		ifstream _infile;
		string _Output;
		bool _isValid;
		TreeNode* _huffTree;
		int heapSizeConst;
		string _codesTable;
		//functions
		void setCodes(TreeNode& huffNode, int* arr, int top);
		void storeCodeInTable(TreeNode& huffNode, int* arr, int top);
		void readFromFile();
		void buildHuffman();
		void convertBSTtoMinHeap(TreeNode* treeNode);

	};
}    