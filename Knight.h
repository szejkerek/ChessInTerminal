#ifndef KNIGHT
#define KNIGHT

#include "Piece.h"
#include "functions.h"
class Knight : public Piece
{
public:
	Knight(Coords pos, bool color);
	std::vector<std::vector<Coords>> virtual ValidMoves();
};

#endif