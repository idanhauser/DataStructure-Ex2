#pragma once
#include "TreeNode.h"
#include<iostream>
using namespace std;
#define new MYDEBUG_NEW
#ifdef _DEBUG
#define MYDEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#else
#define MYDEBUG_NEW new
#endif
namespace HuffmanCoding
{
	class BSTree
	{
	public:
		BSTree(const BSTree& other) = delete;
		BSTree();
		~BSTree();
		void makeEmpty();
		TreeNode* Find( char key)const;
		Pair FindMin() const ;
		Pair FindMax() const;
		void Insert(Pair& item);
		void Delete(char key);
		 void PrintTree(TreeNode* tNode) const ;
		 TreeNode* getRoot() const;
		 int getSize() const;
		 const BSTree& operator=(const BSTree& other) = delete;
	private:
		int _size;
		TreeNode* _root;

	};
}