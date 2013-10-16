#include "player.h"

Player::Player(string playerName, int playerColor, map<string, Territory>& playerTerr, Deck& playerCards)
{
	allCards = playerCards;
	name = playerName;
	color = playerColor;
	myTerr = playerTerr;
}
	
vector<Territory*> Player::getTerr()
{
	return myTerr;
}