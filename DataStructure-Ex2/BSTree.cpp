#include "BSTree.h"
#include<iostream>
using namespace std;

BSTree::BSTree() :root(nullptr)
{
}

BSTree::~BSTree()
{
}

BSTreeNode* BSTree::Find(char key)
{
	BSTreeNode* temp = root;
	while (temp != nullptr)
	{
		if (key == (temp->value).data)
		{
			return temp;
		}
		else if (key < (temp->value).data)
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}

	return nullptr;
}

void BSTree::Insert(Pair item)
{

	if (Find(item.data) != nullptr)
	{
		cout << "Key and value already in the tree" << endl;
		exit(1);
	}
	else
	{
		BSTreeNode* temp = root;
		BSTreeNode* parent = nullptr;
		BSTreeNode* newNode = nullptr;

		while (temp != nullptr)
		{
			parent = temp;
			if (item.data < (temp->value).data)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
		newNode = new BSTreeNode(item, nullptr, nullptr);
		if (parent == nullptr)
		{
			root = newNode;
		}
		else if (item.data < (parent->value).data)
		{
			parent->left = newNode;
		}
		else
		{
			parent->right = newNode;
		}
	}
}

void BSTree::Delete(char key)
{

	if (root != nullptr)
	{
		BSTreeNode* temp = nullptr;

	}
}

void BSTree::PrintTree()
{
	if (root != nullptr)
	{
		root->Inorder();
	}
}
