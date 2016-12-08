#ifndef PAGE_H
#define PAGE_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include "page.h"


struct Page {
	std::string pageContent;
	int pageNumber;
	std::string title;
	bool isFirstPage;
	bool isLastPage;

	void creatHtmlPage();
};

#endif
