#pragma once
#include "TreeNode.h"
#include<iostream>
using namespace std;

namespace HuffmanCoding
{
	class BSTree
	{
	public:
		BSTree();
		~BSTree();
		void makeEmpty();
		TreeNode* Find( char key)const;
		Pair FindMin() const ;
		Pair FindMax() const;
		void Insert(Pair& item);
		void Delete(char key);
		 void printTree(TreeNode* tNode) const ;
		 TreeNode* getRoot() const;
		 int getSize() const;
		 const BSTree& operator=(const BSTree& other) = delete;
		 BSTree(const BSTree& other) = delete;
	private:
		int _size;
		TreeNode* _root;

	};
}