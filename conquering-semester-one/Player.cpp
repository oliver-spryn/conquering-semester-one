#include "player.h"

Player::Player(string playerName, int playerColor, Deck* playerCards) {
	allCards = playerCards;
	name = playerName;
	color = playerColor;
}

bool operator == (Player& left, Player& right)
{
	return (left.getColor() == right.getColor());
}

bool operator != (Player& left, Player& right)
{
	return (left.getColor() != right.getColor());
}
	