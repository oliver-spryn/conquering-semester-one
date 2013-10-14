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
