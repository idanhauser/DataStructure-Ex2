// DataStructure-Ex2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include "BSTree.h"
#include "MinHeap.h"
using namespace std;
using namespace HuffmanCoding;

void GenerateHoffmanCode(const string& cs);


int ReadFromFile(const string& cs, BSTree& searchTree);


void convertBSTtoMinHeap(TreeNode* treeNode, MinHeap& queue);



void GenerateHoffmanCode(const string& cs)
{
	int maxSizeOfqueue;
	BSTree charsCounter;
	charsCounter.makeEmpty();
	maxSizeOfqueue = ReadFromFile(cs, charsCounter);
	MinHeap queue(maxSizeOfqueue);
	convertBSTtoMinHeap(charsCounter.getRoot(), queue);
	charsCounter.PrintTree();
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
		infile >> val;
		Pair data;
		data.freq = 0;
		data.key = val;
		searchTree.Insert(data);
		counter++;
	}
	infile.close();
	cout << endl;
	return counter;
}

void convertBSTtoMinHeap(TreeNode* treeNode, MinHeap& queue)
{
	if (treeNode == nullptr)
	{
		return;
	}



	convertBSTtoMinHeap(treeNode->getLeft(), queue);
	queue.insert(treeNode);
	convertBSTtoMinHeap(treeNode->getRight(), queue);
}

int main()
{
	string nameOfFile;
	cin >> nameOfFile;

	GenerateHoffmanCode(nameOfFile);
}
