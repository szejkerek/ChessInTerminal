#include "Piece.h"

using namespace std;

Piece::Piece(Coords _coords, bool _color) : position({ _coords.x,_coords.y }), color(_color) {}

char Piece::GetSymbol()
{
	return this->symbol;
}

string Piece::GetName()
{
	return this->name;
}

Coords Piece::GetCoords()
{
	return this->position;
}

bool Piece::GetColor()
{
	return this->color;
}

bool Piece::HaveMoved()
{
	return this->haveMoved;
}

void Piece::Moved()
{
	haveMoved = true;
}

void Piece::SetCoords(Coords _coords)
{
	position = _coords;
}
