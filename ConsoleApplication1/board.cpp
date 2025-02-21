#include "board.h"

std::ostream& operator<< (std::ostream& out, const Board& board)
{
	int count{};
	for (size_t y{ 0 }; y < board.m_cases.size(); y++)
	{
		for (size_t x{ 0 }; x < board.m_cases.size(); x++)
		{
			out << "#" << count << " " << board.m_cases[y][x] << "\t";
			count++;
		}
		out << "\n";
	}
	return out;
}

Case& Board::getCase(int input)
{
	switch (input)
	{
	case 0: return m_cases[0][0];
	case 1: return m_cases[0][1]; 
	case 2: return m_cases[0][2]; 
	case 3:	return m_cases[1][0]; 
	case 4:	return m_cases[1][1];
	case 5:	return m_cases[1][2];
	case 6:	return m_cases[2][0];
	case 7:	return m_cases[2][1];
	case 8:	return m_cases[2][2];
	default: std::cerr << "Out of bound case";
	}
}

bool Board::hasWon(const char& c) const
{
	for (size_t y{ 0 }; y < m_cases.size(); y++)
	{
		for (size_t x{ 0 }; x < m_cases.size(); x++)
		{

		}
	}
}