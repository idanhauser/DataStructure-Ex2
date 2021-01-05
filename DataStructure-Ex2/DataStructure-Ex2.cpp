// DataStructure-Ex2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include "BSTree.h"
#include "HuffmanCode.h"
#include "MinHeap.h"
using namespace std;
using namespace HuffmanCoding;

#include <crtdbg.h>
#define new MYDEBUG_NEW
#ifdef _DEBUG
#define MYDEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#else
#define MYDEBUG_NEW new
#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	{
		string nameOfFile;
		cout << "Enter name of file:" << endl;
		cin >> nameOfFile;
		HuffmanCode HuffmanGenerator(nameOfFile);
		HuffmanGenerator.GenerateHuffmanCode();
		cout << HuffmanGenerator << endl;

	}
}
