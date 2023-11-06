#include "Conf.hpp"

void Conf::_setTables() {
    for (int i = 0; i < _mode; i++) {
        std::shared_ptr<Board> brd = std::make_shared<Board>(_wordsLenght, _maxGuess);
        _tables.push_back(brd);
    }
}

std::vector<std::shared_ptr<Board> > Conf::getTables() {
	return this->_tables;
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
