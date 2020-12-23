#pragma once
#include <fstream>

#include "BSTree.h"
#include "MinHeap.h"

namespace HuffmanCoding
{


	class HuffmanCode
	{
	private:
		int _maxSizeOfqueue;
		BSTree _charsCounter;
		MinHeap _queue;
		ifstream _infile;
		string _Output;
		bool _isValid;
	public:
		void checkInput();
		HuffmanCode(const string& namefile);
		void ReadFromFile();
		void GenerateHuffmanCode();
	};
}