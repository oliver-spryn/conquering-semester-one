#ifndef TROOP_H
#define TROOP_H

class Troop
{
public:
	int getNumTroops() {return numTroops;} //accessor function
	void changeNumTroops(int num) {numTroops += num;} //add or subtract number of Troops
protected:
	int numTroops;
};

#endif