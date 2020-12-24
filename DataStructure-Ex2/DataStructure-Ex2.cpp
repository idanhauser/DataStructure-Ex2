// DataStructure-Ex2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include "BSTree.h"
#include "HuffmanCode.h"
#include "MinHeap.h"
using namespace std;
using namespace HuffmanCoding;



int main()
{
	string nameOfFile;
	cin >> nameOfFile;
	HuffmanCode a(nameOfFile);
	a.GenerateHuffmanCode();
	std::cout << "bye" << std::endl;
}
