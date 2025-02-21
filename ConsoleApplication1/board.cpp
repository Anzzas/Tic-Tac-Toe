#include "board.h"

std::ostream& operator<< (std::ostream& out, const Board& board)
{
	for (size_t y{ 0 }; y < board.m_cases.size(); y++)
	{
		for (size_t x{ 0 }; x < board.m_cases.size(); x++)
		{
			out << board.m_cases[y][x] << "\t";
		}
		out << "\n";
	}
	return out;
}