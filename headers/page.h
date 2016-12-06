#ifndef PAGE_H
#define PAGE_H

#include<string>

struct Page{
std::string pageContent;
int pageNumber;
std::string title;
bool isFirstPage;
bool isLastPage;

void creatHtmlPage();
};

#endif
