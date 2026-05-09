### Chess-console-game
## Bartłomiej Gordon INF sem. III
`⭐ Do not forget to give a star on GitHub!`

Program lets you play a local game of Chess. It has features such as loading game in FEN notation and saving your game in PGN notation. It lets you replay your games on sites like Chess.com

Example of the user interface:

![x](https://user-images.githubusercontent.com/69083596/218280705-6060cfc2-75c2-4fdc-b99a-7ae9e5914ba3.png)

## Code Highlights

### Dual-Mode Pseudo-Legal Move Generation

```cpp
// src/Move.cpp
void Move::GeneratePseudoLegal(Board& board, bool onlyKingAttack)
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

	// ... (pawn and king handling omitted for brevity)

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
```

`GeneratePseudoLegal` serves two distinct roles controlled by the `onlyKingAttack` flag. In normal mode it populates `pseudoLegalMoves` for move validation; in king-attack mode it skips that collection and only sets `enemyKingUnderAttack`, avoiding unnecessary work during check detection. Each piece's `ValidMoves()` returns a `vector<vector<Coords>>` where each inner vector is a directional ray. The generator iterates rays and breaks on the first blocking square, correctly modelling how sliding pieces (rooks, bishops, queens) are obstructed — without any extra per-piece branching logic at this level.

### Legal Move Filtering via Board Simulation

```cpp
// src/GameManager.cpp
bool GameManager::isCheckNextNextRound(Board boardSim, bool color, Coords _from, Coords _to)
{
	boardSim.SimulatedMovePiece(_from, _to);
	return isKingInCheck(boardSim, color);
}

vector<MoveCoords> GameManager::NotCheckMoves(Board& board, bool color)
{
	vector<MoveCoords> temp;
	for (auto& coordOfPiece : board.getCoordsOfColor(color))
	{
		Move movetemp(coordOfPiece);

		vector<MoveCoords> allLegalMoves = movetemp.getPseudoLegalMoves(board);

		for (auto& MoveCoord : allLegalMoves)
		{
			if (!isCheckNextNextRound(board, color, MoveCoord.from, MoveCoord.to))
			{
				temp.push_back({ MoveCoord.from, MoveCoord.to });
			}
		}
	}
	return temp;
}
```

This pair implements the standard two-phase chess move legality check. `NotCheckMoves` first gathers pseudo-legal moves for every friendly piece, then filters each candidate by simulating it on a board copy — `Board` is passed by value to `isCheckNextNextRound`, giving a natural deep copy through the value semantics of the `Square[8][8]` member array and `shared_ptr<Piece>` reference counting. If the friendly king remains in check after the simulated move, the candidate is dropped. The result is the complete set of legal moves for the current player, which is also used for checkmate detection when the returned vector is empty.

