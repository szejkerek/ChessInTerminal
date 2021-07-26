#include "functions.h"

using namespace std;

ostream& operator<<(ostream& out, const MoveCoords& _move)
{
	out << "[" << TransformCoords(_move.from) << TransformCoords(_move.to) << "] ";
	return out;
}

bool isInRange(Coords coords)
{
	if (coords.x >= 0 && coords.x <= 7 && coords.y >= 0 && coords.y <= 7)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string TransformCoords(Coords pos)
{
	string text = "  ";
	text[0] = (char)(pos.x + 65);
	text[1] = (char)(pos.y + 49);

	return text;
}

string TransformMoveCoords(MoveCoords _move)
{
	string temp = "";
	 
	temp += TransformCoords(_move.from);
	temp += TransformCoords(_move.to);
	
	temp[0] += 32;
	temp[2] += 32;

	return temp;
}

Coords TransformStringHelp(string pos)
{
	Coords temp{-1,-1};
	if (pos[0] > 64 && pos[0] < 73)
	{
		temp.x = (int)(pos[0] - 65);
	}
	else if (pos[0] > 96 && pos[0] < 105)
	{
		temp.x = (int)(pos[0] - 97);
	}


	if (pos[1] > 48 && pos[1] < 57)
	{
		temp.y = (int)(pos[1] - 49);
	}
	return temp;
}

MoveCoords TransformStringMove(string move)
{
	MoveCoords moveCoords{ {-1,-1},{-1,-1} };

	/// /////////////// FROM

	if (move[0] > 64 && move[0] < 73)
	{
		moveCoords.from.x = (int)(move[0] - 65);
	}
	else if (move[0] > 96 && move[0] < 105)
	{
		moveCoords.from.x = (int)(move[0] - 97);
	}

	if (move[1] > 48 && move[1] < 57)
	{
		moveCoords.from.y = (int)(move[1] - 49);
	}


	/// /////////////// TO

	if (move[2] > 64 && move[2] < 73)
	{
		moveCoords.to.x = (int)(move[2] - 65);
	}
	else if (move[2] > 96 && move[2] < 105)
	{
		moveCoords.to.x = (int)(move[2] - 97);
	}

	if (move[3] > 48 && move[3] < 57)
	{
		moveCoords.to.y = (int)(move[3] - 49);
	}

	return moveCoords;
}

void Parameters(int arg, char* argv[], string& input_file, string& output_file)
{
	bool i_onceUsed = false;
	bool o_onceUsed = false;

	if (arg == 3)
	{
		for (int i = 1; i < arg; i++)
		{
			if (argv[i][0] == '-')
			{

				switch (argv[i][1])
				{
					case 'i':
					{
						if (!i_onceUsed)
						{
							//przypisanie nazwy pliku_wejsciowego 
							input_file = argv[i + 1];
							i_onceUsed = true;
						}
						break;
					}
					default:
					{
						return;
					}

				}

				i++; //przesuniêcie pêtli for na kolejne wywo³anie parametru
			}

			
		}
	}
	else if (arg == 5)
	{
		for (int i = 1; i < arg; i++)
		{
			if (argv[i][0] == '-')
			{

				switch (argv[i][1])
				{
					case 'i':
					{
						if (!i_onceUsed)
						{
							//przypisanie nazwy pliku_wejsciowego 
							input_file = argv[i + 1];
							i_onceUsed = true;
						}
						break;
					}
					case 'o':
					{
						if (!o_onceUsed)
						{
							//przypisanie nazwy pliku_wejsciowego 
							output_file = argv[i + 1];
							o_onceUsed = true;
						}
						break;
					}
					default:
					{
						return;
					}

				}

				i++; //przesuniêcie pêtli for na kolejne wywo³anie parametru
			}


		}
	}

	return;
}

vector<string> FileToFEN(string file_name)
{
	ifstream file(file_name);
	string full_line;
	vector<string> FEN;

	if (file)
	{
		getline(file, full_line);
		size_t pos = full_line.find(' ');
		string element = full_line.substr(0, pos);
		string rest = full_line.substr(pos+1, full_line.length());
		FEN.push_back(element);

		for (size_t i = 0; i < 5; i++)
		{
			pos = rest.find(' ');
			element = rest.substr(0, pos);
			FEN.push_back(element);
			rest = rest.substr(pos + 1, full_line.length());
		}

		file.close();
	}


	return FEN;
}


bool Coords::operator==(const Coords& _obj)
{
	if (x == _obj.x && y == _obj.y)
	{
		return true;
	}
	return false;
}
