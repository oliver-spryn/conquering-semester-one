#include "Game.h"

Game::Game() : deck(new Deck("card-list.txt")) {
	srand(time(0));
}

void Game::setup()
{
	//Assign the colors
	vector<int> colors;
	colors.push_back(pink);
	colors.push_back(green);
	colors.push_back(yellow);
	colors.push_back(blue);
	colors.push_back(white);
	colors.push_back(red);

	//Get number of players
    int numPlayers;
	cout << "Enter the number of players (2-6): ";
    cin >> numPlayers;

	//Build the set of information for creating the Player class
	for(int i=0; i < numPlayers; i++) {
		string name;
		//get name of player
		cout << "Player " << i + 1 << " enter your name: ";
		cin >> name;
        Player player(name,colors[i], deck);
		
		//Add the player to the container
		players.push_back(player);
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

int Game::roll() {
	return rand() % 5 + 1;
}