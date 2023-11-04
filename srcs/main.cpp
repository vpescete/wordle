#include "../include/wordle.h"

int	getWordLenght(char *str) {
	if ((str[0] != '4' || str[0] != '5') && std::strlen(str) != 1) {
		std::cout << RED << "Bad Arguments. You can choose only 4 or 5" << std::endl;
		exit(1);
	}
	return std::atoi(str);
}

int	main(int ac, char*av[]) {
	if (ac != 2) {
		std::cout << RED << "Bad numbers of arguments" << std::endl;
		return 1;
	}

	std::cout << CYAN << " ____ ____ ____ ____ ____ ____ " << RESET << std::endl;
	std::cout << CYAN << "||W |||o |||r |||d |||l |||e ||" << RESET << std::endl;
	std::cout << CYAN << "||__|||__|||__|||__|||__|||__||" << RESET << std::endl;
	std::cout << CYAN << "|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|" << RESET << std::endl << std::endl;
	int	lenght = getWordLenght(av[1]);
	Board board(lenght);
	Keyboard keyboard;

	std::string input;
	for (int i = 0; i <= board.getLenght(); i++) {
		std::cout << "Input: ";
		std::getline(std::cin, input);
		std::cout << std::endl;
		for (int i = 0; i < board.getLenght(); i++) {
			if (input[i] >= 'a' && input[i] <= 'z')
				input[i] -=32;
		}
		if (!board.checkInputWord(input))
			i--;
		else {
			board.insertWord(i, input);
			keyboard.updateMap(input, board);
		}
		board.printBoard();
		keyboard.printKeybaord();
		if (input == board.getWord()) {
			std::cout << CYAN << "   You guess the word in " << i + 1 << " attempt!" << RESET << std::endl << std::endl;
			return 0;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl <<"The secret word was: " << RED << board.getWord() << RESET << std::endl;
	return 0;
}