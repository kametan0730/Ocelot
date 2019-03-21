#ifndef OCELOT_BOARD_H
#define OCELOT_BOARD_H

#include <iostream>

typedef std::pair<int, int> vec2;

class Board {
public:
	const static int STONE_NULL = 0;
	const static int STONE_WHITE = 1;
	const static int STONE_BLACK = 2;
	int stones[10][10];
	Board();
	void print(bool isAddNum = false);
	bool isReversible(int x, int y, int color);
	void reverse(int x, int y, int color);
	int countWhite();
	int countBlack();
	bool isFull();
private:
	void setStone(int x, int y, int color);
	int getStone(int x, int y);
};

#endif //OCELOT_BOARD_H
