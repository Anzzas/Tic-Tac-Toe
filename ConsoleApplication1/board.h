#ifndef BOARD_H
#define BOARD_H
#include <array>
#include "case.h"

class Board
{
public:

	Board() = default;

	friend std::ostream& operator<< (std::ostream& out, const Board& board);

private:

	std::array<std::array<Case, 3>, 3> m_cases;

};
#endif