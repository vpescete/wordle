NAME	= wordle

SRC		= srcs/main.cpp srcs/Board.cpp srcs/Keyboard.cpp

OBJ		= $(SRC:.cpp=.o)

I		= include/
CC		= c++
FLAGS	= -Wall -Wextra -Werror -I$I
RM		= rm -rf

# Colors
GREEN	= \e[92;5;118m
YELLOW	= \e[93;5;226m
GRAY	= \e[33;2;37m
RESET	= \e[0m
CURSIVE	= \e[33;3m

.PHONY: all clean fclean re

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(CURSIVE)$(GRAY) 	- Compiling $(NAME)... $(RESET)\n"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@printf "$(GREEN) - Executable ready.\n$(RESET)"
	@mkdir -p uploads

clean:
	@$(RM) $(OBJ)
	@printf "$(YELLOW) - Object files removed.$(RESET)\n"
	@rm -rf uploads

fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW) - Executable removed.$(RESET)\n"

re: fclean all