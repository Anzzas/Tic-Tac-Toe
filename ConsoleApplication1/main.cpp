#include "board.h"

int inputChoice()
{
	std::cout << "Enter the number of the case you want to take: ";
	int input{};
	while(true)
	{
		std::cin >> input;
		if (input < 0 || input > 8)
		{
			std::cout << "You did not entered a number between 0 and 8! Try again: ";
			continue;
		}
		else if (!std::cin)
		{
			std::cout << "Wrong input! Try again: ";
			continue;
		}
		return input;
	}
}

int main()
{
	std::cout << "Welcome to tic-tac-toe !\n\n";

	Board board{};

	std::cout << board << "\n\n";

	const int choice{ inputChoice() };

	Case selectedCase{ board.getCase(choice) };

	if (selectedCase.isEmpty())
		selectedCase.checkCase();
	else
		std::cout << "Case already checked !\n";
}  