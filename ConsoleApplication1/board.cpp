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

Point2D<Case, 3>& Board::get_m_cases()
{
	return m_cases;
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

bool Board::hasWon() const
{
	if (m_cases[1][1] != '\0') // Checks if middle case is empty to prevent unwanted early win
	{
		// Diagonal win condition check

		if ((m_cases[0][0] == m_cases[1][1] && m_cases[1][1] == m_cases[2][2]) || (m_cases[0][2] == m_cases[1][1] && m_cases[1][1] == m_cases[2][0]))
			return true;
	}

	for (size_t i{ 0 }; i < m_cases.size(); i++)
	{
			// check row
			if ((m_cases[i][0] != '\0' && m_cases[i][0] == m_cases[i][1]) && (m_cases[i][1] == m_cases[i][2]))
				return true;

			// check column
			if (m_cases[0][i] != '\0' && (m_cases[0][i] == m_cases[1][i]) && (m_cases[1][i] == m_cases[2][i]))
				return true;
	}
	return false; // No win condition has been met
}

bool Board::isCombinationPlayable(const Case& a, const Case& b, const Case& c) const
{
	return a.isEmpty() || b.isEmpty() || c.isEmpty() ? true : false;
}

bool Board::isCombinationWinnable(const Case& a, const Case& b, const Case& c) const
{
	int count{};
	if (a == 'O')
		++count;
	if (b == 'O')
		++count;
	if (c == 'O')
		++count;

	if (count >= 2) // If the row/column contains at least 2 'O', then it's winnable for CPU
		return true;

	return false;
}

bool Board::isOpponentWinning(const Case& a, const Case& b, const Case& c) const
{
	int count{};
	if (a == 'X')
		++count;
	if (b == 'X')
		++count;
	if (c == 'X')
		++count;

	if (count >= 2) // If the row/column contains at least 2 'X', then it's winnable for human player
		return true;

	return false;
}

bool Board::isDraw() const
{
	for (size_t i{ 0 }; i < m_cases.size(); i++)
	{
		//check rows
		if (isCombinationPlayable(m_cases[i][0], m_cases[i][1], m_cases[i][2]))
			return false;

		// check columns
		else if (isCombinationPlayable(m_cases[0][i], m_cases[1][i], m_cases[2][i]))
			return false;
	}

	if (isCombinationPlayable(m_cases[0][0], m_cases[1][1], m_cases[2][2]))
				return false;

	else if (isCombinationPlayable(m_cases[0][2], m_cases[1][1], m_cases[2][0]))
				return false;

	std::cout << "Draw !\n";
	return true;
}