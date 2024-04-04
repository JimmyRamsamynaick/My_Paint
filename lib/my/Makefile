##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

SRC = my_isneg.c
SRC += my_getnbr.c
SRC += my_is_prime.c
SRC += my_put_nbr.c
SRC += my_revstr.c
SRC += my_strcmp.c
SRC += my_str_isalpha.c
SRC += my_str_isnum.c
SRC += my_str_isupper.c
SRC += my_strlowcase.c
SRC += my_strncmp.c
SRC += my_strupcase.c
SRC += my_putchar.c
SRC += my_putstr.c
SRC += my_strcat.c
SRC += my_strcpy.c
SRC += my_str_islower.c
SRC += my_str_isprintable.c
SRC += my_strlen.c
SRC += my_strncat.c
SRC += my_strncpy.c
SRC += my_swap.c
SRC += ls_cache.c
SRC += my_printf.c
SRC += my_putnstr.c
SRC += ls_directory.c
SRC += bool.c
SRC += char.c
SRC += float.c
SRC += int.c
SRC += len.c
SRC += ptr.c
SRC += str.c
SRC += unsigned.c
SRC += my_nbr_len.c
SRC += my_put_double.c
SRC += my_put_double_base.c
SRC += my_put_unsigned_base.c
SRC += my_put_long_base.c
SRC += flag_utils.c
SRC += flag_parser.c
SRC += my_put_nbr_base.c
SRC += my_str_to_word_array.c
SRC += my_str_dup.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all : $(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME)	$(OBJ)

clean:
	rm $(OBJ)

fclean: clean
		rm -f $(NAME)
		find . -name "*.a" -delete

re: fclean all
