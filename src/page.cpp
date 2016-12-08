#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include "page.h"

void Page::creatHtmlPage() {
	std::string page = "0000";
	std::stringstream ss;
	if (pageNumber < 10) {
		ss << "000" << pageNumber;
	}
	else {
		if (pageNumber < 100) {
			ss << "00" << pageNumber;
		}
		else {
			if (pageNumber < 1000) {
				ss << "0" << pageNumber;
			}
			else {
				ss << "" << pageNumber;
			}
		}
	}
	page = ss.str();
	//std::string path = "D:\\Documents\\TestProjectOutput\\page" + page + ".html";
	std::string path = "page" + page + ".html";
	char * cstr = new char[path.length() + 1];
	std::strcpy(cstr, path.c_str());
	std::ofstream out(cstr);
	out << "<html>" << std::endl << "<head>" << std::endl << "<title>" << title << "</title>" << std::endl << "</head>" << std::endl << "<body>" << std::endl << "<p>" << std::endl;
	if (isFirstPage) {
		out << "<a href=\"page0001.html\">First</a>," << std::endl;
		out << "<a href=\"page0002.html\">Next</a>," << std::endl;
	}
	else {
		out << "<a href=\"page0001.html\">First</a>," << std::endl;
		if (isLastPage) {
			if (pageNumber - 1 < 10) {
				out << "<a href=\"page000" << (pageNumber - 1) << ".html\">Prev</a>," << std::endl;
			}
			else {
				if ((pageNumber - 1) < 100) {
					out << "<a href=\"page00" << (pageNumber - 1) << ".html\">Prev</a>," << std::endl;
				}
				else {
					if ((pageNumber - 1) < 1000) {
						out << "<a href=\"page0" << (pageNumber - 1) << ".html\">Prev</a>," << std::endl;
					}
					else {
						out << "<a href=\"page" << (pageNumber - 1) << ".html\">Prev</a>," << std::endl;
					}
				}
			}

		}
		else {
			if ((pageNumber - 1) < 10) {
				out << "<a href=\"page000" << (pageNumber - 1) << ".html\">Prev</a>," << std::endl;
			}
			else {
				if ((pageNumber - 1) < 100) {
					out << "<a href=\"page00" << (pageNumber - 1) << ".html\">Prev</a>," << std::endl;
				}
				else {
					if ((pageNumber - 1) < 1000) {
						out << "<a href=\"page0" << (pageNumber - 1) << ".html\">Prev</a>," << std::endl;
					}
					else {
						out << "<a href=\"page" << (pageNumber - 1) << ".html\">Prev</a>," << std::endl;
					}
				}
			}

			if ((pageNumber + 1) < 10) {
				out << "<a href=\"page000" << (pageNumber + 1) << ".html\">Next</a>," << std::endl;
			}
			else {
				if ((pageNumber + 1) < 100) {
					out << "<a href=\"page00" << (pageNumber + 1) << ".html\">Next</a>," << std::endl;
				}
				else {
					if ((pageNumber + 1) < 1000) {
						out << "<a href=\"page0" << (pageNumber + 1) << ".html\">Next</a>," << std::endl;
					}
					else {
						out << "<a href=\"page" << (pageNumber + 1) << ".html\">Next</a>," << std::endl;
					}
				}
			}
		}
	}

	out << "<a href=\"indexPage.html\">Index</a>" << std::endl <<
		"</p>" << std::endl << "<hr/>" << "<pre>" << std::endl;
	out << pageContent << std::endl << "</pre>" << std::endl << "</body>" << std::endl << "</html>" << std::endl;
};
