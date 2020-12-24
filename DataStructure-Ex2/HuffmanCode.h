#pragma once
#include <fstream>



#include "BSTree.h"
#include "MinHeap.h"

namespace HuffmanCoding
{


	class HuffmanCode
	{
	private:
		int _sum;
		int _maxSizeOfqueue;
		BSTree _charsCounter;
		MinHeap _queue;
		ifstream _infile;
		string _Output;
		bool _isValid;
		TreeNode* _huffTree;
	public:
		void checkInput();
		HuffmanCode(const string& namefile);
		void ReadFromFile();
		void buildHuffman();
		void GenerateHuffmanCode();
		void convertBSTtoMinHeap(TreeNode* treeNode);
		void printCodes(TreeNode* huffNode, int arr[], int top);
        
	};
}    