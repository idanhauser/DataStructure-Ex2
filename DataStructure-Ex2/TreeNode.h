#pragma once

#include<iostream>

#include "Pair.h"
using namespace std;

class TreeNode
{
private:
	Pair _data;
	TreeNode* _left, * _right;
public:
	TreeNode();
	TreeNode(Pair item, TreeNode* left, TreeNode* right);
	~TreeNode();

	void Inorder();
	friend class BSTree;
	friend class MinHeap;
};
