#ifndef BOOK_H
#define BOOK_H

#include "index.h"
#include "page.h"
#include "words.h"
#include <iostream>
#include <fstream>
#include <string>
#include<vector>

class Book{
    private:
    string title;
    vector<Page> pages;
    Index index;
    Words stopList;

    public:
    Book();
    ~Book();

    void createIndex();

    void createBook(istream& input);

    void generateStopList();

    void setTitle(istream& input);
};

    string reduceWords (string word);

#endif
