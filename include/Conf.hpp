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
		std::vector<std::shared_ptr<Keyboard> > _keyboards;
		void	_setTables();
		void	_setKeyboards();
	public:
		Conf(int mode, int len) : _mode(mode), _wordsLenght(len) {
			if (mode == 1)
				_maxGuess = 6;
			else if (mode == 2)
				_maxGuess = 7;
			else if (mode == 4)
				_maxGuess = 9;
			_setTables();
			_setKeyboards();
		};
		~Conf() {};

		std::vector<std::shared_ptr<Board> >	getTables();
		std::vector<std::shared_ptr<Keyboard> >	getKeyboards();
		void		printTables();
		int			getMode() {
			return _mode;
		};
		int			getMaxGuess() {
			return _maxGuess;
		};
};

#endif