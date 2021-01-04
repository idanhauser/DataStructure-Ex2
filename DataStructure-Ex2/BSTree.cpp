#include "BSTree.h"
#include<iostream>
#include <stdlib.h>
#include "Pair.h"
#define new MYDEBUG_NEW
#ifdef _DEBUG
#define MYDEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#else
#define MYDEBUG_NEW new
#endif
using namespace std;

namespace  HuffmanCoding
{
	BSTree::BSTree() :_size(0),_root(nullptr)
	{
	}

	BSTree::~BSTree()
	{
		makeEmpty();
	}

	void BSTree::makeEmpty()
	{
		_root = nullptr;
	}

	TreeNode* BSTree::Find(const char key) const
	{
		bool isFound = false;
		TreeNode* founded = nullptr;
		TreeNode* temp = _root;
		while ((temp != nullptr) && (!founded))
		{
			const char keyNode = temp->_data.getKey();
			if (key == keyNode)
			{
				founded = temp;
			}

			if (key < keyNode)
			{
				temp = temp->_left;
			}
			else
			{
				temp = temp->_right;
			}
		}

		return founded;
	}
	/* loop down to find the leftmost leaf */
	Pair BSTree::FindMin() const
	{
		TreeNode* current = _root;


		while (current->_left != nullptr)
		{
			current = current->_left;
		}

		return current->_data;
	}
	/* loop down to find the rightmost leaf */
	Pair BSTree::FindMax() const
	{
		TreeNode* current = _root;


		while (current->_right != nullptr)
			current = current->_right;

		return current->_data;
	}



	void BSTree::Insert(Pair& item)
	{
		TreeNode* temp = Find(item.getKey());
		if (temp != nullptr)
		{
			temp->_data++;
		}
		else
		{
			temp = _root;
			TreeNode* parent = nullptr;
			item++;
			while (temp != nullptr)
			{
				parent = temp;

				if (item.getKey() < (temp->_data).getKey())
				{
					temp = temp->_left;
				}
				else
				{
					temp = temp->_right;
				}
			}
			TreeNode* newNode = new TreeNode(item, nullptr, nullptr);
			_size++;
			if (parent == nullptr)
			{
				_root = newNode;
			}
			else if (item.getKey() < (parent->_data).getKey())
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
		while (curr != nullptr && curr->_data.getKey() != key) {
			prev = curr;
			if (key < curr->_data.getKey())
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
			TreeNode* newCurr;
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

			TreeNode* temp = curr->_right;
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
			curr->_data.setKey(temp->_data.getKey());
			delete temp;
		}
	}

	void BSTree::PrintTree() const
	{
		if (_root != nullptr)
		{
			_root->Inorder();
		}
	}

	TreeNode* BSTree::getRoot() const
	{
		return _root;
	}

	int BSTree::getSize() const
	{
		return _size;
	}


}
