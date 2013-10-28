#include <ctime>
#include <iostream>
#include <conio.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include "Player.h"
#include "Deck.h"
#include "Display.h"
using std::cout;
using std::cin;
using std::endl;
using std::vector;

#ifndef GAME_H
#define GAME_H

struct RollData {
	RollData() : reRoll(false), val(0) {}
	bool reRoll;
	int val;
};

class Game
{
public:
	Game();

	void setup();
	void play();
	void firstTurn();

	void reinforcementsPhase(Player p);
	void attackPhase(Player p);
	void fortifyPhase(Player p);
	void endTurn(Player p);         //draw a card if a territory is conquered
private:
	vector <Player> players;
	Deck *deck;
	vector<string> text;
	vector<char> align;
	bool terrConquered;
	//Board board;

	int roll();
	void pause();
	void setTitle(string title);
	int currentPlayer;
};

#endif