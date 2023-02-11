#include "Board.h"
#include "Figures/Knight.h"
#include "Figures/Pawn.h"
#include "Figures/Rook.h"
#include "Figures/King.h"
#include "Figures/Queen.h"
#include "Figures/Bishop.h"
#include "Figures/Piece.h"

using namespace std;

void Board::PlacePiece(Coords pos, char letter)
{
	if (!isInRange(pos))
	{
		return;
	}

	shared_ptr<Piece> wsk;

	switch (letter)
	{
	case 'n':
	{
		Knight knight(pos, BLACK);
		wsk = make_shared<Knight>(knight);

		board[pos.x][pos.y].SetPiece(wsk);
		break;
	}
	case 'N':
	{
		Knight knight(pos, WHITE);
		wsk = make_shared<Knight>(knight);
		board[pos.x][pos.y].SetPiece(wsk);
		break;
	}
	case 'p':
	{
		Pawn pawn(pos, BLACK);
		wsk = make_shared<Pawn>(pawn);
		board[pos.x][pos.y].SetPiece(wsk);
		break;
	}
	case 'P':
	{
		Pawn pawn(pos, WHITE);
		wsk = make_shared<Pawn>(pawn);
		board[pos.x][pos.y].SetPiece(wsk);
		break;
	}
	case 'b':
	{
		Bishop bishop(pos, BLACK);
		wsk = make_shared<Bishop>(bishop);
		board[pos.x][pos.y].SetPiece(wsk);
		break;
	}
	case 'B':
	{
		Bishop bishop(pos, WHITE);
		wsk = make_shared<Bishop>(bishop);
		board[pos.x][pos.y].SetPiece(wsk);
		break;
	}
	case 'r':
	{
		Rook rook(pos, BLACK);
		wsk = make_shared<Rook>(rook);
		board[pos.x][pos.y].SetPiece(wsk);
		break;
	}
	case 'R':
	{
		Rook rook(pos, WHITE);
		wsk = make_shared<Rook>(rook);
		board[pos.x][pos.y].SetPiece(wsk);
		break;
	}
	case 'q':
	{
		Queen queen(pos, BLACK);
		wsk = make_shared<Queen>(queen);
		board[pos.x][pos.y].SetPiece(wsk);
		break;
	}
	case 'Q':
	{
		Queen queen(pos, WHITE);
		wsk = make_shared<Queen>(queen);
		board[pos.x][pos.y].SetPiece(wsk);
		break;
	}
	case 'k':
	{
		King king(pos, BLACK);
		wsk = make_shared<King>(king);
		board[pos.x][pos.y].SetPiece(wsk);
		break;
	}
	case 'K':
	{
		King king(pos, WHITE);
		wsk = make_shared<King>(king);
		board[pos.x][pos.y].SetPiece(wsk);
		break;
	}

	default:
		break;
	}
}

vector<vector<Coords>> Board::ValidMoves(Coords pos)
{
	if (DoesExist(pos))
	{
		return board[pos.x][pos.y].pPiece->ValidMoves();
	}
	
}

void Board::MovePiece(Coords from, Coords to)
{
	board[from.x][from.y].MovePiece(board[to.x][to.y]);
	board[to.x][to.y].pPiece->SetCoords(to);
	board[to.x][to.y].pPiece->Moved();
}

void Board::SimulatedMovePiece(Coords from, Coords to)
{
	board[from.x][from.y].MovePiece(board[to.x][to.y]);
	board[to.x][to.y].pPiece->Moved();
}

void Board::SetStartingPosition(string FEN)
{
	int x = 0;
	int y = 7;
	for (auto letter : FEN)
	{
		if (letter >= 48 && letter <= 57)
		{
			for (size_t i = 0; i < (letter - 48); i++)
			{
				x += 1;
			}
			continue;
		}
		if (letter == '/')
		{
			y -= 1;
			x = 0;
			continue;
		}
		PlacePiece({ x, y }, letter);
		x += 1;
	}
}

