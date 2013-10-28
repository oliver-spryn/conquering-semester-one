#include "Game.h"
#include "windows.h"
using std::map;

Game::Game() : deck(new Deck("card-list.txt")), terrConquered(false) {
	srand(time(0));
	text.push_back("Replace me :D");
	align.push_back('C');

//Initialize teh Territory pointerz :)
	ifstream fin;
	char terr[256];
	char tangent[256];
	fin.open("territory-list.txt");
	
//Add each of the territories to a container
	while(!fin.eof()) {
		fin.getline(terr, 256);

	//Lines that begin with a tab indicate tangent territories
		if (terr[0] != '\t')
			territories.push_back(new Territory(terr));
	}

//Start anew <--- poetic ;)
	fin.seekg(0);

//Add each of the tangent territories
	string convert;
	fin.getline(tangent, 256); // Get the first territory out of the way ;)

	for(int i = 0; i < territories.size(); ++i) {
	//Lines that begin with a tab indicate tangent territories
		while(true) {
			fin.getline(tangent, 256);

			if (tangent[0] == '\t') {
				convert = tangent;
				convert = convert.substr(1);

				for (int j = 0; j < territories.size(); ++j) {
					if (territories[j]->getName() == convert) {
						territories[i]->addTangent(territories[j]);
					}
				}
			} else {
				break;
			}
		}
	}
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
	int i = 0;
	while(true){
		for(i=currentPlayer; i<players.size(); i++){
			reinforcementsPhase(players[i]);    //reinforcements phase
		    attackPhase(players[i]);    //attack phase
			fortifyPhase(players[i]);    //fortify phase
			if (terrConquered)
				endTurn(players[i]);    //draw a card if a territory is conquered
		}
		currentPlayer = 0;
	}
}

void Game::firstTurn()
{
	setTitle("Determining Who Starts the Game");

	int numPlayers = players.size();
    int numTrues = 0;
    vector<bool> maybeFirst;
    for(int i = 0; i<numPlayers; i++)
	    maybeFirst.push_back(true);

    vector<int> rolls;
	    for(int i = 0; i<numPlayers; i++) {
		    if(maybeFirst[i])
			    rolls.push_back(roll());
        }

    do {
	    for(int i = 0; i<numPlayers; i++) {
		    if(maybeFirst[i])
			    rolls[i] = roll();
        }
	
	    for(int i=0; i<numPlayers-1; i++) {
		    if(maybeFirst[i]) {
			    for(int j=i+1; j<numPlayers; j++) {
				    if(maybeFirst[j]) {
					    if(rolls[i] > rolls[j])
                            maybeFirst[j] = false;
                        else if(rolls[i] < rolls[j]) {
                           maybeFirst[i] = false;
                           break;
                        }
				    }				
			    }
		    }
	    }
      
        cout << '\n';
        numTrues = 0;
        for(int i =0; i<numPlayers; i++)
            if(maybeFirst[i])
                numTrues++;
    } while(numTrues > 1);

	int i = 0;

	for(i; i<numPlayers; i++) {
		if(maybeFirst[i]) {
			Display::setTextColor(players[i].getColor());
			cout << endl << players[i].getName();
			Display::resetTextColor();
			cout << " you go first!" << endl;
			currentPlayer = i;
			break;
		}
    }

	//distributing soldiers.
	vector<int> numTroops(players.size());
	int initDistribution = (deck->size() / players.size());
	int remainder = deck->size() % players.size();

	for(int i=0; i<numTroops.size(); i++)
		numTroops[i] = initDistribution;
	for(int i=numTroops.size()-1; remainder > 0; i--) {
		numTroops[i]++;
		remainder--;
	}



	pause();
}

void Game::reinforcementsPhase(Player p) {
    ;
}
void Game::attackPhase(Player p) {
    while(true) {
    vector<Territory *> attTerr;
    // populate list of territories that the player can attack from (with # of troops in parenthesis)
    for(int i = 0; i < territories.size(); i++) {
        if(territories[i]->getOwner() == p) {
            attTerr.push_back(territories[i]);
            cout << i << " - " << territories[i]->getName() << "(" << territories[i]->getNumTroops << ")" << endl;
        }
    }
    
    int a=-1;
    while(a<0 || a >= territories[i]->size()) {
        cout << "Enter the number corresponding to the territory from which you would like to attack : ";
        cin >> a;
        cout << '\n';
    }

    //populate a list of territories that the player can attack (with the # of troops in parenthesis)
    vector<Territory *> defTerr = attTerr[a]->getTanget();
    for(int i = 0; i < defTerr.size(); i++) {
        if(defTerr[i]->getOwner() != p) {
            attTerr.push_back(territories[i]);
            cout << i << " - " << territories[i]->getName() << "(" << territories[i]->getNumTroops << ")" << endl;
        }
    }
        
    int d=-1;
    while(d<0 || d >= territories[i]->size()) {
        cout << "Enter the number corresponding to the territory which you would like to attack : ";
        cin >> d;
        cout << '\n';
    }
        Assault battle(attTerr[a], defTerr[d]);  // instantiates object of type Assault that handles the battle
            if(battle.attack()) {  //begins the assault
                terrConquered = true;    //set player value that holds if a territory was conquered to true
                battle.terrAcquisition();
            }
    }
}
void Game::fortifyPhase(Player p) {
    ;
}

void Game::endTurn(Player p) { 
	Hand* h = p.getHand();
    //if it was, the player gets a card and sets value back to false
	h->addCard(*deck);
	delete h;

	terrConquered = false;
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

vector<Territory*> Game::playerOwns(Player &p) {
	vector<Territory*> ret;

	for (int i = 0; i < territories.size(); ++i) {
		if (territories[i]->getOwner() == p) {
			ret.push_back(territories[i]);
		}
	}

	return ret;
}