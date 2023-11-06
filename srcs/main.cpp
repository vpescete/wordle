#include "../include/wordle.h"

int	getWordLenght(std::string str) {
	if (str[0] == '1')
		return std::atoi("4");
	else if (str[0] == '2')
		return std::atoi("5");
	return 0;
}

int getSetMode(std::string str) {
	if (str[0] == '1')
		return std::atoi("1");
	else if (str[0] == '2')
		return std::atoi("2");
	else if (str[0] == '3')
		return std::atoi("4");
	return 0;
}

void	setCapInput(std::string input) {
	for (int i = 0; input[i]; i++) {
		if (input[i] >= 'a' && input[i] <= 'z')
			input[i] -=32;
	}
}

int	main(int ac, char*av[]) {
	(void)av;
	if (ac != 1) {
		std::cout << RED << "Bad numbers of arguments" << std::endl;
		return 1;
	}
	std::cout << CYAN << " ____ ____ ____ ____ ____ ____ " << RESET << std::endl;
	std::cout << CYAN << "||W |||o |||r |||d |||l |||e ||" << RESET << std::endl;
	std::cout << CYAN << "||__|||__|||__|||__|||__|||__||" << RESET << std::endl;
	std::cout << CYAN << "|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|" << RESET << std::endl << std::endl;
	std::cout << std::endl << "Welcome to Wordle!" << std::endl;
	std::cout << std::endl << "Choose one of the following modes: " << std::endl;
	std::cout << "\t1) Single mode" << std::endl
			<< "\t2) Double mode" << std::endl
			<< "\t3) Quad mode" << std::endl;
	std::string modes;
	std::cout << "Modes: ";
	std::getline(std::cin, modes);
	std::cout << std::endl;
	std::cout << std::endl << "Choose the lenght of the words to guess: " << std::endl;
	std::cout << "\t1) four" << std::endl
			<< "\t2) five" << std::endl;
	std::string length;
	std::cout << "Lenght: ";
	std::getline(std::cin, length);
	std::cout << std::endl;

	int	len = getWordLenght(length);
	int mod = getSetMode(modes);
	Conf	confGame(mod, len);
	confGame.printTables();
	for (int i = 0; i < confGame.getMaxGuess(); i++) {
		std::string input;
		std::cout << "Input: ";
		std::getline(std::cin, input);
		std::cout << std::endl;
		setCapInput(input);
		std::vector<std::shared_ptr<Board> >::iterator it = confGame.getTables().begin();
		for (; it != confGame.getTables().end(); it++) {
			if (!(**it).checkInputWord(input))
				i--;
			else
				(**it).insertWord(i, input);
		}
		confGame.printTables();
	}
	// Board board(len);
	// Keyboard keyboard;

	// for (int i = 0; i <= board.getLenght(); i++) {
	// 	std::string input;
	// 	std::cout << "Input: ";
	// 	std::getline(std::cin, input);
	// 	std::cout << std::endl;
	// 	for (int i = 0; i < board.getLenght(); i++) {
	// 		if (input[i] >= 'a' && input[i] <= 'z')
	// 			input[i] -=32;
	// 	}
	// 	if (!board.checkInputWord(input))
	// 		i--;
	// 	else {
	// 		board.insertWord(i, input);
	// 		keyboard.updateMap(input, board);
	// 	}
	// 	board.printBoard();
	// 	keyboard.printKeybaord();
	// 	if (input == board.getWord()) {
	// 		std::cout << CYAN << "   You guess the word in " << i + 1 << " attempt!" << RESET << std::endl << std::endl;
	// 		return 0;
	// 	}
	// 	std::cout << std::endl;
	// }
	// std::cout << std::endl <<"The secret word was: " << RED << board.getWord() << RESET << std::endl;
	return 0;
}