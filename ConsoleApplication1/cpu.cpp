#include "cpu.h"

Case* Cpu::findWinningMove(const Board& board, Point2D<Case, 3>& m_cases)
{
	// Check diagonal winning move
	if (board.isCombinationWinnable(m_cases[0][0], m_cases[1][1], m_cases[2][2])) // check diagonal 1
		return findEmptyCases(m_cases[0][0], m_cases[1][1], m_cases[2][2]);

	else if (board.isCombinationWinnable(m_cases[0][2], m_cases[1][1], m_cases[2][0])) // check diagonal 2
		return findEmptyCases(m_cases[0][2], m_cases[1][1], m_cases[2][0]);

	// loops to search any instant winning moves
	for (size_t i{ 0 }; i < m_cases.size(); i++)
	{
		// For columns (y)
		if (board.isCombinationPlayable(m_cases[0][i], m_cases[1][i], m_cases[2][i]))
		{
			if (board.isCombinationWinnable(m_cases[0][i], m_cases[1][i], m_cases[2][i]))
				return findEmptyCases(m_cases[0][i], m_cases[1][i], m_cases[2][i]);
		}

		// For rows (x)
		if (board.isCombinationPlayable(m_cases[i][0], m_cases[i][1], m_cases[i][2]))
		{
			if (board.isCombinationWinnable(m_cases[i][0], m_cases[i][1], m_cases[i][2]))
				return findEmptyCases(m_cases[i][0], m_cases[i][1], m_cases[i][2]);
		}
	}
	return nullptr;
}

Case* Cpu::findDefensiveMove(const Board& board, Point2D<Case, 3>& m_cases)
{
	// Check diagonal defensive move against human player to prevent him winning
	if (board.isOpponentWinning(m_cases[0][0], m_cases[1][1], m_cases[2][2])) // check diagonal 1
		return findEmptyCases(m_cases[0][0], m_cases[1][1], m_cases[2][2]);

	else if (board.isOpponentWinning(m_cases[0][2], m_cases[1][1], m_cases[2][0])) // check diagonal 2
		return findEmptyCases(m_cases[0][2], m_cases[1][1], m_cases[2][0]);

	// loops to search for any defensive move to prevent opponent from winning
	for (size_t i{ 0 }; i < m_cases.size(); i++)
	{
		// For columns (y)
		if (board.isCombinationPlayable(m_cases[0][i], m_cases[1][i], m_cases[2][i]))
		{
			if (board.isOpponentWinning(m_cases[0][i], m_cases[1][i], m_cases[2][i]))
				return findEmptyCases(m_cases[0][i], m_cases[1][i], m_cases[2][i]);
		}

		// For rows (x)
		if (board.isCombinationPlayable(m_cases[i][0], m_cases[i][1], m_cases[i][2]))
		{
			if (board.isOpponentWinning(m_cases[i][0], m_cases[i][1], m_cases[i][2]))
				return findEmptyCases(m_cases[i][0], m_cases[i][1], m_cases[i][2]);
		}
	}
	return nullptr;
}

Case* Cpu::findAggressiveMove(const Board& board, Point2D<Case, 3>& m_cases)
{
	if (m_cases[1][1].isEmpty())
		return &m_cases[1][1];

	else if (m_cases[0][0] != 'X' && m_cases[1][1] != 'X' && m_cases[2][2] != 'X') // check diagonal 1
		return findEmptyCases(m_cases[0][0], m_cases[1][1], m_cases[2][2]);

	else if (m_cases[0][2] != 'X' && m_cases[1][1] != 'X' && m_cases[2][0] != 'X') // check diagonal 2
		return findEmptyCases(m_cases[0][2], m_cases[1][1], m_cases[2][0]);

	// loops to find aggressive move to win
	for (size_t i{ 0 }; i < m_cases.size(); i++)
	{
		// For columns (y)
		if (board.isCombinationPlayable(m_cases[0][i], m_cases[1][i], m_cases[2][i]))
		{
			if (m_cases[0][i] != 'X' && m_cases[1][i] != 'X' && m_cases[2][i] != 'X')
				return findEmptyCases(m_cases[0][i], m_cases[1][i], m_cases[2][i]);
		}

		// For rows (x)
		if (board.isCombinationPlayable(m_cases[i][0], m_cases[i][1], m_cases[i][2]))
		{
			if (m_cases[i][0] != 'X' && m_cases[i][1] != 'X' && m_cases[i][2] != 'X')
				return findEmptyCases(m_cases[i][0], m_cases[i][1], m_cases[i][2]);
		}
	}
	return nullptr;
}

Case* Cpu::findNormalMove(const Board& board, Point2D<Case, 3>& m_cases)
{
	// loops to find a normal move if neither of above conditions are filled
	for (size_t i{ 0 }; i < m_cases.size(); i++)
	{
		// For columns (y)
		if (board.isCombinationPlayable(m_cases[0][i], m_cases[1][i], m_cases[2][i]))
			return findEmptyCases(m_cases[0][i], m_cases[1][i], m_cases[2][i]);

		// For rows (x)
		if (board.isCombinationPlayable(m_cases[i][0], m_cases[i][1], m_cases[i][2]))
			return findEmptyCases(m_cases[i][0], m_cases[i][1], m_cases[i][2]);
	}
	return nullptr;
}

Case& Cpu::playMove(Board& board)
{
	Point2D<Case, 3>& m_cases{ board.get_m_cases() };

	Case* move{ nullptr };

	if (move = findWinningMove(board, m_cases))
		return *move;

	else if (move = findWinningMove(board, m_cases))
		return *move;

	else if (move = findDefensiveMove(board, m_cases))
		return *move;

	else if (move = findAggressiveMove(board, m_cases))
		return *move;

	else if (move = findNormalMove(board, m_cases))
		return *move;

	throw std::runtime_error{ "Error : Cannot play any move" };
}