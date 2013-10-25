#include "Card.h"

bool operator == (Card& left, Card& right)
{
	return ((left.name == right.name) && (left.value == right.value));
}

istream& operator >> (istream& in, Card& c)
{
	string n;
	int v;

	std::getline(in, n);
	in >> v;

	c.name = n;
	c.value = v;

	return in;
}