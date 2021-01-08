#pragma once
#include <fstream>



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
		~HuffmanCode();
		void GenerateHuffmanCode();
		string getCodesTable() const;
		bool isValid() const;
		int getWeightOfHuffman() const;
		friend ostream& operator<<(ostream& os, const HuffmanCode& table);
		HuffmanCode(const HuffmanCode& other) = delete;
		const HuffmanCode& operator=(const HuffmanCode& other) = delete;
		
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
		int _heapSizeConst;
		string _codesTable;

		//functions
		void setCodes(TreeNode& huffNode, int* arr, int top);
		void storeCodeInTable(TreeNode& huffNode, int* arr, int top);
		void readFromFile();
		void buildHuffman();
		void convertBSTtoMinHeap(TreeNode* treeNode);

	};
}    