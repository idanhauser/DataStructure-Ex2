#pragma once

#include<iostream>
using namespace std;
typedef struct Pair
{
	char data;
	int freq;
}Pair;

class BSTreeNode
{
private:
	Pair value;
	BSTreeNode* left, * right;
public:
	BSTreeNode();
	BSTreeNode(Pair item, BSTreeNode* left, BSTreeNode* right);
	~BSTreeNode();

	void Inorder();
	friend class BSTree;
};
