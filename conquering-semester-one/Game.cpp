#include "Game.h"
#include "windows.h"

Game::Game() : deck(new Deck("card-list.txt")) {
	srand(time(0));
	text.push_back("Replace me :D");
	align.push_back('C');
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

	vector<string> colorNames;
	colorNames.push_back("pink");
	colorNames.push_back("green");
	colorNames.push_back("yellow");
	colorNames.push_back("blue");
	colorNames.push_back("white");
	colorNames.push_back("red");

//Get number of players
    int numPlayers = 2;

	do {
		setTitle("Beginning the Game");

		if (numPlayers < 2 || numPlayers > 6) {
			Display::coloredText("Try again...", red);
			cout << endl;
		}

		cout << "Enter the number of players (2-6): ";
		cin >> numPlayers;
	} while (numPlayers < 2 || numPlayers > 6);
	

//Build the set of information for creating the Player class
	setTitle("Getting to Know You");
	cout << numPlayers << " players" << endl << endl;

	for(int i = 0; i < numPlayers; ++i) {
	//Get name of player
		string name;
		
		cout << "Player " << i + 1 << " enter your name: ";
		cin >> name;
        Player player(name,colors[i], deck);
		
	//Add the Player to the container
		players.push_back(player);
    }

//Show the players their colors
	setTitle("Assigning Player Colors");

	for(int i = 0; i < numPlayers; ++i) {
		Display::setTextColor(colors[i]);
		cout << players[i].getName() << ", you have been assigned the " << colorNames[i] << " color" << endl;
	}

	Display::resetTextColor();

	cout << endl << "Please get the appropriate colored pieces for the game.";
	pause();
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
	setTitle("Determining Who Starts the Game");

//Roll the die for each of the users
	vector<int> firstRolls(players.size());
	int max = 0, maxIndex = 0, dupRoll = 0;

	cout << "Everyone is rolling their dice..." << endl << endl;

	do {
		for(int i = 0; i < players.size(); ++i) {
			firstRolls[i] = roll();

		//Do we have a winner, yet?
			if (firstRolls[i] > max) {
				max = firstRolls[i];
				maxIndex = i;
			}

		//Rats... we have a duplicate roll
			if (firstRolls[i] == max) {
				dupRoll = max;
			}

			Display::setTextColor(players[i].getColor());
			cout << players[i].getName() << ", you rolled a " << firstRolls[i] << endl;
		}
	} while (dupRoll == max);

//Show the results of who won the roll
	Display::setTextColor(players[maxIndex].getColor());
	cout << endl << players[maxIndex].getName();
	Display::resetTextColor();
	cout << " you go first!" << endl;

	pause();

//Thanks http://www.cprogramming.com/tutorial/computersciencetheory/sorting1.html
	/*for(int x=0; x<n; x++)

	{

		for(int y=0; y<n-1; y++)

		{

			if(array[y]>array[y+1])

			{

				int temp = array[y+1];

				array[y+1] = array[y];

				array[y] = temp;

			}

		}

	}*/
}

void Game::reinforcementsPhase(Player p) {
    ;
}
void Game::attackPhase(Player p) {
    // populate list of territories that the player can attack from (with # of troops in parenthesis)
        //populate a list of territories that the player can attack (with the # of troops in parenthesis)
    
            //Assault battle(attackingTerr, defendingTerr);  // instantiates object of type Assault that handles the battle
            //if(battle.begin()) {  //begins the assault
                //set player value that holds if a territory was conquered to true
            //}
}
void Game::fortifyPhase(Player p) {
    ;
}
void Game::endTurn(Player p) { 
    ;//checks to see if a territory was captured
       //if it was, the player gets a card and sets value back to false
}

int Game::roll() {
	return (rand() % 5) + 1;
}

void Game::setTitle(string title) {
	text[0] = title;

	Display::clear();
	Display::setTextColor(gBlack);
	cout << Display::distribute(text, align);
	Display::resetTextColor();
	cout << endl;
}

void Game::pause() {
	cout << endl << endl << "Press any key to continue to the next step...";

	_getch();
}