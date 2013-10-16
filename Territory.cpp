#include "Territory.h"

/**
 * FRIEND FUNCTION
 * 
 * An overloaded == operator to determine if two Territory objects
 * are equal.
 *
 * @access public
 * @param  Territory& t1 The first Territory object to compare
 * @param  Territory& t2 The second Territory object to compare
 * @return bool          Whether the two territory objects are the same
*/

bool operator== (Territory& t1, Territory& t2) {
	return t1.color == t2.color && t1.continent == t2.continent && t1.name == t2.name;
}

/**
 * FRIEND FUNCTION
 * 
 * An overloaded != operator to determine if two Territory objects
 * are not equal.
 *
 * @access public
 * @param  Territory& t1 The first Territory object to compare
 * @param  Territory& t2 The second Territory object to compare
 * @return bool          Whether the two territory objects are not the same
*/

bool operator!= (Territory& t1, Territory& t2) {
	return t1.color != t2.color || t1.continent != t2.continent || t1.name != t2.name;
}

/**
 * DEFAULT CONSTRUCTOR
 * 
 * This constructor assigns the member variables their values given to
 * this constructor, and calls this class's super constructor.
 *
 * @access public
 * @param  int                color     The color of this terriory, as defined by the ENUM in Display.h
 * @param  string             continent The string name of the continent in which this territory resides
 * @param  string             name      The string name of this territory
 * @param  vector<Territory*> tangent   A vector of pointers to Territory objects indicating territories which are tangent to the current territory
 * @param  Player&            owner     A reference to the Player object which owns this territory
 * @return void
*/

Territory::Territory(int color, string continent, string name, vector<Territory*> tangent, Player& owner) : 
	TroopHandler(), color(color), continent(continent), name(name), tangent(tangent), owner(owner) { }

/**
 * Access the integer value (according to the Windows console) of this
 * territory's color.
 *
 * @access public
 * @return int    The integer value according to the Windows console) of this territory's color
*/

int Territory::getColor() const {
	return this->color;
}

/**
 * Access the name of the continent in which this territory resides.
 *
 * @access public
 * @return string The name of the continent in which this territory resides
*/

string Territory::getContinent() const {
	return this->continent;
}

/**
 * Access the name of the territory.
 *
 * @access public
 * @return string The name of the territory
*/

string Territory::getName() const {
	return this->name;
}

/**
 * Access the owner of this territory.
 *
 * @access public
 * @return string The owner of this territory
*/

Player& Territory::getOwner() const {
	return this->owner;
}

/**
 * Determine whether this territory is tangent to another territory.
 *
 * @access public
 * @param  Territory& territory A Territory object to check against the current Territory object
 * @return bool                 Whether this territory is tangent to the one passed in as an argument
*/

bool Territory::isTangentTo(Territory& territory) {
	for (vector<Territory*>::iterator it = this->tangent.begin(); it != this->tangent.end(); ++it) {
		if (**it == territory) {
			return true;
		}
	}

	return false;
}

/**
 * Set a new owner for this territory.
 *
 * @access public
 * @param  Player& owner The new owner for this territory
 * @return void
*/

void Territory::setOwner(Player& owner) {
	this->owner = owner;
}