#ifndef MOVE
#define MOVE
#include "functions.h"
#include "Board.h"

class Move
{
private:
	//private fields
	MoveCoords move_coords;
	Coords help_coords;
	bool isMove;
	bool enemyKingUnderAttack = false;

	//private methods
	std::vector<MoveCoords> pseudoLegalMoves;
	void GeneratePseudoLegal(Board& board, bool onlyKingAttack);

public:
	//constructors
	Move(MoveCoords _move);
	Move(Coords _help);

	//public methods
	bool isOnBoard();
	MoveCoords getMoveCoords();
	void MakeMove(Board& board);
	bool DoesExist(Board& board);
	bool AttackEnemyKing(Board& board);
	bool isYourColor(Board& board, bool onMoveColor);
	std::vector<MoveCoords> getPseudoLegalMoves(Board& board);
	bool CompareMove(std::vector<MoveCoords>& allLegalMovesInPosition);
	std::vector<MoveCoords> GetLegalMoves(std::vector<MoveCoords>& allLegalMovesInPosition);
};

#endif