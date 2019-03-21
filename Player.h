#ifndef OCELOT_PLAYER_H
#define OCELOT_PLAYER_H

#include "Board.h"

class Player {
public:
	int player_color;
	Board* board;
	Player(Board* board, int color);
	bool randomAttack();
	bool inputAttack();

private:
	bool isReversiblePosExists();
};

#endif //OCELOT_PLAYER_H
