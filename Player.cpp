#include "player.h"

Player::Player()
{
	allCards;
	name;
	color;
	hand;
	myTerr;
}

Player::Player(string playerName, int playerColor)
{
	allCards;
	name = playerName;
	color = playerColor;
	hand;
	myTerr;
}
	
vector<Territory*> Player::getTerr()
{

}