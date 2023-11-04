#include "../include/Board.hpp"
#include "Board.hpp"

void Board::_initBoard() {
	std::string str;
	if (_lenght == 5)
		str = "_____";
	else
		str = "____";
	for (int i = 0; i < 6; i++) {
		_board.push_back(str);
	}
}

void Board::_setWord() {
	std::string path;
	if (_lenght == 5)
		path = FIVE;
	else if (_lenght == 4)
		path = FOUR;
	std::ifstream inputFile(path);

	if (!inputFile) {
		std::cerr << "Impossibile aprire il file." << std::endl;
		return ;
	}

	std::string word;

	while (std::getline(inputFile, word)) {
		_words.push_back(word);
	}

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<std::size_t> distribution(0, _words.size() - 1);
	std::size_t random_index = distribution(gen);

	_word = _words[random_index];
}
Board::Board(int lenght) : _lenght(lenght)
{
	_initBoard();
	_setWord();
	_setMap();
}
Board::~Board() {

}

bool Board::checkInputWord(std::string input) {
	if (input.size() != (unsigned long)_lenght) {
		std::cout << RED << "The lenght of the input is not " << _lenght << RESET << std::endl << std::endl;
		return false;
	}
	if (!checkExistWord(input))
		return false;
	return true;
}

bool Board::checkExistWord(std::string input) {
	for (int i = 0; i < _lenght; i++) {
		if (input[i] >= 'a' && input[i] <= 'z')
			input[i] -=32;
	}
	std::vector<std::string>::iterator it = _words.begin();
	for (; it != _words.end(); it++) {
		if (input == (*it))
			return true;
	}
	std::cout << RED << input << " dosen't exist" << RESET << std::endl;
	return false;
}

void Board::printColor(char c, int k, int p) {
	(void)k;
	int i = 0;
	int flag = 0;
	for (; i < _lenght; i++) {
		if ((c == _word[p] || (c + 32) == _word[p] || (c - 32) == _word[p])) {
			std::cout << GREEN << c << " " << RESET;
			_letterCounter[c]--;
			return ;
		}
		else if (c == _word[i] || (c + 32) == _word[i] || (c - 32) == _word[i]) {
			flag = 1;
			for (; p < _lenght; p++) {
				if ((_board[k][p] == _word[i] || (_board[k][p] + 32) == _word[i] || (_board[k][p] - 32) == _word[i]) && i == p) {
					flag = 0;
					break ;
				}
			}
			if (flag == 0)
				break ;
		}
	}
	if (flag == 1 && _letterCounter[c] != 0) {
		_letterCounter[c]--;
		std::cout << YELLOW << c << " " << RESET;
	}
	else
		std::cout << c << " ";
}

void Board::_setMap() {
	for (int i = 0; i < _lenght; i++)
		_letterCounter[_word[i]] = 0;
	for (int i = 0; i < _lenght; i++) {
		if (_letterCounter.find(_word[i]) != _letterCounter.end()) {
			_letterCounter[_word[i]]++;
		} else {
			_letterCounter[_word[i]] = 1;
		}
	}
}

void Board::insertWord(int i, std::string input) {
	for (int i = 0; i < _lenght; i++) {
		if (input[i] >= 'a' && input[i] <= 'z')
			input[i] -=32;
	}
	_board[i] = input;
}

void Board::printBoard()
{
	for (int i = 0; i < 6; i++) {
		std::cout << "\t";
		for (int j = 0; j < _lenght; j++) {
			printColor(_board[i][j], i, j);
		}
		std::cout << std::endl;
		_setMap();
	}
	std::cout << std::endl;
}

int Board::getLenght() {
	return _lenght;
}

std::string Board::getWord() {
	return _word;
}
