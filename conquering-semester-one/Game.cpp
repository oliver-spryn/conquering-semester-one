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
			//reinforcements phase
			//attack phase
			//fortify phase
			//draw a card if a territory is conquered
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
    ; // populate list of territories with # of troops in parenthesis
    // instantiates object of type Assault that handles the battle
        // tells you how many troops you have left after each assault
        //asks if you want to continue assaulting
    // if attacking player wins the battle, calls troop movement
}
void Game::fortifyPhase(Player p) {
    ;
}
void Game::endTurn(Player p) { 
    ;
}