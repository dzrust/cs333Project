#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include "indexConstants.h"
#include "book.h"
#include "index.h"
#include "words.h"
#include "page.h"


class Book {
private:
	std::string title;
	std::vector<Page> pages;
	Index index;
	Words stopList;

public:
	Book();
	~Book();

	void createIndex();

	void createBook(std::istream& input);

	void generateStopList();

	void setTitle(std::istream& input);
};

std::string reduceWords(std::string word);

std::string toLower(std::string word);

#endif
