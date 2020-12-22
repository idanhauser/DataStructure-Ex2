#include "TreeNode.h"

#include <iostream>
using namespace std;

TreeNode::TreeNode() :_right(nullptr), _left(nullptr)
{
}

TreeNode::TreeNode(Pair item, TreeNode* left, TreeNode* right) : _data(item), _left(left), _right(right)
{
}

TreeNode::~TreeNode()
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



void TreeNode::Inorder()
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
