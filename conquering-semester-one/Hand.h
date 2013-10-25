#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "CardGroup.h"
using std::vector;
using std::string;
using std::stringstream;

#ifndef HAND_H
#define HAND_H


class Hand : public CardGroup
{
public:
	virtual int size() {return hand.size();}
	virtual void addCard(CardGroup& group);
	virtual vector<Card> removeCard(); //returns a vector<Card> of size 1 with the Card() if the user doesn't want to remove cards
	bool hasTerrCard(string terrName);
	void print();

private:
	vector<Card> hand;
};

class Tried_to_remove_card_from_empty_hand {};
class Tried_to_remove_nonexistent_card {};

#endif