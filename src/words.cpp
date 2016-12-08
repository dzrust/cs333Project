#include <vector>
#include <iostream>
#include "words.h"

using namespace std;
Words::Words() {
	wordHead = NULL;
};

Words::~Words() {
	// Delete all the nodes making up this primary's linked list
	ListNode* current = wordHead;
	while (current != NULL)
	{
		ListNode* next = current->next;
		delete current;
		current = next;
	}

};

void Words::addWordOrLocation(std::string newWord, int location) {
	ListNode* temp = findWord(newWord);
	word wrd(newWord, location);
	if (temp != 0) {
		if (!(temp->data.locationAdded(location))) {
			//Add location
			temp->data.wordLocations.push_back(location);
		}
	}
	else {
		//add new word
		temp = wordHead;
		ListNode* previous = NULL;
		if (temp == 0) {
			wordHead = new ListNode(wrd, NULL);
		}
		else {
			while (temp->next != NULL && temp->data.newWord < newWord) {
				previous = temp;
				temp = temp->next;
			}
			if (previous == NULL)
			{
				wordHead = new ListNode(wrd, wordHead);
			}
			else
			{
				ListNode* newNode = new ListNode(wrd, temp);
				previous->next = newNode;
			}
		}
	}
}

bool Words::inStopList(std::string word, Words stopList) {
	bool found = false;
	found = (stopList.findWord(word) != NULL);
	return found;
}

Words::ListNode* Words::findWord(std::string word) {
	ListNode* wrd = wordHead;
	bool foundWord = false;
	while (wrd != NULL && !foundWord) {
		if (wrd->data.newWord == word) {
			foundWord = true;
		}
		else {
			wrd = wrd->next;
		}
	}
	return wrd;
}

//  private:

Words::word::word(string nWord, int nLocation)
{
	newWord = nWord;
	wordLocations.push_back(nLocation);
}

bool Words::word::locationAdded(int location) {
	int length = wordLocations.size();
	bool locationFound = false;
	for (int i = 0; i < length && !locationFound; i++) {
		if (wordLocations[i] == location) {
			locationFound = true;
		}
	}
	return locationFound;
}
