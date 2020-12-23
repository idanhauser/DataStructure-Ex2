#pragma once

#include<iostream>

#include "Pair.h"
using namespace std;

namespace HuffmanCoding
{
	class TreeNode
	{
	private:
		Pair _data;
		TreeNode* _left, * _right;
	public:
		TreeNode();
		TreeNode(Pair item, TreeNode* left, TreeNode* right);
		~TreeNode();
		Pair getData() const;
		TreeNode* getLeft() const;
		TreeNode* getRight() const;
		void Inorder() const ;
		friend class BSTree;
		friend class MinHeap;
	};
}