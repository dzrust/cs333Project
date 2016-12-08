#ifndef INDEX_H
#define INDEX_H

#include <iostream>
#include <fstream>
#include <string>
#include "index.h"
#include "words.h"
#include "indexConstants.h"


struct Index {
	Words containedWords;
	void createHtmlFile(std::string title, int numberOfPages);
};

#endif
