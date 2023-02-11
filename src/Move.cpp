#include "Move.h"

using namespace std;

Move::Move(MoveCoords _move) :move_coords(_move), isMove(1), help_coords({-1,-1}) { }
Move::Move(Coords _help) : help_coords(_help), isMove(0), move_coords({ {-1,-1},{-1,-1} }) { }

bool Move::DoesExist(Board& board)
{
	if (isMove)
	{
		return board.DoesExist(move_coords.from);
	}
	else
	{
		return board.DoesExist(help_coords);
	}
}


void Move::GeneratePseudoLegal(Board& board,bool onlyKingAttack)
{
	vector<vector<Coords>> valid_moves;
	Coords current_position;
	int pawnMultiplier = 1;
	bool currentColor;

	if (isMove)
	{
		current_position = move_coords.from;
	}
	else
	{
		current_position = help_coords;	
	}

	valid_moves = board.ValidMoves(current_position);

	if (board.GetColor(current_position) == BLACK)
	{
		pawnMultiplier = -1;
		currentColor = BLACK;		
	}
	else
	{
		currentColor = WHITE;
	}

	

	if (board.GetName(current_position) == "Pion")
	{
		if (isInRange({ current_position.x - 1,current_position.y + (1 * pawnMultiplier) })) //lewo
		{
			if (board.isEnemy({ current_position.x - 1,current_position.y + (1 * pawnMultiplier) }, currentColor))
			{
				if (!board.isEnemyKing({ current_position.x - 1,current_position.y + (1 * pawnMultiplier) }, currentColor))
				{
					if (!onlyKingAttack)
					{
						pseudoLegalMoves.push_back({ current_position,{ current_position.x - 1,current_position.y + (1 * pawnMultiplier) } });
					}		
				}
				else
				{
					enemyKingUnderAttack = true;
				}
			}
		}
		if (isInRange({ current_position.x +1, current_position.y + (1 * pawnMultiplier) })) //prawo
		{
			if (board.isEnemy({ current_position.x + 1, current_position.y + (1 * pawnMultiplier) }, currentColor))
			{
				if (!board.isEnemyKing({ current_position.x + 1, current_position.y + (1 * pawnMultiplier) }, currentColor))
				{
					if (!onlyKingAttack)
					{
						pseudoLegalMoves.push_back({ current_position,{ current_position.x + 1, current_position.y + (1 * pawnMultiplier) } });
					}		
				}
				else
				{
					enemyKingUnderAttack = true;
				}
			}
		}
		if (isInRange({ current_position.x ,current_position.y + (1 * pawnMultiplier) })) //góra
		{
			if (!board.DoesExist({ current_position.x ,current_position.y + (1 * pawnMultiplier) }))
			{
				if (current_position.y != 1 && board.GetColor(current_position) == WHITE)
				{
					if (!onlyKingAttack)
					{
						pseudoLegalMoves.push_back({ current_position,{ current_position.x, current_position.y + (1 * pawnMultiplier) } });
					}		
				}
				else if (current_position.y != 6 && board.GetColor(current_position) == BLACK)
				{
					if (!onlyKingAttack)
					{
						pseudoLegalMoves.push_back({ current_position,{ current_position.x, current_position.y + (1 * pawnMultiplier) } });
					}
						
				}
				else
				{
					if (!board.DoesExist({ current_position.x ,current_position.y + (2 * pawnMultiplier) }))
					{
						if (!onlyKingAttack)
						{
							pseudoLegalMoves.push_back({ current_position,{ current_position.x, current_position.y + (1 * pawnMultiplier) } });
							pseudoLegalMoves.push_back({ current_position,{ current_position.x, current_position.y + (2 * pawnMultiplier) } });
						}						
					}
				}
			}
		}

	}
	else if(board.GetName(current_position) == "Krol")
	{
		for (auto& vector: valid_moves)
		{
			for (auto& coord:vector)
			{
				if (!board.isFriendly(coord, board.GetColor(current_position)))
				{
					if (!board.isEnemyKingInCircle(coord, board.GetColor(current_position)))
					{
						if (!onlyKingAttack)
						{
							pseudoLegalMoves.push_back({ current_position, coord});
						}
					}
				}
			}
		}
	}
	else 
	{
		for (auto& vector : valid_moves)
		{
			for (auto& coord : vector)
			{
				if (!board.isFriendly(coord, board.GetColor(current_position)))
				{
					if (!board.isEnemyKing(coord, board.GetColor(current_position)))
					{
						if (!onlyKingAttack)
						{
							pseudoLegalMoves.push_back({ current_position, coord });
						}

						if (board.isEnemy(coord, board.GetColor(current_position)))
						{
							break;
						}
					}
					else
					{
						enemyKingUnderAttack = true;
					}
				}
				else
				{
					break;
				}
			}
		}
	}

}


bool Move::isYourColor(Board& board, bool onMoveColor)
{
	if (isMove)
	{		
		if (board.GetColor(move_coords.from) == onMoveColor)
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
		if (board.GetColor(help_coords) == onMoveColor)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Move::isOnBoard()
{
	if (isMove)
	{//move
		if (isInRange(move_coords.from) && isInRange(move_coords.to))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{//help
		if (isInRange(help_coords))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void Move::MakeMove(Board& board)
{
	board.MovePiece(move_coords.from, move_coords.to);
}

MoveCoords Move::getMoveCoords()
{
	return this->move_coords;
}

vector<MoveCoords> Move::getPseudoLegalMoves(Board& board)
{
	GeneratePseudoLegal(board, false);
	return pseudoLegalMoves;
}

bool Move::AttackEnemyKing(Board& board)
{
	GeneratePseudoLegal(board, true);
	return enemyKingUnderAttack;
}

bool Move::CompareMove(vector<MoveCoords>& allLegalMovesInPosition)
{
	for (auto& sim_move:allLegalMovesInPosition)
	{
		if (sim_move.from == this->move_coords.from && sim_move.to == this->move_coords.to)
		{
			return true;
		}
	}
	return false;
}

vector<MoveCoords> Move::GetLegalMoves(vector<MoveCoords>& allLegalMovesInPosition) 
{
	vector<MoveCoords> temp;
	for (auto& sim_moves: allLegalMovesInPosition)
	{
		if (help_coords == sim_moves.from)
		{
			temp.push_back({ help_coords,sim_moves.to });
		}
	}
	return temp;
}