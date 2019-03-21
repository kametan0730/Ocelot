#include <vector>
#include "Board.h"

Board::Board() {
	for (int x = 0; x < 10; ++x) {
		for (int y = 0; y < 10; ++y) {
			stones[x][y] = STONE_NULL;
		}
	}
	setStone(4,4,1);
	setStone(4,5,2);
	setStone(5,4,2);
	setStone(5,5,1);
}

void Board::print(bool isPrintLineNum) {
	if(isPrintLineNum) std::cout << "＼１ ２ ３ 4 ５ ６ 7 ８" << std::endl;
	for (int y = 1; y < 9; ++y) {
		if(isPrintLineNum) std::cout << y << " ";
		for (int x = 1; x < 9; ++x) {
			std::cout << ((stones[x][y] == STONE_NULL) ? "⬜️" : (stones[x][y] == STONE_WHITE) ? "⚪️" : "⚫️");
		}
		std::cout << std::endl;
	}
}

void Board::setStone(int x, int y, int color) {
	stones[x][y] = color;
}

int Board::getStone(int x, int y) {
	return stones[x][y];
}

bool Board::isReversible(int x, int y, int color) {
	if(getStone(x, y) != STONE_NULL) return false;
	int directions[9][2] = {
			{ 0, 1},
			{ 1, 1},
			{ 1, 0},
			{ 1,-1},
			{ 0,-1},
			{-1,-1},
			{-1, 0},
			{-1, 1},
	};
	for (auto &direction : directions) {
		if(getStone(x + direction[0], y + direction[1]) != ((color == STONE_WHITE) ? STONE_BLACK : STONE_WHITE)) continue;
		int loop = 2;
		while(true){
			int reverse_x = x + direction[0]*loop;
			int reverse_y = y + direction[1]*loop;
			int stone = getStone(reverse_x, reverse_y);
			if(stone == STONE_NULL) break;
			if(stone == ((color == STONE_WHITE) ? STONE_WHITE : STONE_BLACK)) return true;
			loop++;
		}
	}
	return false;
}

void Board::reverse(int x, int y, int color) {
	if(getStone(x, y) != STONE_NULL) return;
	setStone(x, y, color);
	int directions[9][2] = {
			{ 0, 1},
			{ 1, 1},
			{ 1, 0},
			{ 1,-1},
			{ 0,-1},
			{-1,-1},
			{-1, 0},
			{-1, 1},
	};
	for (auto &direction : directions) {
		if(getStone(x + direction[0], y + direction[1]) != ((color == STONE_WHITE) ? STONE_BLACK : STONE_WHITE)) continue;
		int loop = 1;
		std::vector<vec2> path;
		while(true){
			int reverse_x = x + direction[0]*loop;
			int reverse_y = y + direction[1]*loop;
			int stone = getStone(reverse_x, reverse_y);
			path.emplace_back(reverse_x, reverse_y);
			if(stone == STONE_NULL) break;
			if(stone == ((color == STONE_WHITE) ? STONE_WHITE : STONE_BLACK)) {
				for (int i = 0; i < path.size(); ++i) {
					setStone(path[i].first, path[i].second, color);
				}
				break;
			}
			loop++;
		}
	}
}


int Board::countWhite() {
	int result = 0;
	for (int y = 1; y < 9; ++y) {
		for (int x = 1; x < 9; ++x) {
			if(stones[x][y] == STONE_WHITE) result++;
		}
	}
	return result;
}
int Board::countBlack() {
	int result = 0;
	for (int y = 1; y < 9; ++y) {
		for (int x = 1; x < 9; ++x) {
			if(stones[x][y] == STONE_BLACK) result++;
		}
	}
	return result;
}

bool Board::isFull() {
	int count = 0;
	for (int y = 1; y < 9; ++y) {
		for (int x = 1; x < 9; ++x) {
			if(stones[x][y] == STONE_NULL) count++;
		}
	}
	return (count == 0);
}
