#ifndef SQUARE
#define SQUARE

#include <utility>
#include "Piece.h"

class Square
{
public:
	//public fields
	std::shared_ptr<Piece> pPiece;

	//construktor
	Square();

	//methods
	bool DoesExist();
	void RemovePiece();
	void MovePiece( Square& to);
	void SetPiece(std::shared_ptr<Piece> newPiece);
	
	//operator
	friend std::ostream& operator<<(std::ostream& out, const Square& _square);

};

#endif