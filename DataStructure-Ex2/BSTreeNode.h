#pragma once

#include<iostream>
using namespace std;
typedef struct Pair
{
	char key;
	int freq;
}Pair;

class BSTreeNode
{
private:
	Pair _data;
	BSTreeNode* _left, * _right;
public:
	BSTreeNode();
	BSTreeNode(Pair item, BSTreeNode* left, BSTreeNode* right);
	~BSTreeNode();

	void Inorder();
	friend class BSTree;
};
