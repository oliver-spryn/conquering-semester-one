#include <string>
using std::string;

#ifndef CARD_H
#define CARD_H

enum Value {SOLDIER = 1, CAVALRY, CANNON};

class Card
{
public:
	Value getValue() {return value;}
	string getTerritoryName() {return territoryName;}
private:
	Value value;
	string territoryName;
}; 

#endif