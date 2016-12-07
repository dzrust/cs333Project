#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include "indexConstants.h"
#include "book.h"
#include "index.h"

using namespace std;

Book::Book() {

};

Book::~Book() {
};

// Strips all punctuation (except hyphens) from a word and
// changes any upper-case characters to lower-case. Note that
// if a word has nothing except punctuation, this may reduce
// it to the empty string.
string reduceWords(string word)
{
	string result;
	int length = word.size();
	for (int i = 0; i < length; ++i)
	{
		char c = word[i];
		if (c == '-')
			result += c;
		else if (c >= 'a' && c <= 'z')
			result += c;
		else if (c >= 'A' && c <= 'Z')
			result += (c - 'A' + 'a'); // converts to lower-case
	}
	return result;
}

void Book::createIndex() {
	index.createHtmlFile(title);
}

void Book::createBook(istream& input) {
	string word;
	int count = 0;
	Page p;
	p.isFirstPage = true;
	p.isLastPage = false;
	p.pageContent = "";
	p.pageNumber = 1;
	p.title = title;
	while (!input.eof()) {
		string lineContent;
		std::getline(input, lineContent);
		if (count == MAX_LINES_PER_PAGE) {
			pages.push_back(p);
			p.creatHtmlPage();
			p.isFirstPage = false;
			p.isLastPage = false;
			p.pageContent = word + " ";
			p.pageNumber++;
			count = 0;
		}
		else {
			count++;
			p.pageContent += lineContent;
			p.pageContent += "\n";
		}
		int i = 0;
		std::istringstream buf(lineContent);
		std::istream_iterator<std::string> beg(buf), end;

		std::vector<std::string> tokens(beg, end);
		for (auto& s : tokens) {
			string word = s;
			word = reduceWords(word);
			if (word != "") {
				index.containedWords.addWordOrLocation(word, p.pageNumber);
			}
		}
	}
	p.isLastPage = true;
	p.creatHtmlPage();
}

void Book::generateStopList() {
	std::ifstream in("stoplist.txt");
	string word;
	while (in >> word) {
		stopList.addWordOrLocation(word, 0);
	}
	in.close();
}

void Book::setTitle(istream& input) {
	string word;
	bool titleFound = false;
	while (!input.eof() && !titleFound) {
		string lineContent;
		std::getline(input, lineContent);
		if (word == "Title:") {
			input >> title;
			titleFound = true;
		}
	}
}
