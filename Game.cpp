#include "Game.h"

void Game::setup()
{
	//get number of players
	//set up other options
	//populate a private containers of players

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
}
