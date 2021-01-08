#pragma once
#include "Pair.h"

#include "TreeNode.h"
using namespace std;

namespace HuffmanCoding
{
	class MinHeap
	{
	public:
		MinHeap()=default;
		MinHeap(int phySize);
		MinHeap(TreeNode*& arr,const int size);
		~MinHeap();
		void BuildHeap() const;
		bool isEmpty() const;
		void makeEmpty();
		TreeNode* Min() const ;
		TreeNode& DeleteMin();
		void insert(TreeNode& item);
		int getHeapSize() const;
		int getPhyHeapSize() const;
		bool getIsAllocated()const;
		MinHeap& operator=(const MinHeap& other);
		MinHeap(const MinHeap& other) = default;
		friend ostream& operator<<(ostream& os, const MinHeap& queue);

		
		private:
		TreeNode** _data;
		int _phySize;
		int _heapSize;
		bool _allocated;
		static int Left(int node);
		static int Right(int node);
		static int Parent(int node);
		void FixHeap(int node) const;
	};
}