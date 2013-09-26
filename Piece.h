#ifndef PIECE_H
#define PIECE_H

class Piece
{
public:
	int getNumPieces() {return numPieces;} //accessor function
	void changeNumPieces(int num) {numPieces += num;} //add or subtract number of pieces
protected:
	int numPieces;
};

#endif