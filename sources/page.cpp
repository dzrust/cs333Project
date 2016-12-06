#include "page.h"
#include<string>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void Page::creatHtmlPage(){
    std::string page = "0000";
    if(pageNumber < 10){
        page = "000" + pageNumber;
    }else{
        if(pageNumber < 100){
        page = "00" + pageNumber;
        }else{
            if(pageNumber < 1000){
                page = "0" + pageNumber;
                }else{
                page = "" + pageNumber;
                }
    }
    }
    std::string path = "D:\\Documents\\TestProjectOutput\\page" + page + ".html";
      char * cstr = new char [path.length()+1];
  std::strcpy (cstr, path.c_str());
    std::ofstream out(cstr);
    out << "<html>" << endl << "<head>" << endl << "<title>" << title << "</title>" << endl << "</head>" << endl << "<body>" << endl << "<p>" << endl;
    if(isFirstPage){
        out << "<a href=\"page0001.html\">First</a>," << endl;
        out << "<a href=\"page0002.html\">Next</a>," << endl;
    }else{
        out << "<a href=\"page0001.html\">First</a>," << endl;
        if(isLastPage){
                if(pageNumber-1 < 10){
                    out << "<a href=\"page000" << (pageNumber-1)<<".html\">Prev</a>," << endl;
                }else{
                    if((pageNumber-1) < 100){
                    out << "<a href=\"page00"<< (pageNumber-1)<<".html\">Prev</a>," << endl;
                    }else{
                    if((pageNumber-1) < 1000){
                    out << "<a href=\"page0" <<(pageNumber-1)<<".html\">Prev</a>," << endl;
                    }else{
                    out << "<a href=\"page"<< (pageNumber-1)<<".html\">Prev</a>," << endl;
                    }
                    }
                }

        }else{
                            if((pageNumber-1) < 10){
                    out << "<a href=\"page000" <<(pageNumber-1)<<".html\">Prev</a>," << endl;
                }else{
                    if((pageNumber-1) < 100){
                    out << "<a href=\"page00"<< (pageNumber-1)<<".html\">Prev</a>," << endl;
                    }else{
                    if((pageNumber-1) < 1000){
                    out << "<a href=\"page0"<< (pageNumber-1)<<".html\">Prev</a>," << endl;
                    }else{
                    out << "<a href=\"page"<< (pageNumber-1)<<".html\">Prev</a>," << endl;
                    }
                    }
                }

                                if((pageNumber+1) < 10){
                    out << "<a href=\"page000" <<(pageNumber+1)<<".html\">Next</a>," << endl;
                }else{
                    if((pageNumber+1) < 100){
                    out << "<a href=\"page00" <<(pageNumber+1)<<".html\">Next</a>," << endl;
                    }else{
                    if((pageNumber+1) < 1000){
                    out << "<a href=\"page0" <<(pageNumber+1)<<".html\">Next</a>," << endl;
                    }else{
                    out << "<a href=\"page"<< (pageNumber+1)<<".html\">Next</a>," << endl;
                    }
                    }
                }
        }
    }

    out << "<a href=\"indexPage.html\">Index</a>" << endl <<
                "</p>" << endl << "<hr/>" << "<pre>" << endl;
                out << pageContent << endl << "</pre>" << endl << "</body>" << endl << "</html>" << endl;
};
