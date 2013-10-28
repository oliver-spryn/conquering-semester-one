#include <ctime>
#include <iostream>
#include <conio.h>
#include <vector>
#include <stdlib.h>
#include <fstream>

#include "Territory.h"
#include "Player.h"
#include "Deck.h"
#include "Display.h"
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::vector;

#ifndef GAME_H
#define GAME_H

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
	vector <Territory*> territories;
	vector<string> text;
	vector<char> align;

	int roll();
	void pause();
	void setTitle(string title);
	int currentPlayer;
};

#endif