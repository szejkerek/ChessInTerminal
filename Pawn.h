#ifndef PAWN
#define PAWN

#include "Piece.h"

#include "functions.h"
class Pawn : public Piece
{
public:
	Pawn(Coords pos, bool color);
	std::vector<std::vector<Coords>> virtual ValidMoves();
};

#endif