#include "MinHeap.h"


MinHeap::MinHeap(int max) :maxSize(max), heapSize(0), allocated(true)
{
	data = new TreeNode[max];
}

MinHeap::MinHeap(TreeNode*& arr, int n) : maxSize(n), heapSize(n),allocated(false)
{
	data = arr;
	for (int i = n/2-1; i >= 0; i--)
	{
		FixHeap(i);
	}
}

MinHeap::~MinHeap()
{
	if (allocated)
	{
		delete[] data;
	}
	data = nullptr;
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

	if (left < heapSize && data[left]._data.freq < data[node]._data.freq)
	{
		min = left;
	}
	else
	{
		min = node;
	}
	if (right < heapSize && data[right]._data.freq < data[min]._data.freq)
	{
		min = right;
	}
	/* swap the parent with the smallest, if needed. */

	if (min != node) {
		TreeNode* temp = &data[node];
		data[node] = data[min];
		data[min] = *temp;
		FixHeap(min);
	}
}

/* remove the element at head of the queue (i.e., with minimum frequency) */
TreeNode* MinHeap::DeleteMin()
{
	TreeNode* MinTreeNode;
	if (heapSize == 0) {
		cout << ("ERROR: heap underflow!") << endl;
		exit(1);
	}
	/* get return value out of the root */
	MinTreeNode = &data[0];
	heapSize--;
	data[0] = data[heapSize];
	/* left and right are a heap, make the root a heap */
	FixHeap(0);
	return MinTreeNode;
}

void MinHeap::insert(TreeNode* item)
{
	if (maxSize == heapSize)
	{
		cout << ("ERROR: heap Overflow!") << endl;
		exit(1);
	}
	int i = heapSize;
	heapSize++;

	while ((i > 0) && (data[Parent(i)]._data.freq < item->_data.freq)) {
		data[i] = data[Parent(i)];
		i = Parent(i);
	}
	data[i] = *item;
}



