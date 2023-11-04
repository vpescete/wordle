#include "Keyboard.hpp"

void Keyboard::_initMap() {
	std::string first = "QWERTYUIOP";
	std::string second = "ASDFGHJKL";
	std::string third = "ZXCVBNM";
	std::vector<std::unordered_map<char, int> >::iterator it = _keyboard.begin();
	for (int j = 0; first[j]; j++) {
		(*it)[first[j]] = 0;
	}
	it++;
	for (int j = 0; second[j]; j++) {
		(*it)[second[j]] = 0;
	}
	it++;
	for (int j = 0; third[j]; j++) {
		(*it)[third[j]] = 0;
	}
}


void Keyboard::updateMap(std::string input, Board & board) {
	for (int i = 0; input[i]; i++) {
		if (input[i] >= 'a' && input[i] <= 'z')
			input[i] -= 32;
	}

	std::vector<std::unordered_map<char, int> >::iterator it = _keyboard.begin();
	for (int i = 0; it != _keyboard.end() && i < 3; it++, i++) {
		if (i == 1)
			std::cout << " ";
		else if (i == 2)
			std::cout << "  ";
		// std::unordered_map<char, int>::iterator ite = (*it).begin();
		for (int j = 0; input[j]; j++) {
			char letter = input[j];
			// Verifica se la lettera è nella parola da trovare e se è una chiave valida nella mappa
			if (board.getWord().find(letter) != std::string::npos && (*it).find(letter) != (*it).end()) {
				(*it)[letter] = 2; // Imposta il valore a 2
			}
			else if ((*it).find(letter) != (*it).end()) {
				(*it)[letter] = 1; // Imposta il valore a 1
			}
		}
		// for (; ite != (*it).end(); ite++) {
		// 	if ((*ite).second == 0)
		// 		std::cout << GREY << (*ite).first << RESET << " ";
		// 	else if ((*ite).second == 1)
		// 		std::cout << RED << (*ite).first << RESET << " ";
		// 	else if ((*ite).second == 2)
		// 		std::cout << GREEN << (*ite).first << RESET << " ";
		// }
		// std::cout << std::endl;
	}
}

void Keyboard::printKeybaord() {
	std::vector<std::unordered_map<char, int> >::iterator it = _keyboard.begin();
	for (int i = 0; it != _keyboard.end() && i < 3; it++, i++) {
		std::cout << "   ";
		if (i == 1)
			std::cout << " ";
		else if (i == 2)
			std::cout << "  ";
		std::unordered_map<char, int>::iterator ite = (*it).begin();
		for (; ite != (*it).end(); ite++) {
			if ((*ite).second == 0)
				std::cout << GREY << (*ite).first << RESET << " ";
			else if ((*ite).second == 1)
				std::cout << RED << (*ite).first << RESET << " ";
			else if ((*ite).second == 2)
				std::cout << GREEN << (*ite).first << RESET << " ";
		}
		std::cout << std::endl;
	}
}
