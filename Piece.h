#ifndef PIECE
#define PIECE

#include"functions.h"

class Piece
{
private:

	//private fields
	bool haveMoved = false;

protected:

	//protected fields
	Coords position;
	bool color;
	char symbol = '?';
	std::string name = "?";

public:

	//Constructor
	Piece(Coords coords, bool color);

	//Getters
	char GetSymbol();
	std::string GetName();
	Coords GetCoords();
	bool GetColor();
	bool HaveMoved();

	//Setters
	void Moved();
	void SetCoords(Coords coords);

	//virtual method
	std::vector<std::vector<Coords>> virtual ValidMoves() = 0;

};

#endif