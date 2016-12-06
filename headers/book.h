#ifndef BOOK_H
#define BOOK_H

#include "index.h"
#include "page.h"
#include "words.h"
#include <string>

const string OUTPUT_PATH = "D:\\Documents\\TestProjectOutput";
class Book{
    private:
    string title;
    Page* pages;
    Index index;
    Words stopList;

    public:
    Book();
    ~Book();

    void createIndex();

    void createBook();

    void generateStopList();

    void setTitle();
};

#endif
