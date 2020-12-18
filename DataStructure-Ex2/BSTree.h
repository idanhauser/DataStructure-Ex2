#pragma once
#include "BSTreeNode.h"
#include<iostream>
using namespace std;
class BSTree
{
private:
	BSTreeNode* root;
public:
	BSTree();
	~BSTree();
	BSTreeNode* Find(char key);
	void Insert(Pair item);
	void Delete(char key);
	void PrintTree();
};
