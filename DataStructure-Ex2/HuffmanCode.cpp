#include "HuffmanCode.h"
#include <stdlib.h>
#include <string>

#include "Utils.h"

using namespace std;
#include <iostream>
namespace HuffmanCoding
{
	/// <summary>
	/// checks if file is ok, and we can read text from it.
	/// </summary>
	void HuffmanCode::checkInput() const
	{
		if (!_isValid)
		{
			cout << _Output;
			exit(1);
		}
	}


	HuffmanCode::HuffmanCode(const string& nameFile) : _sum(0), _phySizeOfqueue(0), _charsCounter(), _mQueue(),
		_infile(nameFile), _Output(""), _isValid(true), _huffTree(), _codesTable("") 
	{
		readFromFile();//updating the member _phySizeOfqueue
		checkInput();

		_mQueue = MinHeap(_phySizeOfqueue);//init queue

	}

	HuffmanCode::~HuffmanCode()
	{
		delete _huffTree;
		_huffTree = nullptr;

	}
	/// <summary>
	/// reads chars from file and store the into the bst.
	/// </summary>
	void HuffmanCode::readFromFile()
	{
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

			Pair data(val, 0);
			_charsCounter.Insert(data);
			_infile >> std::noskipws >> val;
		}
		_infile.close();
		cout << endl;
		_phySizeOfqueue = _charsCounter.getSize();
	}

	/// <summary>
	/// this function build huffman tree by the algoritem we learn in class
	/// Dequeue the two nodes with the lowest weight by examining the fronts of both queues.
	///Create a new internal node, with the two just - removed nodes as children(either node can be either child) and the sum of their weights as the new weight.
	///Enqueue the new node into the rear of the second queue.
	///The remaining node is the root node; the tree has now been generated.
	/// </summary>
	void HuffmanCode::buildHuffman()
	{
		TreeNode* minNode1;
		TreeNode* minNode2;
		TreeNode* newNode;
		Pair item(NON_PRINTABLE_CHARACTER, 0);
		const int size = _mQueue.getHeapSize() - 1;
		
		for (int i = 0; i < size; i++) {
			minNode1 = &_mQueue.DeleteMin();
			minNode2 = &_mQueue.DeleteMin();
			item.setFreq(minNode1->getData().getFreq() + minNode2->getData().getFreq());
			newNode = new TreeNode(item, minNode1, minNode2);
			_mQueue.insert(*newNode);
		}
		_huffTree = &(_mQueue.DeleteMin());
	}

	/// <summary>
	/// set the code on tree for each charater from the file.
	/// </summary>
	/// <param name="huffNode"> Huffman tree</param>
	/// <param name="arr">the arr which stores the code.</param>
	/// <param name="top">index</param>
	void HuffmanCode::setCodes(TreeNode& huffNode, int* arr, const int top)
	{
		if (huffNode.getLeft()) {

			arr[top] = 0;
			setCodes(*huffNode.getLeft(), arr, top + 1);
		}

		if (huffNode.getRight()) {

			arr[top] = 1;
			setCodes(*huffNode.getRight(), arr, top + 1);
		}
		storeCodeInTable(huffNode, arr, top);


	}
	/// <summary>
	/// this function takes the code from the arr and puts it into the table with the char it present
	/// </summary>
	/// <param name="huffNode"></param>
	/// <param name="arr"></param>
	/// <param name="top"></param>
	void HuffmanCode::storeCodeInTable(TreeNode& huffNode, int* arr, const int top)
	{
		if (huffNode.getRight() == nullptr && huffNode.getLeft() == nullptr) {
			const char ch = huffNode.getData().getKey();
			if ((ch != '\n') && (ch != '\t'))
			{
				_codesTable.append("'");
				_codesTable += ch;
				_codesTable.append("' - ");
			}
			else if (ch=='\n')
			{//we need to print "new line char '\n'
				_codesTable.append("'\\n' -");
			}
			else
			{//we need to print "new line char '\t'
				_codesTable.append("'\\t' -");
			}
			_sum += top * huffNode.getData().getFreq();
			for (int i = 0; i < top; ++i)
			{
				_codesTable += to_string(arr[i]);

			}
			if (top == 0)
			{
				_codesTable += to_string(arr[top]);
				_sum += huffNode.getData().getFreq();
			}
			_codesTable.append("\n");

		}

	}
	/// <summary>
	/// this function is the "main" function in this class. it manages all the process.
	/// </summary>
	void HuffmanCode::GenerateHuffmanCode()
	{
		convertBSTtoMinHeap(_charsCounter.getRoot());
		buildHuffman();
		int size = _mQueue.getPhyHeapSize();
		int* arr = new int[size];
		arr[0] = 1;
		_codesTable += "Character encoding: \n";
		setCodes(*_huffTree, arr, 0);
		_codesTable += "\nEncoded file weight: " + to_string(_sum) + "\n";

		delete[] arr;
	}

	/// <summary>
	/// this function reads the bst and any node in the tree it takes into the heap.
	/// </summary>
	/// <param name="treeNode"></param>
	void HuffmanCode::convertBSTtoMinHeap(TreeNode* treeNode)
	{
		if (treeNode == nullptr)
		{
			return;
		}
		convertBSTtoMinHeap(treeNode->getLeft());
		convertBSTtoMinHeap(treeNode->getRight());
		treeNode->setLeft(nullptr);
		treeNode->setRight(nullptr);
		_mQueue.insert(*treeNode);

	}

	string HuffmanCode::getCodesTable() const
	{
		return _codesTable;
	}

	bool HuffmanCode::isValid() const
	{
		return _isValid;
	}

	int HuffmanCode::getWeightOfHuffman() const
	{
		return _sum;
	}
	/// <summary>
	/// prints the tables of huffman and the codes.
	/// </summary>
	ostream& operator<<(ostream& os, const HuffmanCode& table)
	{
		os << table._codesTable;

		return os;

	}
}
