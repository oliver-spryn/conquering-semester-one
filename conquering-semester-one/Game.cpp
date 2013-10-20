#include "Game.h"

void Game::setup()
{
    int numPlayers;    
	cout << "Enter the number of players (2-5): ";//get number of players
    cin >> numPlayers; //set up other options
	for(int i=0; i < numPlayers; i++) { //populate a private containers of players
        
    }
}
void Game::play()
{
	firstTurn();

	while(true){
		for(int i=0; i<players.size(); i++){
			reinforcementsPhase(players[i]);    //reinforcements phase
		    attackPhase(players[i]);    //attack phase
			fortifyPhase(players[i]);    //fortify phase
			endTurn(players[i]);    //draw a card if a territory is conquered
		}
	}
}
void Game::firstTurn()
{
	//players roll die to determine order and reorder the vector of players accordingly
	//initial troop placement
}

void Game::reinforcementsPhase(Player p) {
    ;
}
void Game::attackPhase(Player p) {
    // populate list of territories that the player can attack from (with # of troops in parenthesis)
        //populate a list of territories that the player can attack (with the # of troops in parenthesis)
    
            //Assault battle(attackingTerr, defendingTerr);  // instantiates object of type Assault that handles the battle
            //battle.begin();   //begins the assault
            //if(battle.isConquered()) {  //if the territory was conquered
                //battle.troopMovement();   //allows player to move troops to conquered territory
                //set player value that holds if a territory was conquered to true
            //}
    // if attacking player wins the battle, calls troop movement
}
void Game::fortifyPhase(Player p) {
    ;
}
void Game::endTurn(Player p) { 
    ;//checks to see if a territory was captured
       //if it was, the player gets a card and sets value back to false
}