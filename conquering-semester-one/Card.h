#include <string>
using std::string;
using std::istream;

#ifndef CARD_H
#define CARD_H

struct Card
{
	Card() : name("No_Name"), value(0){}
	Card(string n, int v) : name(n), value(v) {}

	bool anySet(); //determines if there is a set to play

	friend bool operator == (Card& left, Card& right);
	friend istream& operator >> (istream& in, Card& c);

	string name;
	int value;
};

//enum Value {SOLDIER = 1, CAVALRY, CANNON};
//
//class Card
//{
//public:
//	Value getValue() {return value;}
//	string getTerritoryName() {return territoryName;}
//private:
//	Value value;
//	string territoryName;
//}; 

#endif