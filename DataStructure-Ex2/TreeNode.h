#pragma once


#include "Pair.h"
using namespace std;

namespace HuffmanCoding
{
	class TreeNode
	{	
	public:
		TreeNode();
		TreeNode(const Pair& item, TreeNode* left, TreeNode* right);
		~TreeNode();
		Pair getData() const;
		TreeNode* getLeft() const;
		TreeNode* getRight() const ;
		void Inorder() const ;
		void setLeft(TreeNode* left);
		void setRight(TreeNode* right);
		const TreeNode& operator=(const TreeNode& other) = delete;
		TreeNode(const TreeNode& other) = delete;
		friend class BSTree;
		friend class MinHeap;
	private:
		Pair _data;
		TreeNode* _left, * _right;
	};
}