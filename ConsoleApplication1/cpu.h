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

private:

	Case* findWinningMove(const Board& board, Point2D<Case, 3>& m_cases);
	Case* findDefensiveMove(const Board& board, Point2D<Case, 3>& m_cases);
	Case* findAggressiveMove(const Board& board, Point2D<Case, 3>& m_cases);
	Case* findNormalMove(const Board& board, Point2D<Case, 3>& m_cases);
};
#endif