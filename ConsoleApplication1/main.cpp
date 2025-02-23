#include "board.h"
#include "cpu.h"

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
	while(true)
	{
		std::cout << "Welcome to tic-tac-toe !\n\n";

		std::array<std::unique_ptr<Player>, 2> players
		{
			std::make_unique<Player>('X'),
			std::make_unique<Cpu>('O'),
		};

		Board board{};

		bool continueGame{ true };
		while (continueGame)
		{
			for (const auto& player : players)
			{
				if (Cpu * cpu{ dynamic_cast<Cpu*>(player.get()) })
				{
					try
					{
						cpu->playMove(board).fillCase(cpu->getSign());
					}
					catch (std::runtime_error& error)
					{
						std::cerr << error.what();
						return 0;
					}
				}

				else
				{
					while (true)
					{
						std::cout << board << "\n\n"; // display board

						const int choice{ inputChoice(player->getSign()) }; // User input choice

						Case& selectedCase{ board.getCase(choice) }; // getting ref of the selected case

						if (selectedCase.isEmpty()) // verifying if the case is empty
						{
							selectedCase.fillCase(player->getSign()); // filling case with the correct sign
							break;
						}
						else
						{
							std::cout << "Case already checked !\n";
							continue;
						}
					}
				}

				if (board.hasWon() || board.isDraw())
				{
					continueGame = false;
					break;
				}
			}
		}

		std::cout << board << "\n\nGame Over ! Play again ? (y/n): ";
		char pAgain{};
		std::cin >> pAgain;
		if (pAgain == 'n' || pAgain == 'N')
			return 0;
		std::cout << "\n\n\n\n\n\n";
	}
}  