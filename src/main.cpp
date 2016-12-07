#include <iostream>

#include <fstream>
#include "book.h"

using namespace std;

int main(int argc, char** argv)
{
	if (argc == 2)
	{
		std::ifstream in(argv[1]);
		Book newBook;
		newBook.generateStopList();
		newBook.createBook(in);
		newBook.createIndex();
	}
	else
	{
		cerr << "Usage: " << argv[0] << " inFileName" << endl;
		return -1;
	}

	return 0;
}
