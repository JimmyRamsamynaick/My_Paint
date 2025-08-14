/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** my.h - Library header
*/

#ifndef MY_H_
#define MY_H_

// Basic functions
int my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char *my_strcat(char *dest, char const *src);
int my_getnbr(char const *str);
int my_put_nbr(int nb);
int my_putnbr_base(int nbr, char const *base);
int my_atoi(char const *str);
char *my_itoa(int value);

#endif /* MY_H_ */
