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
		void checkInput() const;
		void PrintTable();
		HuffmanCode()=delete;
		HuffmanCode(const HuffmanCode& other)=delete;
		const HuffmanCode& operator=(const HuffmanCode& other)=delete;
		HuffmanCode(const string& nameFile);
		~HuffmanCode();
		void ReadFromFile();
		void buildHuffman();
		void setCodes(TreeNode& huffNode, int* arr, int top);
		void printCode(TreeNode& huffNode, int* arr, int top);
		void GenerateHuffmanCode();
		void convertBSTtoMinHeap(TreeNode* treeNode);
		string getCodesTable() const;
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
		string _codesTable;
	};
}    