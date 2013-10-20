#include "Assault.h"

/**
 * DEFAULT CONSTRUCTOR
 * 
 * This constructor assigns the member variables their values given to
 * this constructor.
 *
 * @access public
 * @param  Territory                color     The color of this terriory, as defined by the ENUM in Display.h
 * @param  Territory             continent The string name of the continent in which this territory resides
 * @return void
*/

Assault::Assault(Territory attackingTerr, Territory defendingTerr) {
    this->attackingTerr = attackingTerr;
    this->defendingTerr = defendingTerr;
}

/**
 * This function handles the attacking between territories.
 *
 * @access public
 * @return void
*/

void Assault::attack() {
    
    
}

/**
 * Moves troops from attackingTerr to conquered defendingTerr.
 *
 * @access public
 * @return void
*/

void Assault::troopMovement() {
    ;
}

/**
 * This function returns the value of terrCaptured();
 *
 * @access public
 * @return bool
*/

bool Assault::terrCaptured() {
    ;
}


