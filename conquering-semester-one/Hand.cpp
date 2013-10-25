#include "Hand.h"
using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::string;

void Hand::addCard(CardGroup& group)
{
	Card c; 
	hand.push_back(c = group.removeCard());
	if(c.name.size() > largestName)
		largestName = c.name.size();

	string s;
	stringstream ss;
	ss << c.value;
	s = ss.str();
	ss.clear();
	
	if(strlen(s.c_str()) > sizeOfLargestValue)
		sizeOfLargestValue = strlen(s.c_str());
}

Card Hand::removeCard()
{
	Card c;
	if(empty()) {
		cout << "Error: Cannot remove card from an empty hand" << endl;
		throw(Tried_to_remove_card_from_empty_hand());
	}
	else {

		int choice = -1;
		//bool chosen = false;
		//vector<int> options;
		//for(int i=1; i<hand.size()+1; i++)
			//options.push_back(i);
		int *options = new int[hand.size()];
		for(int i=0; i<hand.size()+1; i++)
			options[i] = i;
		//may not need this...
		system("cls");
		//******************

		for(int i=0; i<hand.size(); i++) {
			cout << left << setw(6) << "(" << options[i] << ")";
			cout << left << setw(largestName + 2) << hand[i].name;
			cout << left << setw(sizeOfLargestValue) << hand[i].value << endl << endl;
		}
		while(choice == -1) {
			cout << "Please enter the number of the card you wish to discard, or 0 to return to the previous screen" << endl;
			cout << "Choice: ";
			choice = getValidIntChoice(options, hand.size()+1);
		}
		if(choice == 0)
			return Card(); //return default constructor if the user doesn't wish to continue
		else
			c = hand.at(choice+1);

		delete [] options;

		//bool found = false;
		//auto i = hand.begin();	

		//for(i; i != hand.end(); i++) {
		//	if(*i == c) {
		//		hand.erase(i);
		//		found = true;
		//		break;
		//	}
		//}
		//if(found == false) {
		//	cout << "The card you are trying to remove is not in the hand." << endl;
		//	throw(Tried_to_remove_nonexistent_card());
		//}
	}
	return c;
}

bool Hand::hasTerrCard(string terrName)
{
	for(auto i = hand.begin(); i != hand.end(); i++) {
		if(i->name == terrName)
			return true;
	}
	return false;
}