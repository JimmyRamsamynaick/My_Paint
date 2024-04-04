/*
** EPITECH PROJECT, 2023
** my_putnstr
** File description:
** put n str
*/

#include "my.h"

int my_putnstr(char const *str, unsigned int n)
{
    int i = 0;

    while (i < n) {
        my_putchar(str[i]);
        i += 1;
    }
    return n;
}
