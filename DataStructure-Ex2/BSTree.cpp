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
		while ((temp != nullptr) && (!isFound))
		{
			const char keyNode = temp->_data.getKey();
			if (key == keyNode)
			{
				founded = temp;
				isFound = true;
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
		TreeNode* pCurr = _root;
		TreeNode* prev = nullptr;
		while (pCurr != nullptr && pCurr->_data.getKey() != key) {
			prev = pCurr;
			if (key < pCurr->_data.getKey())
			{
				pCurr = pCurr->_left;
			}
			else {
				pCurr = pCurr->_right;
			}
		}
		if (pCurr == nullptr) {
			cout << "ERROR: Key " << key
				<< " not found in the"
				<< " provided BST.\n";
			exit(1);
		}
		if (pCurr->_left == nullptr || pCurr->_right == nullptr) {
			TreeNode* newCurr;
			if (pCurr->_left == nullptr)
			{
				newCurr = pCurr->_right;
			}
			else
			{
				newCurr = pCurr->_left;
			}

			if (prev == nullptr)
			{
				return;
			}

			if (pCurr == prev->_left)
			{
				prev->_left = newCurr;
			}
			else {
				prev->_right = newCurr;
			}
			delete pCurr;
		}
		else {
			TreeNode* p = nullptr;

			TreeNode* temp = pCurr->_right;
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
				pCurr->_right = temp->_right;
			}
			pCurr->_data.setKey(temp->_data.getKey());
			delete temp;
		}
	}


	void BSTree::PrintTree(TreeNode* tNode) const
	{
		if (_root != nullptr)
		{
			PrintTree(tNode->_left);

			cout << (tNode->_data) << " ";

	
			PrintTree(tNode->_right);
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
