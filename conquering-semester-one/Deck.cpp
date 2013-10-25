#include "Deck.h"
using std::swap;
using std::cout;
using std::endl;
using std::ifstream;

Deck::Deck(string filename)
{	
	ifstream fin;
	fin.open(filename);
	if(fin.fail()) {
		throw Failed_to_open_file_for_deck_input();
	}
	else {
		Card c;
		while(fin >> c) {
			deck.push_back(c);
		}

	}
	fin.close();
}

void Deck::addCard(CardGroup& group) //there is a problem here...hand.removeCard() always has an interface...
{
	deck.push_front(group.removeCard());
}

Card Deck::removeCard()
{
	if(empty()) {
		cout << "Error: cannot draw from an empty deck." << endl;
		throw Tried_to_draw_from_empty_deck();
	}
	Card temp = deck.back();
	deck.pop_back();
	return temp;
}

void Deck::shuffle()
{
	int a, b, deckSize;

	deckSize = deck.size();
	for(int i=0; i<10000; i++)
	{
		a = rand() % deckSize;
		b = rand() % deckSize;
		swap(deck[a], deck[b]);
	}
}