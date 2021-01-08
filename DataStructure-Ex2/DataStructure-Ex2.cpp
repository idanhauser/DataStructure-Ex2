
//Idan Hasuer 205542549
//Roee Habari - tamir 205666985
#include <stdlib.h>
#include <ostream>
#include <string>
#include "HuffmanCode.h"
using namespace std;
using namespace HuffmanCoding;


///******************************
///		INSTRUCTIONS:
///******************************
//1) Enter a text file name with an extension(for example:"input.txt").
//2)Init the object HuffmanCode and enter the name we recieved from user.
//3)Use the object of HuffmanCode and use the function "GenerateHuffmanCode".
//4)After the process is finised we can't print the object and read the eccoded table.

int main()
{

		string nameOfFile;
		cout << "Enter name of file:" << endl;
		cin >> nameOfFile;
		HuffmanCode HuffmanGenerator(nameOfFile);
		HuffmanGenerator.GenerateHuffmanCode();
		cout << HuffmanGenerator << endl;
	
}
