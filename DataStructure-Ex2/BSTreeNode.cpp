#include "BSTreeNode.h"

#include <iostream>
using namespace std;

BSTreeNode::BSTreeNode() :_right(nullptr), _left(nullptr)
{
}

BSTreeNode::BSTreeNode(Pair item, BSTreeNode* left, BSTreeNode* right) : _data(item), _left(left), _right(right)
{
}

BSTreeNode::~BSTreeNode()
{
	if (_left != nullptr)
	{
		delete _left;
	}
	if (_right != nullptr)
	{
		delete _right;
	}


}



void BSTreeNode::Inorder()
{
	if (_left != nullptr)
	{
		_left->Inorder();
	}
	cout << _data.key << " : " << _data.freq << endl;
	if (_right != nullptr)
	{
		_right->Inorder();
	}
}
