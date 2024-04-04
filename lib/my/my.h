/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** lib
*/

#ifndef LIBMY_
        #define LIBMY_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "my_printf.h"
    #include "menu.h"

    #define IS_LOWERCASE(c) ((c) >= 'a' && (c) <= 'z')
    #define IS_UPPERCASE(c) ((c) >= 'A' && (c) <= 'Z')
    #define IS_ALPHA(c) (IS_LOWERCASE(c) || IS_UPPERCASE(c))
    #define IS_NUM(c) ((c) >= '0' && (c) <= '9')
    #define IS_ALPHANUM(c) (IS_NUM(c) || IS_ALPHA(c))
    #define IS_PRINTABLE(c) ((c) >= ' ' && (c) <= '~')

    #define MIN(x, y) (((x) < (y)) ? (x) : (y))
    #define MAX(x, y) (((x) > (y)) ? (x) : (y))
    #define ABS(n) (((n) > 0) ? (n) : -(n))

    #define BASE_BIN "01"
    #define BASE_OCT "01234567"
    #define BASE_DEC "0123456789"
    #define BASE_HEX "0123456789abcdef"
    #define BASE_HEX_MIN "0123456789abcdef"
    #define BASE_HEX_MAJ "0123456789ABCDEF"

int my_getnbr(char *str);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
int afficher_dossier(int argc, char **argv);
int ls_cache(int argc, char **argv);
int my_putnstr(char const *str, unsigned int n);
int directory(int argc, char **argv);
int my_printf(const char *restrict format, ...);
int printf_bool_helper(printf_args_t *arg, char *str_true, char *str_false);
int printf_char(printf_args_t *arg);
int printf_purcent(printf_args_t *arg);
int printf_float(printf_args_t *arg);
int printf_rounded_float(printf_args_t *arg);
int printf_int(printf_args_t *arg);
int printf_len(printf_args_t *arg);
int printf_octal(printf_args_t *arg);
int printf_decimal(printf_args_t *arg);
int printf_hexadecimal(printf_args_t *arg);
int printf_hexadecimal2(printf_args_t *arg);
int printf_str(printf_args_t *arg);
int printf_pointer(printf_args_t *arg);
int printf_bool_min(printf_args_t *arg);
int my_nbr_len(int n, const char *base);
int my_put_double(double n, int precision);
int my_nbr_len(int n, const char *base);
int my_putnchar(char c, int n);
int my_put_double_base(double n, const char *base, int precision);
int my_put_unsigned_base(unsigned int nbr, char const *base);
int my_put_long_base(unsigned long nbr, char const *base);
int right_pad(printf_args_t *arg, int written);
int left_pad(printf_args_t *arg, int written);
int may_you_show_this_formatting(char **ptr, printf_args_t *arg);
int my_putnbr_base(int nbr, char const *base);
int game_setup(void);
int mouse_click(void);
sfSprite sprite(sfRenderWindow *window, sfEvent event, sfSprite *sprite);
int fermeture(sfRenderWindow *window, sfEvent event, sfSprite *sprite);
char **my_str_to_word_array(char const *str);
char *my_strdup(char const *src);
int my_str_replace(char *str, char c, char d);
char **my_strdup_to_word_array(char *str);
char **my_str_to_word_array(char const *str);

#endif
