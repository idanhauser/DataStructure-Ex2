#include "MinHeap.h"

#include <stdlib.h>
#define new MYDEBUG_NEW
#ifdef _DEBUG
#define MYDEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#else
#define MYDEBUG_NEW new
#endif

namespace HuffmanCoding
{


	MinHeap::MinHeap(int phySize) :_data(new TreeNode* [phySize]), _phySize(phySize), _heapSize(0), _allocated(true)
	{

	}

	MinHeap::MinHeap(TreeNode*& arr, const int size) : _phySize(size), _heapSize(size), _allocated(false)
	{
		_data = &arr;

	}

	MinHeap::~MinHeap()
	{
		if (_allocated)
		{
			delete[] _data;
		}
		_data = nullptr;
	}

	void MinHeap::BuildHeap() const
	{
		for (int i = _phySize / 2 - 1; i >= 0; i--)
		{
			FixHeap(i);
		}
	}

	bool MinHeap::isEmpty() const
	{
		return (_heapSize == 0);
	}

	void MinHeap::makeEmpty()
	{
		_heapSize = 0;
	}

	TreeNode* MinHeap::Min() const
	{
		return *_data;
	}

	int MinHeap::Left(const int node)
	{
		return (2 * node + 1);
	}

	int MinHeap::Right(const int node)
	{
		return (2 * node + 2);
	}

	int MinHeap::Parent(const int node)
	{
		return (node - 1) / 2;
	}

	void MinHeap::FixHeap(const int node) const
	{
		int min;
		int left = Left(node);
		int right = Right(node);
		/* find the smallest of parent, left, and right */

		if (left < _heapSize && _data[left]->_data.getFreq() < _data[node]->_data.getFreq())
		{
			min = left;
		}
		else
		{
			min = node;
		}
		if (right < _heapSize && _data[right]->_data.getFreq() < _data[min]->_data.getFreq())
		{
			min = right;
		}


		if (min != node) {
			TreeNode* temp = _data[node];
			_data[node] = _data[min];
			_data[min] = temp;
			FixHeap(min);
		}
	}


	/// <summary>
	///Remove the element at head of the queue 
	/// </summary>
	/// <returns>retuns the element with the minimum frequency.(the root in the MinHeap) </returns>
	TreeNode& MinHeap::DeleteMin()
	{
		TreeNode* MinTreeNode;
		if (_heapSize == 0) {
			cout << "ERROR: heap underflow! maybe file is empty?" << endl;
			exit(1);
		}
		MinTreeNode = _data[0];
		_heapSize--;
		_data[0] = _data[_heapSize];
		FixHeap(0);
		return *MinTreeNode;
	}

	void MinHeap::insert(TreeNode& item)
	{
		if (_phySize == _heapSize)
		{
			cout << "ERROR: heap Overflow!" << endl;
			exit(1);
		}
		int i = _heapSize;
		_heapSize++;

		while ((i > 0) && (_data[Parent(i)]->_data.getFreq() > item._data.getFreq())) {
			_data[i] = _data[Parent(i)];
			i = Parent(i);
		}
		_data[i] = &item;
	}


	int MinHeap::getHeapSize() const
	{
		return _heapSize;
	}

	int MinHeap::getPhyHeapSize() const
	{
		return _phySize;
	}

	bool MinHeap::getIsAllocated() const
	{
		return _allocated;
	}

	MinHeap& MinHeap::operator=(const MinHeap& other)
	{
		if (this != &other)
		{
			_allocated = other._allocated;
			_heapSize = other._heapSize;
			_phySize = other._phySize;
			_data = new TreeNode * [_phySize];
		}
		return *this;
	}

	ostream& operator<<(ostream& os, const MinHeap& queue)
	{
		for (int i = 0; i < queue._heapSize; ++i)
		{
			os << queue._data[i]->getData();
		}
		return os;
	}
}
