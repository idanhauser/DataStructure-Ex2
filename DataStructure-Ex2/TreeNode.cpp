﻿#include "TreeNode.h"
#include "Utils.h"

using namespace std;
namespace HuffmanCoding
{
	TreeNode::TreeNode() :_data(NON_PRINTABLE_CHARACTER,-1),_left(nullptr), _right(nullptr)
	{
	}

	TreeNode::TreeNode(const Pair& item, TreeNode* left, TreeNode* right) : _data(item), _left(left), _right(right)
	{
	}
	TreeNode::~TreeNode()
	{


			delete _left;

		delete _right;

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
		if (_right != nullptr)
		{
			_right->Inorder();
		}
	}

	void TreeNode::setLeft(TreeNode* left)
	{
		_left = left;
	}

	void TreeNode::setRight(TreeNode* right)
	{
		_right = right;
	}
}
