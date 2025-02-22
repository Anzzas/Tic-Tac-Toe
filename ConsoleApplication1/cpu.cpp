#include "cpu.h"

Case& Cpu::playMove(Board& board)
{
	Point2D<Case, 3>& m_cases{ board.get_m_cases() };

	for (size_t i{ 0 }; i < m_cases.size(); i++)
	{
		if (board.isCombinationPlayable(m_cases[0][i], m_cases[1][i], m_cases[2][i])) // Comment puis-je retourner directement une des qui est vide ?
		{
			for (size_t j{ 0 }; j < m_cases.size(); j++)
			{
				if (m_cases[j][i].isEmpty())
					return m_cases[j][i];
			}
		}

		if (board.isCombinationPlayable(m_cases[i][0], m_cases[i][1], m_cases[i][2]))
		{
			for (size_t j{ 0 }; j < m_cases.size(); j++)
			{
				if (m_cases[i][j].isEmpty())
					return m_cases[i][j];
			}
		}
	}

	throw std::runtime_error{ "Cannot play any move" };
}