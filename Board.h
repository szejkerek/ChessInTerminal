#ifndef BOARD
#define BOARD

#include "Square.h"
#include "functions.h"
/**
 * @brief Klasa reprezentująca szachownice
 * 
 */
class Board
{
private:
	//private field
	/**
	 * @brief Tablica obiektów klasy Square reprezentująca szachownice
	 * 
	 */
	Square board[8][8];

public:
	
	//Setters
	/**
	 * @brief Funkcja ustawiająca pozycje startową
	 * 
	 * @param FEN linia tekstu przedstawiająca pozycję startową w notacji FEN
	 */
	void SetStartingPosition(std::string FEN);

	//Getters
	bool GetColor(Coords pos);
	bool HaveMoved(Coords pos);
	std::string GetName(Coords pos);
	bool DoesExist(Coords pos);
	bool isEnemy(Coords pos, bool color);
	bool isFriendly(Coords pos, bool color);
	bool isEnemyKing(Coords pos, bool color);
	std::vector<Coords> getCoordsOfColor(bool color);
	bool isEnemyKingInCircle(Coords pos, bool color);

	//Methods
	void Print();
	void MovePiece(Coords from, Coords to);	
	void PlacePiece(Coords pos, char letter);
	std::vector<std::vector<Coords>> ValidMoves(Coords pos);
	void SimulatedMovePiece(Coords from, Coords to);

	//operators
	friend std::ostream& operator<<(std::ostream& out, const Board& _obj);

};
#endif

