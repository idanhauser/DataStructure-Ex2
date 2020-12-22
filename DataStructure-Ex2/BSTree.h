#pragma once
#include "BSTreeNode.h"
#include<iostream>
using namespace std;
class BSTree
{
private:
	BSTreeNode* _root;
public:
	
	BSTree();
	~BSTree();
	void makeEmpty();
	BSTreeNode* Find(char key);
	Pair FindMin(char key);
	Pair FindMax(char key);
	void Insert(Pair item);
	void Delete(char key);
	void PrintTree();
};
