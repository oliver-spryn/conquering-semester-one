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
	Player(string playerName, int playerColor);
	string getName() {return name;}
	int getColor() {return color;}
	int getActiveTroops() {return activeTroops;}
	int getReinforcements() {return reinforcements;}
	void changeActiveTroops(int num) {activeTroops += num;} //add or remove
	void changeReinforcements(int num) {reinforcements += num;}
private:
	string name;
	int color;
	Hand hand;
	int activeTroops;
	int reinforcements;
};

#endif