#include "Bishop.h"
using namespace std;
Bishop::Bishop(Coords pos, bool color) :Piece(pos, color)
{
	name = "Goniec";
	if (color == WHITE)
	{
		this->symbol = 'B';
	}
	if (color == BLACK)
	{
		this->symbol = 'b';
	}
}

vector<vector<Coords>> Bishop::ValidMoves()
{
	vector<vector<Coords>> tempBig;
	vector<Coords> tempSmall;

	for (int i = 1; i < 8; i++) //1
	{
		if (isInRange({position.x - i, position.y + i}))
		{
			tempSmall.push_back({ position.x - i, position.y + i });
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
		if (isInRange({ position.x + i, position.y + i }))
		{
			tempSmall.push_back({ position.x + i, position.y + i });
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
		if (isInRange({ position.x + i, position.y - i }))
		{
			tempSmall.push_back({ position.x + i, position.y - i });
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
		if (isInRange({ position.x - i, position.y - i }))
		{
			tempSmall.push_back({ position.x - i, position.y - i });
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
