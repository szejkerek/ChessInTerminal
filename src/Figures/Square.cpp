#include "Square.h"

using namespace std;

void Square::SetPiece(shared_ptr<Piece> newPiece)
{
	pPiece = newPiece;
}

Square::Square():pPiece(nullptr)
{
}

void Square::RemovePiece()
{
	this->pPiece = nullptr;
}

bool Square::DoesExist()
{
	if (pPiece == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Square::MovePiece(Square& to)
{
	to.pPiece = this->pPiece;
	this->RemovePiece();
}

ostream& operator<<(ostream& out, const Square& _square)
{
	if (_square.pPiece == nullptr)
	{
		out << "[" << " " << "]";
	}
	else
	{
		out << "[" << _square.pPiece->GetSymbol() << "]";
	}

	return out;
}
