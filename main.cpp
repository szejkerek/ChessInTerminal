#include <iostream>
#include "GameManager.h"
#include "functions.h"

using namespace std;

int main(int argc, char* argv[])
{
	//Default file_names
	string input_file = "default.txt";
	string output_file = "output.txt";

	//Starting Parameters
	Parameters(argc, argv, input_file, output_file);

	//GameLogic
	GameManager game(FileToFEN(input_file), output_file);
	game.GameLoop();

}