#ifndef ROOK
#define ROOK

#include "Piece.h"
#include "../functions.h"
class Rook : public Piece
{
public:
	Rook(Coords pos, bool color);
	std::vector<std::vector<Coords>> virtual ValidMoves();
};

#endif