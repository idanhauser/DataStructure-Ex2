#pragma once
#include "Pair.h"
#include <vector>

#include "TreeNode.h"
using namespace std;
class MinHeap
{
private:
	TreeNode* data;
	int maxSize;
	int heapSize;
	bool allocated;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);

public:
	MinHeap(int max);
	MinHeap(TreeNode*& vec, int n);
	~MinHeap();
	TreeNode* Min();
	TreeNode* DeleteMin();
	void insert(TreeNode* item);
};
