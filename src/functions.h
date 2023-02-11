#ifndef FUNKCJE
#define FUNKCJE

#define WHITE  0
#define BLACK  1

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Coords
{
	int x;
	int y;
	bool operator==(const Coords&);

};
struct MoveCoords
{
	Coords from;
	Coords to;
	friend std::ostream& operator<<(std::ostream& out, const MoveCoords& _move);

};


bool isInRange(Coords coords);
std::string TransformCoords(Coords pos);
std::string TransformMoveCoords(MoveCoords _move);
Coords TransformStringHelp(std::string pos);
MoveCoords TransformStringMove(std::string pos);
void Parameters(int arg, char* argv[], std::string& input_file, std::string& output);

std::vector<std::string> FileToFEN(std::string FEN);


#endif 