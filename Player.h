#include <string>
#include <vector>
#include "Card.h"
using std::string;
using std::vector;

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	Player(string playerName);//,color namespace?);
private:
	string name;
	//color;
	vector<Card> hand;
	int activeTroops;
	int reinforcements;
};

#endif