#include "Conf.hpp"

void Conf::_setTables() {
	for (int i = 0; i < _mode; i++) {
		std::shared_ptr<Board> brd = std::make_shared<Board>(_wordsLenght, _maxGuess);
		_tables.push_back(brd);
	}
}

void Conf::_setKeyboards() {
	for (int i = 0; i < _mode; i++) {
		std::shared_ptr<Keyboard> keyboard = std::make_shared<Keyboard>();
		_keyboards.push_back(keyboard);
	}
}

std::vector<std::shared_ptr<Board> > Conf::getTables() {
	return this->_tables;
}

std::vector<std::shared_ptr<Keyboard> > Conf::getKeyboards() {
	return _keyboards;
}

void Conf::printTables() {
	for (int i = 0; i < _maxGuess; i++) {
		std::vector<std::shared_ptr<Board> >::iterator it = _tables.begin();
		for (; it != _tables.end(); it++) {
			std::cout << "\t" << (*it)->getBoard()[i];
		}
		std::cout << std::endl;
	}
}
