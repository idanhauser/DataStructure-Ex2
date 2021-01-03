﻿#include "HuffmanCode.h"
#include <stdlib.h>
#include <string>

#include "Utils.h"
#define new MYDEBUG_NEW
#ifdef _DEBUG
#define MYDEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#else
#define MYDEBUG_NEW new
#endif
using namespace std;
#include <iostream>
namespace HuffmanCoding
{
	void HuffmanCode::checkInput() const
	{
		if (!_isValid)
		{
			cout << _Output;
			exit(1);
		}
	}

	HuffmanCode::HuffmanCode(const string& nameFile) : _sum(0), _maxSizeOfqueue(0), _charsCounter(),_queue(),
	                                                   _infile(nameFile), _Output(""), _isValid(true), _huffTree()
	{
		ReadFromFile();//updating the member __maxSizeOfqueue
		checkInput();
	
		_queue = MinHeap(_maxSizeOfqueue);//init queue
		
	}

	HuffmanCode::~HuffmanCode()
	{
		delete _huffTree;
		_huffTree = nullptr;

	}

	void HuffmanCode::ReadFromFile()
	{
		int counter = 0;
		char val;
		if (!_infile) {
			_Output = "Error with infile. \n";
			_isValid = false;
			return;
		}

		_infile >> std::noskipws >> val;
		while (!_infile.eof()) {
			if (!_infile.good()) {
				_Output = "Error reading. \n";
				_isValid = false;
				return;
			}

			Pair data(val,0);
			_charsCounter.Insert(data);
			counter++;

			_infile >> std::noskipws >> val;
		}
		_infile.close();
		cout << endl;
		_maxSizeOfqueue = _charsCounter.getSize();
	}

	void HuffmanCode::buildHuffman()
	{
		TreeNode* minNode1;
		TreeNode* minNode2;
		TreeNode* newNode;
		Pair item(NON_PRINTABLE_CHARACTER,0);
		const int size = _queue.getHeapSize() - 1; 


		for (int i = 0; i < size; i++) {


			minNode1 = &_queue.DeleteMin();
			minNode2 = &_queue.DeleteMin();
			item.setFreq(minNode1->getData().getFreq() + minNode2->getData().getFreq());
			newNode = new TreeNode(item, minNode1, minNode2);


			_queue.insert(*newNode);
		}
		_huffTree = &(_queue.DeleteMin());
	}

	void HuffmanCode::printCodes(TreeNode& huffNode, int* arr,const int top)
	{
		if (huffNode.getLeft()) {

			arr[top] = 0;
			printCodes(*huffNode.getLeft(), arr, top + 1);
		}

		if (huffNode.getRight()) {

			arr[top] = 1;
			printCodes(*huffNode.getRight(), arr, top + 1);
		}


		if (huffNode.getRight() == nullptr && huffNode.getLeft() == nullptr) {
			if (huffNode.getData().getKey() != '\n')
			{
				cout << "'" << huffNode.getData().getKey() << "' - ";
			}
			else
			{
				cout << "'" << "\\n" << "' - ";
			}
			_sum += top * huffNode.getData().getFreq();
			for (int i = 0; i < top; ++i)
			{
				cout << arr[i];

			}
			if(top==0)
			{
				cout << arr[top];
				_sum += huffNode.getData().getFreq();
			}

			cout << endl;

		}

	}

	void HuffmanCode::GenerateHuffmanCode()
	{
		convertBSTtoMinHeap(_charsCounter.getRoot());
		buildHuffman();
		int size = _queue.getPhyHeapSize();
		int* arr = new int[size];
		arr[0] = 1;
		cout << "Character encoding:" << endl;
		printCodes(*_huffTree, arr, 0);
		cout << "Encoded file weight: " << _sum << " bits.";
		delete[] arr;
	}

	void HuffmanCode::convertBSTtoMinHeap(TreeNode* treeNode)
	{
		if (treeNode == nullptr)
		{
			return;
		}
		convertBSTtoMinHeap(treeNode->getLeft());
		convertBSTtoMinHeap(treeNode->getRight());
		treeNode->setLeft(nullptr);
		treeNode->setright(nullptr);
		_queue.insert(*treeNode);
	
	}
}
