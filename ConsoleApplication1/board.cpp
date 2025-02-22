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

bool Board::hasWon(const char& c) const
{

	for (size_t y{ 0 }; y < m_cases.size(); y++)
	{

		for (size_t x{ 0 }; x < m_cases.size(); x++)
		{
			if (m_cases[y][x].getSign() != c)
				continue;

			if (x + 2 < m_cases.size())
			{
				if ((m_cases[y][x] == m_cases[y][x + 1]) && (m_cases[y][x + 1] == m_cases[y][x + 2]))
					return true;
			}
			else if (y + 2 < m_cases.size())
			{
				if ((m_cases[y][x] == m_cases[y + 1][x]) && (m_cases[y + 1][x] == m_cases[y + 2][x]))
					return true;
			}
		}
		if (m_cases[1][1] != '\0') // Checks if middle case is empty to prevent unwanted early win
		{
			// Diagonal win condition check

			if (m_cases[0][0] == m_cases[1][1] && m_cases[1][1] == m_cases[2][2])
				return true;
			if (m_cases[0][2] == m_cases[1][1] && m_cases[1][1] == m_cases[2][0])
				return true;
		}
	}
	return false;
}

bool Board::isCombinationPlayable(const Case& a, const Case& b, const Case& c) const
{
	// Vérifie si la combinaison contient à la fois X et O (donc bloquée)
	bool hasX{ a == 'X' || b == 'X' || c == 'X' };
	bool hasO{ (a == 'O' || b == 'O' || c == 'O') };

	if (hasX && hasO) // Si la combinaison contient à la fois X et O, elle est bloquée
		return false;

	return true; // Sinon, elle est encore jouable
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