#pragma once
#include "TreeNode.h"
#include<iostream>
using namespace std;
class BSTree
{
private:
	TreeNode* _root;
public:
	
	BSTree();
	~BSTree();
	void makeEmpty();
	TreeNode* Find(char key);
	Pair FindMin(char key);
	Pair FindMax(char key);
	void Insert(Pair item);
	void Delete(char key);
	void PrintTree();
};
