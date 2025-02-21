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
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong input! Try again: ";
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

	for (const auto& e : players)
	{
		std::cout << board << "\n\n"; // display board

		const int choice{ inputChoice() }; // User input choice

		Case& selectedCase{ board.getCase(choice) }; // getting ref of the selected case

		if (selectedCase.isEmpty()) // verifying if the case is empty
			selectedCase.fillCase(e); // filling case with the correct sign
		else
			std::cout << "Case already checked !\n";
	}

}  