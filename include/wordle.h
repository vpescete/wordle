#ifndef WORDLE_HPP
# define WORDLE_HPP

// ANSI Colors
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define BLUE "\e[0;34m"
# define GREY "\x1B[90m"
# define MAGENTA "\e[0;35m"
# define CYAN "\e[0;36m"
# define RESET "\e[0m"

# define FOUR "lists/ITA_4.txt"
# define FIVE "lists/ITA_5.txt"

# include <iostream>
# include <vector>
# include <map>
# include <unordered_map>
# include <iterator>
# include <random>
# include <fstream>
# include <string>

# include <string.h>
# include <unistd.h>
# include <stdio.h>

# include "Board.hpp"
# include "Keyboard.hpp"
# include "Conf.hpp"

#endif