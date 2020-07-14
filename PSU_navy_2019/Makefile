##
## EPITECH PROJECT, 2019
## navy
## File description:
## project
##

NAME	=	navy

SRC	=	src/main.c 		\
		src/start.c		\
		src/split_pos.c		\
		src/error_handling.c	\
		src/boats_handling.c	\
		src/check_pos.c		\
		src/open_file.c		\
		src/display_h.c		\
		src/fill_map.c		\
		src/fill_map_boats.c	\
		src/display_map.c	\
		src/player_one.c	\
		src/player_two.c	\
		src/gnl.c		\
		src/game1.c		\
		src/game2.c		\
		src/win_check.c		\
		src/connect.c		\
		src/send.c		\
		src/receive.c		\
		src/map_update.c	\
		src/print_attack.c	\
		util/my_strlen.c	\
		util/my_putchar.c	\
		util/my_putstr.c	\
		util/my_strcmp.c	\
		util/my_put_nbr.c	\
		util/my_atoi.c		\
		util/write_error.c

CC	=	gcc

DEFLAGS	=	-W -Wextra -Wall -g3

CPPFLAGS=	-I./include/

CFFLAGS	=	tests/unit_tests.c -I./include --coverage -lcriterion

OBJ	=	$(SRC:.c=.o)

all	:	$(OBJ)
		$(CC) $(DEFLAGS) -o $(NAME) $(OBJ) $(CPPFLAGS)

tests_run	:
		$(CC) -o unit_tests lib/my/*.c $(CFFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)		\
		rm -f *# 		\
		rm -f src/*# 		\
		rm -f include/*# 	\
		rm -f *~ 		\
		rm -f src/*~ 		\
		rm -f include/*~ 	\
		rm -f *.gcda 		\
		rm -f *.gcno

re	:	fclean all

.PHONY	:	all tests_run clean fclean re
