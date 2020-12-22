﻿#include "BSTree.h"
#include<iostream>
using namespace std;

BSTree::BSTree() :_root(nullptr)
{
}

BSTree::~BSTree()
{
	makeEmpty();
}

void BSTree::makeEmpty()
{
	if (_root != nullptr)
	{
		delete _root;
	}
	_root = nullptr;
}

TreeNode* BSTree::Find(char key)
{
	TreeNode* temp = _root;
	while (temp != nullptr)
	{
		if (key == (temp->_data).key)
		{
			return temp;
		}
		else if (key < (temp->_data).key)
		{
			temp = temp->_left;
		}
		else
		{
			temp = temp->_right;
		}
	}

	return nullptr;
}

Pair BSTree::FindMin(char key)
{
	TreeNode* current = _root;

	/* loop down to find the leftmost leaf */
	while (current->_left != nullptr)
	{
		current = current->_left;
	}

	return current->_data;
}

Pair BSTree::FindMax(char key)
{
	TreeNode* current = _root;
	/* loop down to find the rightmost leaf */

	while (current->_right != nullptr)
		current = current->_right;

	return current->_data;
}



void BSTree::Insert(Pair item)
{

	if (Find(item.key) != nullptr)
	{
		cout << "Key and value already in the tree" << endl;
		exit(1);
	}
	else
	{
		TreeNode* temp = _root;
		TreeNode* parent = nullptr;
		TreeNode* newNode = nullptr;

		while (temp != nullptr)
		{
			parent = temp;
			if (item.key < (temp->_data).key)
			{
				temp = temp->_left;
			}
			else
			{
				temp = temp->_right;
			}
		}
		newNode = new TreeNode(item, nullptr, nullptr);
		if (parent == nullptr)
		{
			_root = newNode;
		}
		else if (item.key < (parent->_data).key)
		{
			parent->_left = newNode;
		}
		else
		{
			parent->_right = newNode;
		}
	}
}

void BSTree::Delete(char key)
{
	TreeNode* curr = _root;
	TreeNode* prev = nullptr;
	while (curr != nullptr && curr->_data.key != key) {
		prev = curr;
		if (key < curr->_data.key)
		{
			curr = curr->_left;
		}
		else {
			curr = curr->_right;
		}
	}
	if (curr == nullptr) {
		cout << "ERROR: Key " << key
			<< " not found in the"
			<< " provided BST.\n";
		exit(1);
	}
	if (curr->_left == nullptr || curr->_right == nullptr) {
		TreeNode* newCurr = nullptr;
		if (curr->_left == nullptr)
		{
			newCurr = curr->_right;
		}
		else
		{
			newCurr = curr->_left;
		}

		if (prev == nullptr)
		{
			return;
		}

		if (curr == prev->_left)
		{
			prev->_left = newCurr;
		}
		else {
			prev->_right = newCurr;
		}
		delete curr;
	}
	else {
		TreeNode* p = nullptr;
		TreeNode* temp = nullptr;

		temp = curr->_right;
		while (temp->_left != nullptr) {
			p = temp;
			temp = temp->_left;
		}
		if (p != nullptr)
		{
			p->_left = temp->_right;
		}
		else
		{
			curr->_right = temp->_right;
		}
		curr->_data.key = temp->_data.key;
		delete temp;
	}
}

void BSTree::PrintTree()
{
	if (_root != nullptr)
	{
		_root->Inorder();
	}
}
