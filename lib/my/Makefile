##
## EPITECH PROJECT, 2024
## B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
## File description:
## Makefile for libmy
##

SRC		=	my_putchar.c		\
			my_putstr.c		\
			my_strlen.c		\
			my_strcmp.c		\
			my_strcpy.c		\
			my_strdup.c		\
			my_strcat.c		\
			my_getnbr.c		\
			my_put_nbr.c		\
			my_putnbr_base.c	\
			my_atoi.c		\
			my_itoa.c

OBJ		=	$(SRC:.c=.o)

NAME		=	libmy.a

CFLAGS		=	-Wall -Wextra -Werror -std=c99

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
