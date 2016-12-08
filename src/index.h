#ifndef INDEX_H
#define INDEX_H

#include "words.h"

struct Index {
	Words containedWords;
	void createHtmlFile(string title, int numberOfPages);
};

#endif
