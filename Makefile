##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##


SRC = main.c
SRC += $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

NAME = my_paint

GRAPHICS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window
CPPFLAGS = -I./lib/my

all: $(NAME)

libmy:
	make -s -C lib/my

$(NAME):	libmy $(OBJ)
		gcc $(CPPFLAGS) -L./lib/my -o $(NAME) $(OBJ) -lmy $(GRAPHICS)

clean:
	rm $(OBJ)
	find . -name "*.o" -delete

fclean: clean
		rm -f $(NAME)
		find . -name "*.a" -delete
re: fclean all
