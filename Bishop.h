#ifndef BISHOP
#define BISHOP

#include "Piece.h"
#include "functions.h"
class Bishop : public Piece
{
public:
	Bishop(Coords pos, bool color);
	std::vector<std::vector<Coords>> virtual ValidMoves();
};

#endif