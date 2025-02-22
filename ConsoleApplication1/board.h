#ifndef BOARD_H
#define BOARD_H
#include <array>
#include "case.h"

template<typename T, size_t size>
using Point2D = std::array<std::array<T, size>, size>;

class Board
{
public:

	Board() = default;

	friend std::ostream& operator<< (std::ostream& out, const Board& board);
	Case& getCase(int input);
	Point2D<Case, 3>& get_m_cases();
	bool hasWon(const char& c) const;
	bool isDraw() const;
	bool isCombinationPlayable(const Case& a, const Case& b, const Case& c) const;

private:

	Point2D<Case, 3> m_cases;

};
#endif