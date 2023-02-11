#ifndef KING
#define KING

#include "Piece.h"
#include "../functions.h"
class King : public Piece
{
public:
	King(Coords pos, bool color);
	std::vector<std::vector<Coords>> virtual ValidMoves();
};

#endif