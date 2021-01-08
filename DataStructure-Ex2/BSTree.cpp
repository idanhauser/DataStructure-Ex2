#include "BSTree.h"
#include<iostream>
#include <stdlib.h>
#include "Pair.h"

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

	/// <summary>
	/// function to search a given key in a given BST 
	/// </summary>
	/// <param name="key">the key we search in the key</param>
	/// <returns>the node we searched for</returns>
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


	/// <summary>
	/// 	/* loop down to find the left most leaf in the bst */
	/// </summary>
	/// <returns>the minimum in the tree</returns>
	Pair BSTree::FindMin() const
	{
		TreeNode* current = _root;


		while (current->_left != nullptr)
		{
			current = current->_left;
		}

		return current->_data;
	}


	/// <summary>
	/// 	/* loop down to find the right most leaf in the bst*/
	/// </summary>
	/// <returns>the maximum in the tree</returns>
	Pair BSTree::FindMax() const
	{
		TreeNode* current = _root;


		while (current->_right != nullptr)
			current = current->_right;

		return current->_data;
	}


	/// <summary>
	/// This function inserts the item by it's key to the bst.
	/// If the key is already exist we add one to the frequency of the pair. 
	/// </summary>
	/// <param name="item">the pair we want to insert into the tree</param>
	void BSTree::Insert(Pair& item)
	{
		//we need to check if the key is already exist in the tree
		TreeNode* temp = Find(item.getKey());
		if (temp != nullptr)
		{
			//if the pair is already exist we add 1 to frequency with operator++
			temp->_data++;
		}
		else
		{//the pair doesn't exist in the tree, lets add to the tree, in the right place.
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
	/// <summary>
	/// This function delete a pair by its key from the bst
	/// </summary>
	/// <param name="key">the key we want to remove from the tree.</param>
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

	/// <summary>
	/// prints the bst by inorder travse.
	/// </summary>
	/// <param name="tNode">the root if the bst </param>
	void BSTree::printTree(TreeNode* tNode) const
	{
		if (_root != nullptr)
		{
			printTree(tNode->_left);

			cout << (tNode->_data) << " ";

	
			printTree(tNode->_right);
		}

	}

	TreeNode* BSTree::getRoot() const
	{
		return _root;
	}
	/// <summary>
	/// the number of nodes in three
	/// </summary>
	/// <returns>number of nodes in  the tree.</returns>
	int BSTree::getSize() const
	{
		return _size;
	}


}
