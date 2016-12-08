#include <iostream>
#include <fstream>
#include <string>
#include "index.h"
#include "words.h"
#include "indexConstants.h"

void Index::createHtmlFile(std::string title, int numberOfPages) {
	//std::ofstream out("D:\\Documents\\TestProjectOutput\\index.html");
	std::ofstream out("indexPage.html");
	out << "<html>" << std::endl
		<< "<head>" << std::endl
		<< "<title>" << title << "</title>" << std::endl
		<< "</head>" << std::endl
		<< "<body>" << std::endl
		<< "<p>" << std::endl
		<< "<a href=\"page0001.html\">First</a>" << std::endl
		<< "</p>" << std::endl
		<< "<hr/>" << std::endl
		<< "<p>" << std::endl;
	Words::ListNode* nodeHead = containedWords.wordHead;
	char currentIndex = 'A';
	while (nodeHead != 0) {
		std::string word = nodeHead->data.newWord;
		if (word.at(0) != currentIndex) {
			currentIndex = word.at(0);
			out << "<a href=\"#" << currentIndex << "\">" << currentIndex << "</a>" << std::endl;

		}
		nodeHead = nodeHead->next;
	}

	out << "</p>" << std::endl << "<hr />" << std::endl << "<h1>Index</h1>" << std::endl;

	nodeHead = containedWords.wordHead;
	currentIndex = 'A';
	bool firstLetter = true;
	while (nodeHead != 0) {
		std::string word = nodeHead->data.newWord;
		int length = nodeHead->data.wordLocations.size();
		double percentage = 100*((length)/(double)(numberOfPages));
		if (percentage <= PAGE_THRESHOLD) {
			if (word.at(0) != currentIndex) {
				currentIndex = word.at(0);
				if (!firstLetter) {
					out << "</ul>" << std::endl;
				}
				else {
					firstLetter = false;
				}
				out << "<h2 id=\"" << currentIndex << "\">" << currentIndex << "</h2>" << std::endl << "<ul>" << std::endl;

			}
			out << "<li>" << word << std::endl;
			int length = nodeHead->data.wordLocations.size();
			for (int i = 0; i < length; i++) {
				int pageNumber = nodeHead->data.wordLocations[i];
				if ((pageNumber) < 10) {
					out << "<a href=\"page000" << (pageNumber) << ".html\">" << pageNumber << "</a>," << std::endl;
				}
				else {
					if ((pageNumber) < 100) {
						out << "<a href=\"page00" << (pageNumber) << ".html\">" << pageNumber << "</a>," << std::endl;
					}
					else {
						if ((pageNumber) < 1000) {
							out << "<a href=\"page0" << (pageNumber) << ".html\">" << pageNumber << "</a>," << std::endl;
						}
						else {
							out << "<a href=\"page" << (pageNumber) << ".html\">" << pageNumber << "</a>," << std::endl;
						}
					}
				}
			}
		}
		nodeHead = nodeHead->next;
	}


	out << "</body>" << std::endl << "</html>" << std::endl;
}
