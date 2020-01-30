##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC =	soko.c					\
		malloc_and_load_save.c	\
		move_box.c				\
		move_p.c				\
		my_putchar.c			\
		my_putstr_error.c		\
		my_putstr.c				\
		my_strlen_col.c			\
		my_strlen_lines.c		\
		my_strlen.c				\
		openread.c				\
		player.c			

OBJ = $(SRC:.c=.o)

NAME = my_sokoban

all: $(NAME)

$(NAME):   $(OBJ)
		gcc -o 	$(NAME) $(OBJ) -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
