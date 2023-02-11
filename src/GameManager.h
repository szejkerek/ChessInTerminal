#ifndef GAME
#define GAME
#include "Board.h"
#include "functions.h"
#include "Move.h"
class GameManager
{
private:

	//private fields
	Board board;
	std::vector<MoveCoords> listOfMoves;
	std::string output_file;

	bool colorOnMove;

	bool isWhiteCheckMated = false;
	bool isBlackCheckMated = false;
	
	//private methods
	void SwapColors();
	void SetGame(std::string FenPos);
	bool isKingInCheck(Board& board, bool color);
	std::vector<MoveCoords> NotCheckMoves(Board& board, bool color);
	bool isCheckNextNextRound(Board boardSim, bool color, Coords form, Coords to);

public:
	//constructor
	GameManager(std::vector<std::string> FEN, std::string& output);

	//public methods
	void GameLoop();
	void AskForMove();
	void GenerateUI();
	void SaveToFile(std::vector<MoveCoords>& listOfMoves);
};
#endif
