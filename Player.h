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
    Player();
	Player(string playerName, int playerColor);
	string getName() {return name;}
	string getColor() {return color;}
	vector<Territory*> getTerr();
private:
	Deck allCards&;
	string name;
	string color;
	Hand hand;
	vector<Territory*> myTerr;
};

#endif