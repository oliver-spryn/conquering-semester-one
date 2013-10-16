#include <string>
#include <vector>
#include "Hand.h"
using std::string;
using std::vector;

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	Player(string playerName, int playerColor, map<string, Territory>& playerTerr, Deck& playerCards);
	string getName() {return name;}
	string getColor() {return color;}
	vector<Territory*> getTerr();
private:
	string name;
	int color;
	Deck allCards&;
	vector<Territory*> myTerr;
	Hand hand;
};

#endif