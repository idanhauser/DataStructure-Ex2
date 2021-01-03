#pragma once

#include<iostream>
#define new MYDEBUG_NEW
#ifdef _DEBUG
#define MYDEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#else
#define MYDEBUG_NEW new
#endif
#include "Pair.h"
using namespace std;

namespace HuffmanCoding
{
	class TreeNode
	{	
	public:
		TreeNode();
		TreeNode(const Pair& item, TreeNode* left, TreeNode* right);
		const TreeNode& operator=(const TreeNode& other) = delete;
		TreeNode(const TreeNode& other) = delete;
		~TreeNode();
		Pair getData() const;
		TreeNode* getLeft() const;
		TreeNode* getRight() const ;
		void Inorder() const ;
		void setLeft(TreeNode* left);
		void setright(TreeNode* right);
		friend class BSTree;
		friend class MinHeap;
	private:
		Pair _data;
		TreeNode* _left, * _right;
	};
}