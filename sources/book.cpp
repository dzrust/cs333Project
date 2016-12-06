#include "book.h"
#include "index.h"

    Book::Book(){

	};

    Book::~Book(){
		delete pages;
	};

    void Book::createIndex(){
        index.createHtmlFile(title);
	};

    void Book::createBook(){

	};

    void Book::generateStopList(){

	}

    void Book::setTitle(){

	}
