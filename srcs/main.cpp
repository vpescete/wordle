#include "../include/wordle.h"

int	getWordLenght(std::string str) {
	if (str[0] == '1')
		return std::atoi("4");
	else if (str[0] == '2')
		return std::atoi("5");
	else
		std::cout << RED << "Choose one of the length" << RESET << std::endl;
	return 0;
}

int getSetMode(std::string str) {
	if (str[0] == '1')
		return std::atoi("1");
	else if (str[0] == '2')
		return std::atoi("2");
	else if (str[0] == '3')
		return std::atoi("4");
	else
		std::cout << RED << "\tChoose one of the modes!" << RESET << std::endl;
	return 0;
}

void	setCapInput(std::string *input) {
	for (int i = 0; (*input)[i]; i++) {
		if ((*input)[i] >= 'a' && (*input)[i] <= 'z')
			(*input)[i] -=32;
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
	int mod = 0;
	while (!mod) {

		std::cout << std::endl << "Choose one of the following modes: " << std::endl;
		std::cout << "\t1) Single mode" << std::endl
				<< "\t2) Double mode" << std::endl
				<< "\t3) Quad mode" << std::endl;
		std::string modes;
		std::cout << "Modes: ";
		std::getline(std::cin, modes);
		std::cout << std::endl;
		mod = getSetMode(modes);
	}
	int len = 0;
	while (!len) {
		std::cout << std::endl << "Choose the lenght of the words to guess: " << std::endl;
		std::cout << "\t1) four" << std::endl
				<< "\t2) five" << std::endl;
		std::string length;
		std::cout << "Lenght: ";
		std::getline(std::cin, length);
		std::cout << std::endl;

		len = getWordLenght(length);

	}
	int	guessed = 0;
	Conf	confGame(mod, len);
	std::vector<std::shared_ptr<Board> > vectorTab = confGame.getTables();
	std::vector<std::shared_ptr<Keyboard> > vectorKeyboard = confGame.getKeyboards();
	int check = 0;
	for (int i = 0; i < confGame.getMaxGuess(); i++) {
		std::string input;
		std::cout << GREEN << "Input: "; 
		std::getline(std::cin, input);
		std::cout << RESET << std::endl;
		setCapInput(&input);
		std::vector<std::shared_ptr<Board> >::iterator it = vectorTab.begin();
		std::vector<std::shared_ptr<Keyboard> >::iterator ite = vectorKeyboard.begin();
		for (int max = 0; it != vectorTab.end() && max < confGame.getMode(); it++, max++, ite++) {
			if (!(**it).checkInputWord(input)) {
				i--;
				break ;
			}
			else {
				std::cout << RED << "[TABLE " << max + 1 << "]" << RESET << std::endl;
				(**it).insertWord(i, input);
				(**ite).updateMap(input, (**it));
			}
			(**it).printBoard();
			(**ite).printKeybaord();
			if (input == (**it).getWord()) {
				(**it).setIsGuessed(true);
				std::cout << CYAN << "   You guess the word in " << i + 1 << " attempt!" << RESET << std::endl << std::endl;
				check++;
			}
		std::cout << "___________________" << std::endl << std::endl;
		}
		if (check == confGame.getMode()) {
			std::cout << std::endl << GREEN << "\tYOU WIN!!" << RESET << std::endl;
			exit(0);
		}
	}
	std::cout << std::endl << RED <<"The secret words were: " << std::endl;
	std::vector<std::shared_ptr<Board> >::iterator it = vectorTab.begin();
	for (int max = 0; it != vectorTab.end() && max < confGame.getMode(); it++, max++) {
		std::cout << RED << "\t- " << (**it).getWord() << std::endl;
	}
	return 0;
}