#include "Pawn.h"
using namespace std;
Pawn::Pawn(Coords pos, bool color):Piece(pos, color) 
{
	name = "Pion";
	if (color == WHITE)
	{
		this->symbol = 'P';
	}
	if (color == BLACK)
	{
		this->symbol = 'p';
	}
}

vector<vector<Coords>> Pawn::ValidMoves()
{
	return vector<vector<Coords>>();
}
