#include "GameManager.h"

using namespace std;
GameManager::GameManager(vector<string> FEN, string& _output)
{
	SetGame(FEN[0]);
	if (FEN[1] == "b")
	{
		colorOnMove = BLACK;
	}
	else
	{
		colorOnMove = WHITE;
	}

	this->output_file = _output;
}


void GameManager::SetGame(string FenPos)
{
	board.SetStartingPosition(FenPos);
}

void GameManager::GenerateUI()
{
	cout << board;
}

void GameManager::SaveToFile(vector<MoveCoords>& listOfMoves)
{
	fstream output;
	int ruch = 0;
	output.open(output_file, ios::out | ios::app);
	if (output.good() == true)
	{
		for (int i = 0; i < listOfMoves.size(); i++)
		{
			if (i % 2 == 0)
			{
				ruch++;
				output << ruch << ". ";
			}
			output << TransformMoveCoords(listOfMoves[i])<<" ";

		}
		output << "\n\n";
		output.close();
	}
}

void GameManager::AskForMove()
{
	bool isValid = false;
	string currentMoveString;
	do
	{
		vector<MoveCoords> notCheckMoves = NotCheckMoves(board, colorOnMove);
		if (notCheckMoves.size() == 0)
		{
			if (colorOnMove)
			{
				for (int i = 0; i < 3; i++)
					cout << "BIALE WYGRALY"<<endl;

				isWhiteCheckMated = true;
				break;
			}
			else
			{
				for (int i = 0; i < 3; i++)
					cout << "CZARNE WYGRALY" << endl;;

				isBlackCheckMated = true;
				break;
			}
		}

		if(isKingInCheck(board,colorOnMove))
		{
			if (colorOnMove)
			{
					cout << "* CZARNY KROL W SZACHU *" << endl;
			}
			else
			{
					cout << "* BIALY KROL W SZACHU *" << endl;
			}
		}


		if (colorOnMove == WHITE)
		{
			cout << "BIALY -> ";
		}
		else
		{
			cout << "CZARNY -> ";
		}
		

		cout << "Wprowadz ruch: ";
		cin >> currentMoveString;
		

		if (currentMoveString.size() == 4)
		{
			//move
			Move move(TransformStringMove(currentMoveString));
			if (move.isOnBoard())
			{
				if (move.DoesExist(board))
				{
					if (move.isYourColor(board, colorOnMove))
					{
						if (move.CompareMove(notCheckMoves))
						{
							move.MakeMove(board);
							listOfMoves.push_back(move.getMoveCoords());					
							isValid = true;
						}
						else
						{
							cout << "Ruch niezgodny z zasadami gry w szachy." << endl;
							continue;
						}
					}
					else
					{
						cout << "Na tym polu stoi figura przeciwnika." << endl;
						continue;
					}
				}
				else
				{
					cout << "Na tym polu nie stoi zadna figura." << endl;
					continue;
				}
			}
			else
			{
				cout << "Niepoprawnie wprowadzony ruch." << endl;
				continue;
			}
		}
		else if (currentMoveString.size() == 2)
		{
			//help
			Move move(TransformStringHelp(currentMoveString));
			if (move.isOnBoard())
			{
				if (move.DoesExist(board))
				{
					if (move.isYourColor(board, colorOnMove))
					{
						vector<MoveCoords> help = move.GetLegalMoves(notCheckMoves);
						cout << "Lista legalnych ruchow tej figury: ";
						if (help.size() == 0)
						{
							cout << " * brak *";
						}
						else
						{
							for (auto& move : move.GetLegalMoves(notCheckMoves))
							{
								cout << move;
							}
						}
						cout << endl;
					}
					else
					{
						cout << "Na tym polu stoi figura przeciwnika." << endl;
						continue;
					}
				}
				else
				{
					cout << "Na tym polu nie stoi zadna figura." << endl;
					continue;
				}
				
				
			}
			else
			{
				cout << "Niepoprawnie wprowadzona pozycja figury." << endl;
			}
			continue;
		}
		else
		{
			cout << "Niepoprawnie wprowadzony ruch." << endl;
			continue;
		}


		SwapColors();
	} while (!isValid);
}

void GameManager::GameLoop()
{
	do
	{
		GenerateUI();
		AskForMove();

		if (isBlackCheckMated||isWhiteCheckMated)
		{
			SaveToFile(listOfMoves);
			break;
		}

	} while (true);
}

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
			if (!isCheckNextNextRound(board, color, MoveCoord.from,MoveCoord.to))
			{
				temp.push_back({ MoveCoord.from, MoveCoord.to });
			}
		}
	}
	return temp;
}


bool GameManager::isKingInCheck(Board& board, bool color)
{
	for (auto& coord:board.getCoordsOfColor(!color))
	{
		Move move(coord);
		if (move.AttackEnemyKing(board) == true)
		{
			return true;
		}
	}
	return false;
}

void GameManager::SwapColors()
{
	colorOnMove = !colorOnMove;
}
