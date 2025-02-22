#include "board.h"

int inputChoice(const char& sign)
{
	std::cout << "Enter the case number [" << sign << "]: ";
	int input{};
	while(true)
	{
		std::cin >> input;
		if (input < 0 || input > 8)
		{
			std::cout << "You did not entered a number between 0 and 8! Try again [" << sign <<"]: ";
			continue;
		}
		else if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong input! Try again [" << sign <<"]: ";
			continue;
		}
		return input;
	}
}

int main()
{
	std::cout << "Welcome to tic-tac-toe !\n\n";

	std::array<char, 2> players{ 'X', 'O' };

	Board board{};

	bool continueGame{ true };
	while(continueGame)
	{
		for (const auto& sign : players)
		{
			while(true)
			{
				std::cout << board << "\n\n"; // display board

				const int choice{ inputChoice(sign) }; // User input choice

				Case& selectedCase{ board.getCase(choice) }; // getting ref of the selected case

				if (selectedCase.isEmpty()) // verifying if the case is empty
				{
					selectedCase.fillCase(sign); // filling case with the correct sign
					break;
				}
				else
				{
					std::cout << "Case already checked !\n";
					continue;
				}
			}

			if (board.hasWon(sign) || board.isDraw())
			{
				continueGame = false;
				break;
			}
		}
	}


	std::cout << board << "\n\nGame Over !\n";
}  