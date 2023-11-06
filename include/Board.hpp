#ifndef BOARD_HPP
# define BOARD_HPP

# include "wordle.h"

class Board {
	private:
		int	_lenght;
		int	_maxGuess;
		std::string	_word;

		std::vector<std::string> _board;
		std::vector<std::string> _words;

		void	_initBoard();
		void	_setWord();
		bool	checkExistWord(std::string input);
		void	printColor(char c, int k, int p);
		void	_setMap();
		std::map<char, int>	_letterCounter;
	public:
		Board(int lenght, int maxGuess);
		~Board();

		bool	checkInputWord(std::string input);
		void	printBoard();

		void	insertWord(int i, std::string input);
		int		getLenght();
		std::string	getWord();
		std::vector<std::string> getBoard();
		void	setMaxGuess(int n);
};

# endif