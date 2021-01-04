#pragma once
#include "Pair.h"
#define new MYDEBUG_NEW
#ifdef _DEBUG
#define MYDEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#else
#define MYDEBUG_NEW new
#endif
#include "TreeNode.h"
using namespace std;

namespace HuffmanCoding
{
	class MinHeap
	{
	public:
		MinHeap()=default;
		MinHeap( int phySize);
		MinHeap(TreeNode*& arr,const int size);
		MinHeap(const MinHeap& other)=default;
		~MinHeap();
		void BuildHeap() const;
		bool isEmpty() const;
		void makeEmpty();
		TreeNode* Min() const ;
		TreeNode& DeleteMin();
		void insert(TreeNode& item);
		void printHeap() const;
		int getHeapSize() const;
		int getPhyHeapSize() const;
		MinHeap& operator=(const MinHeap& other);
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