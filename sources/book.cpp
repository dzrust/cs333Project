#include "book.h"
#include "index.h"
#include <iostream>
#include <fstream>
#include <string>
#include "indexConstants.h"

    Book::Book(){

	};

    Book::~Book(){
	};

	// Strips all punctuation (except hyphens) from a word and
// changes any upper-case characters to lower-case. Note that
// if a word has nothing except punctuation, this may reduce
// it to the empty string.
string reduceWords (string word)
{
  string result;
  for (int i = 0; i < word.size(); ++i)
    {
      char c = word[i];
      if (c == '-')
	result += c;
      else if (c >= 'a' && c <= 'z')
	result += c;
      else if (c >= 'A' && c <= 'Z')
	result += (c - 'A' + 'a'); // converts to lower-case
    }
  return result;
}

    void Book::createIndex(){
        index.createHtmlFile(title);
	}

    void Book::createBook(istream& input){
        string word;
        int count =0;
                Page p;
                p.isFirstPage = true;
                p.isLastPage = false;
                p.pageContent = "";
                p.pageNumber = 1;
                p.title = title;
        while(input >> word){
            if(count == MAX_LINES_PER_PAGE){
                    pages.push_back(p);
                    p.creatHtmlPage();
                p.isFirstPage = false;
                p.isLastPage = false;
                p.pageContent = word + " ";
                p.pageNumber++;
                count = 0;
            }else{
                p.pageContent += word + " ";
                count++;
            }
            word = reduceWords(word);
            if(word != ""){
                index.containedWords.addWordOrLocation(word, p.pageNumber);
            }
        }
        p.isLastPage = true;
        p.creatHtmlPage();
	}

    void Book::generateStopList(){
        std::ifstream in("stoplist.txt");
        string word;
        while(in >> word){
            stopList.addWordOrLocation(word, 0);
        }
        in.close();
	}

    void Book::setTitle(istream& input){
        string word;
        bool titleFound = false;
        while(input >> word && !titleFound){
            if(word == "Title:"){
                input >> title;
                titleFound = true;
            }
        }
	}
