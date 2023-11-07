#ifndef BOARD_HPP
# define BOARD_HPP

# include "wordle.h"

class Board {
	private:
		int	_lenght;
		std::string	_word;
		int	_maxGuess;

		std::vector<std::string> _board;
		std::vector<std::string> _words;

		void	_initBoard();
		void	_setWord();
		bool	checkExistWord(std::string input);
		void	printColor(char c, int k, int p);
		void	_setMap();
		std::map<char, int>	_letterCounter;
	public:
		Board(int lenght);
		~Board();

		bool	checkInputWord(std::string input);
		void	printBoard();

		void	insertWord(int i, std::string input);
		int		getLenght();
		std::string	getWord();
		int		getMaxGuess();
};

# endif