#include "Board.h"
#include "Player.h"
#include <iostream>

int main() {



	Board board = Board();

	Player player1 = Player(&board, Board::STONE_BLACK);
	Player player2 = Player(&board, Board::STONE_WHITE);

	while (true) {

		bool isSucceed1, isSucceed2;

		isSucceed1 = player1.randomAttack(); // ランダムに攻撃
		if (!isSucceed1 and board.isFull()) break;
		board.print(true);

		isSucceed2 = player2.inputAttack(); // 入力から攻撃
		if (!isSucceed2 and board.isFull()) break;
		board.print(true);
	}
	std::cout << "試合が終了しました 黒:" << board.countBlack() << " 白:" << board.countWhite() << std::endl;

	return 0;
}
