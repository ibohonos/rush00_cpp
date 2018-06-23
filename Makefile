
NAME = ft_contrast
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@clang++ -Wall -Wextra -Werror -o $(NAME) $(SRC) -lncurses
	@echo $(NAME) "is ready to use"

clean:
	@/bin/rm -f *.o
	@echo "Object files were successfully removed"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo $(NAME) "was successfully removed"

re: fclean all
	@echo "The project was successfully recompiled"

