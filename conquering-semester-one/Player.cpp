#include "player.h"

Player::Player(string playerName, int playerColor, Deck* playerCards)
{
	allCards = playerCards;
	name = playerName;
	color = playerColor;
}
	