#include "TreeNode.h"

#include <iostream>
using namespace std;
namespace HuffmanCoding

{
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

	Pair TreeNode::getData() const
	{
		return _data;
	}

	TreeNode* TreeNode::getLeft() const
	{
		return _left;
	}

	TreeNode* TreeNode::getRight() const 
	{
		return _right;
	}

	void TreeNode::Inorder() const
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

	void TreeNode::setLeft(TreeNode* left)
	{
		_left = left;
	}

	void TreeNode::setright(TreeNode* right)
	{
		_right = right;
	}
}
