##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## It's the Makefile
##

TESTS = $(shell find tests -name "*.c" -type f)

SRC =	$(shell find src -name "*.c" -type f)

NAME = game_of_life

CRITERION = -lcriterion --coverage

ERROR = -Werror -Wall -pedantic -g3

all: $(NAME)

$(NAME):
	@gcc $(ERROR) -o ${NAME} $(SRC)
	@echo ">>> Executable \"${NAME}\" created."

clean:
	@rm -f src/*.o

fclean: clean
	@rm -f $(NAME)
	@echo ">>> All files was clean."

re: fclean all

unit_tests: fclean lib
	@gcc $(ERROR) -o unit_tests $(SRC) $(TESTS) $(CRITERION)
	./unit_tests
	@rm -f *.gcno *.gcda
	@rm -f unit_tests
