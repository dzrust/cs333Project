#ifndef INDEX_H
#define INDEX_H

#include "words.h"

struct Index{
    Words containedWords;
    void createHtmlFile(std::string title);
};

#endif
