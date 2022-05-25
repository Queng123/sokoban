##
## EPITECH PROJECT, 2021
## test
## File description:
## test
##

SRC			=	src/sokoban.c				\
				src/game_main.c				\
				src/move.c 					\
				src/game_end.c				\
				src/find_player_pos.c		\
				src/find_objective_pos.c	\
				src/check_block.c			\
				src/error_handling.c		\

TEST_FONC	=	tests/test_my_sokoban.c	\

MAIN		=	src/main.c

OBJ_MAIN	=	$(MAIN:%.c=%.o)
OBJ_SRC		=	$(SRC:%.c=%.o)

OBJ_TEST	+=	$(OBJ_SRC)
OBJ_TEST	+=	$(TEST_FONC:.c=.o)

TEST_BINARY	=	unit_tests

CFLAGS		=	-Wall -Wextra -I./include/

TESTS_FLAGS	=	--coverage -lcriterion -I./include

LIB_FLAGS	=	-L./lib/ -lmy -lncurses

NAME		=	my_sokoban

all:		$(NAME)

$(NAME):	$(OBJ_SRC) $(OBJ_MAIN)
			cp -r ./lib/my/include/. ./include/.
			make -C lib/my/
			gcc $(OBJ_SRC) $(OBJ_MAIN) $(LIB_FLAGS) -o $(NAME)

tests_run:
		make re
		gcc -o $(TEST_BINARY) $(SRC) $(TEST_FONC) $(LIB_FLAGS) $(TESTS_FLAGS)
		./$(TEST_BINARY)
		gcovr --exclude tests --branches
		gcovr --exclude tests

clean:
			rm -f $(OBJ_MAIN)
			rm -f $(OBJ_SRC)
			rm -f $(OBJ_TEST)
			make -C lib/my/ clean

fclean:		clean
			rm -f $(NAME)
			rm -f $(TEST_BINARY)
			rm -f ./include/my.h
			rm -f ./lib/libmy.a
			rm -f *.gc*
			make -C lib/my/ fclean

re:	fclean all

debug:	CFLAGS += -g
debug:	re

.PHONY:		fclean clean re all
