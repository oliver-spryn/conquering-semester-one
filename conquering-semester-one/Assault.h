/**
 * Assaults class
 *
 * This class is designed to manage assaults between two
 * territories
 *
 * @author    Zac Stahl
 * @namespace global
 * @package   assault
*/

#ifndef ASSAULT_H
#define ASSAULT_H

#include "Display.h"
#include "Player.h"
#include "Territory.h"

class Assault {
private : 
    Territory attackingTerr, defendingTerr;
    bool isConquered();

public : 
    Assault(Territory, Territory);

    void attack();
    void troopMovement();
    bool terrCaptured();
};

#endif