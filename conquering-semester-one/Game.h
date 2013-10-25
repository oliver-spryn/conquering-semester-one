#include <iostream>
#include <vector>
#include "Player.h"
#include "Deck.h"
#include "Display.h"
using std::cout;
using std::cin;
using std::vector;

#ifndef GAME_H
#define GAME_H

class Game
{
public:
	void setup();
	void play();
	void firstTurn();

	void reinforcementsPhase(Player p);
	void attackPhase(Player p);
	void fortifyPhase(Player p);
	void endTurn(Player p);         //draw a card if a territory is conquered
private:
	vector <Player> players;
	Deck deck;
	//Board board;
};

#endif