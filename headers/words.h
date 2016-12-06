#ifndef WORDS_H
#define WORDS_H

using namespace std;

#include <vector>
#include <iostream>

struct Words {
  Words();

  ~Words();

  //Adds word to linked list in order
  void addWordOrLocation (std::string newWord, int location);

  bool inStopList(std::string newWord, Words stopList);

  // ==============================================
  // All information below this line is hidden
private:

  struct word {
std::string newWord;
vector<int> wordLocations;
bool locationAdded(int location);
};

public:
struct ListNode {
    word data;
    ListNode* next;

    ListNode (const word& newWord, ListNode* nxt = 0)
      : data(newWord), next(nxt)
    {}
  };


 ListNode* findWord(std::string newWord);


    ListNode* wordHead;

};
#endif
