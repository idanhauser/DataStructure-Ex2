#include "HuffmanCode.h"

namespace HuffmanCoding
{
	void HuffmanCode::checkInput()
	{
		if (!_isValid)
		{
			cout << _Output;
			exit(1);
		}
	}

	HuffmanCode::HuffmanCode(const string& namefile) :_maxSizeOfqueue(0), _charsCounter()/*bst*/, _infile(namefile), _isValid(true)
	{
		ReadFromFile();//updating the member __maxSizeOfqueue
		checkInput();
		_queue = MinHeap(_maxSizeOfqueue);//init queue
	}

	void HuffmanCode::ReadFromFile()
	{
		int counter = 0;
		char val;
		if (!_infile) {
			_Output = "Error with infile. \n";
			_isValid = false;
			return;
		}

		_infile >> val;
		while (!_infile.eof()) {
			if (!_infile.good()) {
				_Output = "Error reading. \n";
				_isValid = false;
				return;
			}
			cout << val << endl;//TODO: for testing purpose need to delete
			_infile >> val;
			Pair data;
			data.freq = 0;
			data.key = val;
			_charsCounter.Insert(data);
			counter++;
		}
		_infile.close();
		cout << endl;
		_maxSizeOfqueue = counter;
	}

	void HuffmanCode::GenerateHuffmanCode()
	{

	}


}