bool Board::isEnemy(Coords pos, bool onMoveColor)
{
	if (DoesExist(pos))
	{
		if (GetColor(pos) != onMoveColor)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Board::isFriendly(Coords pos, bool onMoveColor)
{
	if (DoesExist(pos))
	{
		if (GetColor(pos) == onMoveColor)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}


bool Board::isEnemyKing(Coords pos, bool onMoveColor)
{
	if (isEnemy(pos, onMoveColor))
	{
		if (GetName(pos) == "Krol")
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Board::isEnemyKingInCircle(Coords pos, bool color)
{
	if (isInRange({ pos.x - 1, pos.y }))
	{
		if (isEnemyKing({ pos.x - 1, pos.y }, color))
		{
			return true;
		}
	}
	if (isInRange({ pos.x - 1, pos.y + 1 }))
	{
		if (isEnemyKing({ pos.x - 1, pos.y + 1 }, color))
		{
			return true;
		}
	}

	if (isInRange({ pos.x , pos.y + 1 }))
	{
		if (isEnemyKing({ pos.x , pos.y + 1 }, color))
		{
			return true;
		}
	}

	if (isInRange({ pos.x + 1 , pos.y + 1 }))
	{
		if (isEnemyKing({ pos.x + 1 , pos.y + 1 }, color))
		{
			return true;
		}
	}

	if (isInRange({ pos.x + 1 , pos.y }))
	{
		if (isEnemyKing({ pos.x + 1 , pos.y }, color))
		{
			return true;
		}
	}

	if (isInRange({ pos.x + 1 , pos.y - 1 }))
	{
		if (isEnemyKing({ pos.x + 1 , pos.y - 1 }, color))
		{
			return true;
		}
	}

	if (isInRange({ pos.x , pos.y - 1 }))
	{
		if (isEnemyKing({ pos.x , pos.y - 1 }, color))
		{
			return true;
		}
	}

	if (isInRange({ pos.x - 1 , pos.y - 1 }))
	{
		if (isEnemyKing({ pos.x - 1 , pos.y - 1 }, color))
		{
			return true;
		}
	}

	return false;
}

vector<Coords> Board::getCoordsOfColor(bool color)
{
	vector<Coords> temp;
	for (int j = 7; j >= 0; j--)
	{
		for (int i = 0; i < 8; i++)
		{
			if (board[i][j].DoesExist())
			{
				if (board[i][j].pPiece->GetColor() == color)
				{
					temp.push_back({ i,j });
				}
			}

		}

	}
	return temp;
}

bool Board::DoesExist(Coords pos)
{
	return board[pos.x][pos.y].DoesExist();
}

bool Board::HaveMoved(Coords pos)
{
	return board[pos.x][pos.y].pPiece->HaveMoved();
}

bool Board::GetColor(Coords pos)
{
	return board[pos.x][pos.y].pPiece->GetColor();
}

string Board::GetName(Coords pos)
{
	return board[pos.x][pos.y].pPiece->GetName();
}

void Board::Print()
{
	for (int j = 7; j >= 0; j--)
	{
		//wypisanie bocznego indeksu
		cout << j + 1 << " ";
		//wypisanie figur
		for (int i = 0; i < 8; i++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	//wypisanie dolnego indeksu
	cout << "   ";
	for (int i = 0; i < 8; i++)
	{
		cout << (char)(i + 65) << "  ";
	}
	cout << endl;
}

ostream& operator<<(ostream& out, const Board& _obj)
{
	for (int j = 7; j >= 0; j--)
	{
		//wypisanie bocznego indeksu
		out << j + 1 << " ";
		//wypisanie figur
		for (int i = 0; i < 8; i++)
		{
			out << _obj.board[i][j];
		}
		out << endl;
	}
	//wypisanie dolnego indeksu
	out << "   ";
	for (int i = 0; i < 8; i++)
	{
		out << (char)(i + 65) << "  ";
	}
	out << endl;
	return out;
}
