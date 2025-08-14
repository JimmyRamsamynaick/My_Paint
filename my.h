/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdarg.h>
    #include <unistd.h>
    #include <stdlib.h>

// String functions
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char const *str, char const *to_find);
char *my_strdup(char const *src);

// Character functions
int my_isalpha(char c);
int my_isdigit(char c);
int my_isalnum(char c);
int my_isprint(char c);
int my_isupper(char c);
int my_islower(char c);
char my_toupper(char c);
char my_tolower(char c);

// Number functions
int my_atoi(char const *str);
char *my_itoa(int nb);
int my_getnbr(char const *str);
int my_put_nbr(int nb);
int my_putnbr_base(int nbr, char const *base);

// Output functions
int my_putchar(char c);
int my_putstr(char const *str);
int my_printf(char const *format, ...);
int my_dprintf(int fd, char const *format, ...);

// Memory functions
void *my_memset(void *s, int c, size_t n);
void *my_memcpy(void *dest, const void *src, size_t n);
void *my_memmove(void *dest, const void *src, size_t n);
int my_memcmp(const void *s1, const void *s2, size_t n);

// Array functions
char **my_str_to_word_array(char const *str);
int my_show_word_array(char * const *tab);
char *my_revstr(char *str);
char *my_strrev(char *str);

// Math functions
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_is_prime(int nb);

#endif /* !MY_H_ */
