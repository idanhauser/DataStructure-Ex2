// DataStructure-Ex2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include "BSTree.h"
#include "HuffmanCode.h"
#include "MinHeap.h"
using namespace std;
using namespace HuffmanCoding;


void GenerateHoffmanCode(const string& cs);


int ReadFromFile(const string& cs, BSTree& searchTree);


void convertBSTtoMinHeap(TreeNode* treeNode, MinHeap& queue);


TreeNode* build_huffman( MinHeap& queue);

void GenerateHoffmanCode(const string& cs)
{
	char* codes[256]; /* array of codes, 1 per char */
	char code[256];   /* a place to hold one code */
	int maxSizeOfqueue;
	BSTree charsCounter;

	maxSizeOfqueue = ReadFromFile(cs, charsCounter);
	charsCounter.PrintTree();
	MinHeap queue(maxSizeOfqueue);
	convertBSTtoMinHeap(charsCounter.getRoot(), queue);
	TreeNode* t;

	cout << endl;
	cout << endl;

	queue.printHeap();

	t=build_huffman(queue);


	//traverse(t, 0, code, codes);
}

int ReadFromFile(const string& cs, BSTree& searchTree)
{
	int counter = 0;
	char val;
	ifstream infile(cs);
	if (!infile) {
		cout << "Error with infile" << endl;
		exit(-1);
	}

	infile >> val;
	while (!infile.eof()) {
		if (!infile.good()) {
			cout << "Error reading" << endl;
			exit(-1);
		}
		cout << val << endl;//for testing purpose need to delete
		Pair data;
		data.freq = 0;
		data.key = val;
		searchTree.Insert(data);
		counter++;
		infile >> val;
	}
	infile.close();
	cout << endl;
	return counter;
}



/* make the huffman tree from frequencies in freq[] (Huffman's Algorithm) */

TreeNode* build_huffman(MinHeap& queue) {
	int		i, n;
	TreeNode* x, * y, * z;
	Pair item;
	item.key = '%';

	/* at this point, the heap is a "forest" of singleton trees */

	n = queue.getHeapSize() - 1; /* heap_size isn't loop invariant! */

	/* if we insert two things and remove one each time,
	 * at the end of heap_size-1 iterations, there will be
	 * one tree left in the heap
	 */
	for (i = 0; i < n; i++) {

		/* make a new node z from the two least frequent
		 * nodes x and y
		 */
	
		x = queue.DeleteMin();
		y = queue.DeleteMin();
		item.freq= x->getData().freq + y->getData().freq;
		z = new TreeNode(item, x, y);
		/* z's frequency is the sum of x and y */


		/* put this back in the queue */

		queue.insert(z);
	}

	/* return the only thing left in the queue, the whole Huffman tree */

	return queue.DeleteMin();
}







void convertBSTtoMinHeap(TreeNode* treeNode, MinHeap& queue)
{
	if (treeNode == nullptr)
	{
		return;
	}



	convertBSTtoMinHeap(treeNode->getLeft(), queue);
	convertBSTtoMinHeap(treeNode->getRight(), queue);
	treeNode->setLeft(nullptr);
	treeNode->setright(nullptr);
	queue.insert(treeNode);

}




int main()
{
	string nameOfFile;
	cin >> nameOfFile;
	HuffmanCode a(nameOfFile);
	a.GenerateHuffmanCode();

}
