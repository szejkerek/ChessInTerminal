#include "Queen.h"
using namespace std;
Queen::Queen(Coords pos, bool color) :Piece(pos, color)
{
	name = "Hetman";
	if (color == WHITE)
	{
		this->symbol = 'Q';
	}
	if (color == BLACK)
	{
		this->symbol = 'q';
	}
}

vector<vector<Coords>> Queen::ValidMoves()
{
	vector<vector<Coords>> tempBig;
	vector<Coords> tempSmall;
	for (int i = 1; i < 8; i++) //1R
	{
		if (isInRange({position.x - i, position.y}))
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

	for (int i = 1; i < 8; i++) //1B
	{
		if (isInRange({ position.x - i, position.y + i }))
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

	for (int i = 1; i < 8; i++) //2R
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

	for (int i = 1; i < 8; i++) //2B
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


	for (int i = 1; i < 8; i++) //3R
	{
		if (isInRange({ position.x + i, position.y}))
		{
			tempSmall.push_back({ position.x + i, position.y});
		}
		else
		{
			break;
		}
	}
	tempBig.push_back(tempSmall);
	tempSmall.clear();



	for (int i = 1; i < 8; i++) //3B
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

	for (int i = 1; i < 8; i++) //4R
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




	for (int i = 1; i < 8; i++) //4B
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
