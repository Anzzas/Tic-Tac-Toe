#ifndef CPU_H
#define CPU_H
#include "player.h"
#include "board.h"


class Cpu : public Player
{
public:

	Cpu(char sign)
		: Player{ sign }
	{
	}

	Case& playMove(Board& board);
};

#endif