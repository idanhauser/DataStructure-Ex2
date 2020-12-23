#pragma once
#include "TreeNode.h"
#include<iostream>
using namespace std;

namespace HuffmanCoding
{
	class BSTree
	{
	private:
		TreeNode* _root;
	public:

		BSTree();
		~BSTree();
		void makeEmpty();
		TreeNode* Find(const char key)const;
		Pair FindMin(const char key) const ;
		Pair FindMax(const char key) const;
		void Insert(Pair item);
		void Delete(char key);
		void PrintTree() const;
		 TreeNode* getRoot() const;
	};
}