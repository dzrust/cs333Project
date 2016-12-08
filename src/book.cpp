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
			result += " ";
		else if (c >= 'a' && c <= 'z')
			result += c;
		else if (c >= 'A' && c <= 'Z')
			result += (c - 'A' + 'a'); // converts to lower-case
	}
	return result;
}

string toLower(string word)
{
	string result;
	int length = word.size();
	for (int i = 0; i < length; ++i)
	{
		char c = word[i];
		if (c >= 'A' && c <= 'Z') {
			result += (c - 'A' + 'a'); // converts to lower-case
		}
		else {
			result += c;
		}
	}
	return result;
}

void Book::createIndex() {
	index.createHtmlFile(title, pages.size());
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
	while (!input.eof()) 
	{
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
			std::istringstream buf1(word);
			std::istream_iterator<std::string> beg1(buf1), end1;

			std::vector<std::string> tokens1(beg1, end1);
			for (auto& d : tokens1) {
				if (d.size() > 3 && !index.containedWords.inStopList(d, stopList)) {
					index.containedWords.addWordOrLocation(d, p.pageNumber);
				}
			}
		}
	}
	std::istringstream buf(p.pageContent);
	std::istream_iterator<std::string> beg(buf), end;

	std::vector<std::string> tokens(beg, end);
	bool finalPageContent = false;
	for (auto& s : tokens) {
		string word = s;
		word = reduceWords(word);
		if (word != "") {
			finalPageContent = true;
		}
	}
	if (finalPageContent) {
		p.isLastPage = true;
		p.creatHtmlPage();
	}
	else {
		pages[pages.size()-1].isLastPage = true;
		pages[pages.size() - 1].creatHtmlPage();

	}
}

void Book::generateStopList() {
	std::ifstream in("stoplist.txt");
	string word;
	while (in >> word)
	{
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
		std::istringstream buf(lineContent);
		std::istream_iterator<std::string> beg(buf), end;

		std::vector<std::string> tokens(beg, end);
		for (auto& s : tokens) 
		{
			string word = s;
			word = toLower(word);
			if (titleFound) {
				title += s + " ";
			}
			if (word == "title:") 
			{
				titleFound = true;
			}
		}
	}
}
