#include <vector>
#include "Player.h"

Player::Player(Board* board, int color) {
	this->board = board;
	player_color = color;
}

bool Player::randomAttack() {
	std::vector<vec2> pairs;
	for (int y = 1; y < 9; ++y) {
		for (int x = 1; x < 9; ++x) {
			if(board->isReversible(x, y, player_color)){
				pairs.emplace_back(x, y);
			}
		}
	}
	if(pairs.empty()) return false;
	vec2 pos = pairs[rand()%pairs.size()];
	board->reverse(pos.first, pos.second, player_color);
	return true;
}

bool Player::inputAttack() {
	if(!isReversiblePosExists()) {
		std::cout << (player_color == Board::STONE_WHITE ? "白" : "黒") << "の番ですが置ける場所がありません" << std::endl;
		return false;
	}
	std::cout << (player_color == Board::STONE_WHITE ? "白" : "黒") << "の番です、置く場所を入力してください" << std::endl;
	int x, y;
	std::cin >> x >> y;
	if(1 > x or 8 < x or 1 > y or 8 < y){
		std::cout << "そのマスには置けません" << std::endl;
		return inputAttack();
	}
	if(board->isReversible(x, y, player_color)) {
		board->reverse(x, y, player_color);
	}else{
		std::cout << "そのマスには置けません" << std::endl;
		return inputAttack();
	}
	return true;
}

bool Player::isReversiblePosExists() {
	for (int y = 1; y < 9; ++y) {
		for (int x = 1; x < 9; ++x) {
			if(board->isReversible(x, y, player_color)){
				return true;
			}
		}
	}
	return false;
}