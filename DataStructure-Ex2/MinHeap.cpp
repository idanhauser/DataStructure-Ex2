#include "MinHeap.h"

namespace HuffmanCoding
{



	MinHeap::MinHeap(int max) :_maxSize(max), _heapSize(0), _allocated(true),_data(new TreeNode*[max])
	{

	}

	MinHeap::MinHeap(TreeNode*& arr, int n) : _maxSize(n), _heapSize(n), _allocated(false)
	{
		_data = &arr;
		for (int i = n / 2 - 1; i >= 0; i--)
		{
			FixHeap(i);
		}
	}

	MinHeap::~MinHeap()
	{
		if (_allocated)
		{
			delete[] _data;
		}
		_data = nullptr;
	}

	bool MinHeap::isEmpty()
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

	int MinHeap::Left(int node)
	{
		return (2 * node + 1);
	}

	int MinHeap::Right(int node)
	{
		return (2 * node + 2);
	}

	int MinHeap::Parent(int node)
	{
		return (node - 1) / 2;
	}

	void MinHeap::FixHeap(int node)
	{
		int min;
		int left = Left(node);
		int right = Right(node);
		/* find the smallest of parent, left, and right */

		if (left < _heapSize && _data[left]->_data.freq < _data[node]->_data.freq)
		{
			min = left;
		}
		else
		{
			min = node;
		}
		if (right < _heapSize && _data[right]->_data.freq < _data[min]->_data.freq)
		{
			min = right;
		}
		/* swap the parent with the smallest, if needed. */

		if (min != node) {
			TreeNode* temp = _data[node];
			_data[node] = _data[min];
			_data[min] = temp;
			FixHeap(min);
		}
	}

	/* remove the element at head of the queue (i.e., with minimum frequency) */
	TreeNode* MinHeap::DeleteMin()
	{
		TreeNode* MinTreeNode;
		if (_heapSize == 0) {
			cout << ("ERROR: heap underflow!") << endl;
			exit(1);
		}
		/* get return value out of the root */
		MinTreeNode = _data[0];
		_heapSize--;
		_data[0] = _data[_heapSize];
		/* left and right are a heap, make the root a heap */
		FixHeap(0);
		return MinTreeNode;
	}

	void MinHeap::insert(TreeNode* item)
	{
		if (_maxSize == _heapSize)
		{
			cout << ("ERROR: heap Overflow!") << endl;
			exit(1);
		}
		int i = _heapSize;
		_heapSize++;

		while ((i > 0) && (_data[Parent(i)]->_data.freq > item->_data.freq)) {
			_data[i] = _data[Parent(i)];
			i = Parent(i);
		}
		_data[i] = item;
	}

	void MinHeap::printHeap() const
	{
		cout << "print arr" << endl;
		for (int i = 0; i < _heapSize; ++i)
		{
			cout << (_data[i])->getData().key << ":" << (_data[i])->getData().freq << endl;
		}
	}

	int MinHeap::getHeapSize() const
	{
		return _heapSize;
	}

	void MinHeap::operator=(const MinHeap& other)
	{
		if(this!=&other)
		{
			_allocated = other._allocated;
			_heapSize = other._heapSize;
			_maxSize = other._maxSize;
			_data = new TreeNode * [_maxSize];
			
		}
	}
}
