#pragma once
#include "Pair.h"
#include <vector>

#include "TreeNode.h"
using namespace std;

namespace HuffmanCoding
{
	class MinHeap
	{
	private:
		TreeNode** _data;
		int _maxSize;
		int _heapSize;
		bool _allocated;
		static int Left(int node);
		static int Right(int node);
		static int Parent(int node);
		void FixHeap(int node);

	public:
		MinHeap()=default;
		MinHeap(int max);
		MinHeap(TreeNode*& arr, int n);
		~MinHeap();
		bool	isEmpty();
		void makeEmpty();
		TreeNode* Min() const ;
		TreeNode* DeleteMin();
		void insert(TreeNode* item);
		void printHeap() const;
		int getHeapSize() const;
		int getMaxHeapSize() const;
		void operator=(const MinHeap& other);
	};
}