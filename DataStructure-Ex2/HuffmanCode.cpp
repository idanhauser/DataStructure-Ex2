#include "HuffmanCode.h"

namespace HuffmanCoding
{
	void HuffmanCode::checkInput()
	{
		if (!_isValid)
		{
			cout << _Output;
			exit(1);
		}
	}

	HuffmanCode::HuffmanCode(const string& namefile) :_maxSizeOfqueue(0), _infile(namefile), _isValid(true)
	{
		ReadFromFile();//updating the member __maxSizeOfqueue
		checkInput();
		_queue = MinHeap(_maxSizeOfqueue);//init queue
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

			Pair data;
			data.freq = 0;
			data.key = val;
			cout << "key " << data.key << " : " << data.freq << endl;
			_charsCounter.Insert(data);
			counter++;

			_infile >> std::noskipws >> val;
		}
		_infile.close();
		cout << endl;
		_maxSizeOfqueue = counter;
	}

	void HuffmanCode::buildHuffman()
	{
		int		i, n;
		TreeNode* minNode1, * minNode2, * newNode;
		Pair item;
		item.key = '%';

		/* at this point, the heap is a "forest" of singleton trees */

		n = _queue.getHeapSize() - 1; /* heap_size isn't loop invariant! */

		/* if we insert two things and remove one each time,
		 * at the end of heap_size-1 iterations, there will be
		 * one tree left in the heap
		 */
		for (i = 0; i < n; i++) {

			/* make a new node z from the two least frequent
			 * nodes x and y
			 */

			minNode1 = _queue.DeleteMin();
			minNode2 = _queue.DeleteMin();
			item.freq = minNode1->getData().freq + minNode2->getData().freq;
			newNode = new TreeNode(item, minNode1, minNode2);
			/* z's frequency is the sum of x and y */


			/* put this back in the queue */

			_queue.insert(newNode);
		}

		/* return the only thing left in the queue, the whole Huffman tree */

		_huffTree = _queue.DeleteMin();
	}
	// Prints huffman codes from the root of Huffman Tree. 
// It uses arr[] to store codes 
	void HuffmanCode::printCodes(TreeNode* huffNode, int arr[], int top)

	{

		// Assign 0 to left edge and recur 
		if (huffNode->getLeft()) {

			arr[top] = 0;
			printCodes(huffNode->getLeft(), arr, top + 1);
		}

		// Assign 1 to right edge and recur 
		if (huffNode->getRight()) {

			arr[top] = 1;
			printCodes(huffNode->getRight(), arr, top + 1);
		}

		// If this is a leaf node, then 
		// it contains one of the input 
		// characters, print the character 
		// and its code from arr[] 
		if (huffNode->getRight() == nullptr && huffNode->getLeft() == nullptr) {

			cout << huffNode->getData().key << ": ";

			_sum += top * huffNode->getData().freq;
			for (int i = 0; i < top; ++i)
			{
				cout << arr[i];

			}
			cout << "\n";

		}

	}

	void HuffmanCode::GenerateHuffmanCode()
	{
		_charsCounter.PrintTree();
		convertBSTtoMinHeap(_charsCounter.getRoot());
		buildHuffman();
		int size = _queue.getHeapSize();
		int* arr = new int[size];
		printCodes(_huffTree, arr, 0);
		cout << "Encoded file weight: " << _sum;
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
		_queue.insert(treeNode);
	}
}
