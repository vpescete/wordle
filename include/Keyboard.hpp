#ifndef KEYBOARD_HPP
# define KEYBOARD_HPP

# include "wordle.h"

class Board;

class Keyboard {
	private:
		std::vector<std::unordered_map<char, int> > _keyboard;

		void	_initMap();
	public:
		Keyboard() : _keyboard(3) {
			_initMap();
		};
		~Keyboard() {};

		void	updateMap(std::string input, Board & board);
		void	printKeybaord();
};

#endif