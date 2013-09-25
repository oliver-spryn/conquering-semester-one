#include <iostream>
#include <vector>
#include "Player.h"
using std::vector;

#ifndef GAME_H
#define GAME_H

class Game
{
public:
	void setup();
	void play();
	void firstTurn();
private:
	vector <Player> players;
};

#endif