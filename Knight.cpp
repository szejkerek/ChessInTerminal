#include "Knight.h"
using namespace std;

Knight::Knight(Coords pos, bool color) :Piece(pos, color)
{
	name = "Skoczek";
	if (color == WHITE)
	{
		this->symbol = 'N';
	}
	if (color == BLACK)
	{
		this->symbol = 'n';
	}
}

vector<vector<Coords>> Knight::ValidMoves()
{
	vector<vector<Coords>> tempBig;
	vector<Coords> tempSmall;
	
	if (isInRange({position.x - 2, position.y + 1})) //1
	{
		tempSmall.push_back({ position.x - 2, position.y + 1 });
		tempBig.push_back(tempSmall);
		tempSmall.clear();
	}
	if (isInRange({ position.x - 1, position.y + 2 }))//2
	{
		tempSmall.push_back({ position.x - 1, position.y + 2 });
		tempBig.push_back(tempSmall);
		tempSmall.clear();
	}
	if (isInRange({ position.x + 1, position.y + 2 }))//3
	{
		tempSmall.push_back({ position.x + 1, position.y + 2 });
		tempBig.push_back(tempSmall);
		tempSmall.clear();
	}
	if (isInRange({ position.x + 2, position.y + 1 }))//4
	{
		tempSmall.push_back({ position.x + 2, position.y + 1 });
		tempBig.push_back(tempSmall);
		tempSmall.clear();
	}
	if (isInRange({ position.x + 2, position.y - 1 }))//5
	{
		tempSmall.push_back({ position.x + 2, position.y - 1 });
		tempBig.push_back(tempSmall);
		tempSmall.clear();
	}
	if (isInRange({ position.x + 1, position.y - 2 }))//6
	{
		tempSmall.push_back({ position.x + 1, position.y - 2 });
		tempBig.push_back(tempSmall);
		tempSmall.clear();
	}
	if (isInRange({ position.x - 1, position.y - 2 }))//7
	{
		tempSmall.push_back({ position.x - 1, position.y - 2 });
		tempBig.push_back(tempSmall);
		tempSmall.clear();
	}
	if (isInRange({ position.x - 2, position.y - 1 }))//8
	{
		tempSmall.push_back({ position.x - 2, position.y - 1 });
		tempBig.push_back(tempSmall);
		tempSmall.clear();
	}

	return tempBig;
}
