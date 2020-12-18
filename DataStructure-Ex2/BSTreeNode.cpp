#include "BSTreeNode.h"

#include <iostream>
using namespace std;

BSTreeNode::BSTreeNode() :right(nullptr), left(nullptr)
{
}

BSTreeNode::BSTreeNode(Pair item, BSTreeNode* left, BSTreeNode* right) : value(item), left(left), right(right)
{
}

BSTreeNode::~BSTreeNode()
{
	if (left != nullptr)
	{
		delete left;
	}
	if (right != nullptr)
	{
		delete right;
	}


}

Pair& BSTreeNode::getValue()
{
	return value;
}

void BSTreeNode::Inorder()
{
	if (left != nullptr)
	{
		left->Inorder();
	}
	cout << value.data << " : " << value.freq << endl;
	if (right != nullptr)
	{
		right->Inorder();
	}
}
