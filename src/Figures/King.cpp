#include "King.h"

using namespace std;

King::King(Coords pos, bool color) :Piece(pos, color)
{
	name = "Krol";
	if (color == WHITE)
	{
		this->symbol = 'K';
	}
	if (color == BLACK)
	{
		this->symbol = 'k';
	}
}

vector<vector<Coords>> King::ValidMoves()
{
	vector<vector<Coords>> tempBig;
	vector<Coords> tempSmall;

	if (isInRange({ position.x - 1, position.y })) //1
	{
		tempSmall.push_back({ position.x - 1, position.y });
		tempBig.push_back(tempSmall);
		tempSmall.clear();
	}
	if (isInRange({ position.x - 1, position.y + 1}))//2
	{
		tempSmall.push_back({ position.x - 1, position.y + 1 });
		tempBig.push_back(tempSmall);
		tempSmall.clear();
	}
	if (isInRange({ position.x, position.y + 1 }))//3
	{
		tempSmall.push_back({ position.x, position.y + 1 });
		tempBig.push_back(tempSmall);
		tempSmall.clear();
	}
	if (isInRange({ position.x + 1, position.y + 1 }))//4
	{
		tempSmall.push_back({ position.x + 1, position.y + 1 });
		tempBig.push_back(tempSmall);
		tempSmall.clear();
	}
	if (isInRange({ position.x + 1, position.y }))//5
	{
		tempSmall.push_back({ position.x + 1, position.y });
		tempBig.push_back(tempSmall);
		tempSmall.clear();
	}
	if (isInRange({ position.x + 1, position.y - 1 }))//6
	{
		tempSmall.push_back({ position.x + 1, position.y - 1 });
		tempBig.push_back(tempSmall);
		tempSmall.clear();
	}
	if (isInRange({ position.x, position.y - 1 }))//7
	{
		tempSmall.push_back({ position.x, position.y - 1 });
		tempBig.push_back(tempSmall);
		tempSmall.clear();
	}
	if (isInRange({ position.x - 1, position.y - 1 }))//8
	{
		tempSmall.push_back({ position.x - 1, position.y - 1 });
		tempBig.push_back(tempSmall);
		tempSmall.clear();
	}

	return tempBig;
}
