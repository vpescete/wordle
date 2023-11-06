#ifndef CONF_HPP
# define CONF_HPP

# include "wordle.h"

class Board;
class Keyboard;

class Conf {
	private:
		int	_mode;
		int	_wordsLenght;
		int	_maxGuess;

		std::vector<std::shared_ptr<Board> > _tables;
		void	_setTables();
	public:
		Conf(int mode, int len) : _mode(mode), _wordsLenght(len) {
			if (mode == 1)
				_maxGuess = 6;
			else if (mode == 2)
				_maxGuess = 7;
			else if (mode == 4)
				_maxGuess = 9;
			_setTables();
		};
		~Conf() {};

		std::vector<std::shared_ptr<Board> >	getTables();
		void		printTables();
		int			getMaxGuess() {
			return _maxGuess;
		};
};

#endif