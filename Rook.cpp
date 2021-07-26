#include "Rook.h"
using namespace std;

Rook::Rook(Coords pos, bool color) :Piece(pos, color)
{
	name = "Wieza";
	if (color == WHITE)
	{
		this->symbol = 'R';
	}
	if (color == BLACK)
	{
		this->symbol = 'r';
	}
}

vector<vector<Coords>> Rook::ValidMoves()
{
	vector<vector<Coords>> tempBig;
	vector<Coords> tempSmall;
	for (int i = 1; i < 8; i++) //1
	{
		if (isInRange({ position.x - i, position.y }))
		{
			tempSmall.push_back({ position.x - i, position.y });
		}
		else
		{
			break;
		}
	}
	tempBig.push_back(tempSmall);
	tempSmall.clear();

	for (int i = 1; i < 8; i++) //2
	{
		if (isInRange({ position.x, position.y + i }))
		{
			tempSmall.push_back({ position.x, position.y + i });
		}
		else
		{
			break;
		}
	}
	tempBig.push_back(tempSmall);
	tempSmall.clear();

	for (int i = 1; i < 8; i++) //3
	{
		if (isInRange({ position.x + i, position.y }))
		{
			tempSmall.push_back({ position.x + i, position.y });
		}
		else
		{
			break;
		}
	}
	tempBig.push_back(tempSmall);
	tempSmall.clear();

	for (int i = 1; i < 8; i++) //4
	{
		if (isInRange({ position.x, position.y - i }))
		{
			tempSmall.push_back({ position.x, position.y - i });
		}
		else
		{
			break;
		}
	}
	tempBig.push_back(tempSmall);
	tempSmall.clear();


	return tempBig;
}
