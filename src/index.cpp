#include <iostream>
#include <fstream>
#include <string>
#include "index.h"
#include "words.h"
#include "indexConstants.h"

using namespace std;

void Index::createHtmlFile(string title) {
	//std::ofstream out("D:\\Documents\\TestProjectOutput\\index.html");
	std::ofstream out("C:\\TestOutput\\index.html");
	out << "<html>" << endl
		<< "<head>" << endl
		<< "<title>" << title << "</title>" << endl
		<< "</head>" << endl
		<< "<body>" << endl
		<< "<p>" << endl
		<< "<a href=\"page0001.html\">First</a>" << endl
		<< "</p>" << endl
		<< "<hr/>" << endl
		<< "<p>" << endl;
	Words::ListNode* nodeHead = containedWords.wordHead;
	char currentIndex = 'A';
	while (nodeHead != 0) {
		std::string word = nodeHead->data.newWord;
		if (word.at(0) != currentIndex) {
			currentIndex = word.at(0);
			out << "<a href=\"#" << currentIndex << "\">" << currentIndex << "</a>" << endl;

		}
		nodeHead = nodeHead->next;
	}

	out << "</p>" << endl << "<hr />" << endl << "<h1>Index</h1>" << endl;

	nodeHead = containedWords.wordHead;
	currentIndex = 'A';
	bool firstLetter = true;
	while (nodeHead != 0) {
		std::string word = nodeHead->data.newWord;
		if (nodeHead->data.wordLocations.size() <= PAGE_THRESHOLD) {
			if (word.at(0) != currentIndex) {
				currentIndex = word.at(0);
				if (!firstLetter) {
					out << "</ul>" << endl;
				}
				else {
					firstLetter = false;
				}
				out << "<h2 id=\"" << currentIndex << "\">" << currentIndex << "</h2>" << endl << "<ul>" << endl;

			}
			out << "<li>" << word << endl;
			int length = nodeHead->data.wordLocations.size();
			for (int i = 0; i < length; i++) {
				int pageNumber = nodeHead->data.wordLocations[i];
				if ((pageNumber) < 10) {
					out << "<a href=\"page000" << (pageNumber) << ".html\">" << pageNumber << "</a>," << endl;
				}
				else {
					if ((pageNumber) < 100) {
						out << "<a href=\"page00" << (pageNumber) << ".html\">" << pageNumber << "</a>," << endl;
					}
					else {
						if ((pageNumber) < 1000) {
							out << "<a href=\"page0" << (pageNumber) << ".html\">" << pageNumber << "</a>," << endl;
						}
						else {
							out << "<a href=\"page" << (pageNumber) << ".html\">" << pageNumber << "</a>," << endl;
						}
					}
				}
			}
		}
		nodeHead = nodeHead->next;
	}


	out << "</body>" << endl << "</html>" << endl;
}
