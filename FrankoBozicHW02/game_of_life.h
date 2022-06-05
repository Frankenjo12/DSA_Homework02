#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class game_of_life {
private:
	static const unsigned int COLS = 40;
	static const unsigned int ROWS = 20;
	char _generation[ROWS][COLS];
	char _next_generation[ROWS][COLS];
	bool random_value();
	bool cell_taken(int i, int j);

public:
	game_of_life();
	void next_generation();
	void draw();
};

#endif
