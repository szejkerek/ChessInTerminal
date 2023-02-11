#ifndef QUEEN
#define QUEEN

#include "Piece.h"
#include "../functions.h"
class Queen : public Piece
{
public:
	Queen(Coords pos, bool color);
	std::vector<std::vector<Coords>> virtual ValidMoves();
};

#endif