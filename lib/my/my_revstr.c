/*
** EPITECH PROJECT, 2023
** strlen.c
** File description:
** my_strlen
*/

#include "my.h"

void rev(char *a, char *b)
{
    char c = *a;

    *a = *b;
    *b = c;
}

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;

    while (i < j) {
        rev(&str[i], &str[j]);
        j = j - 1;
        i = i + 1;
    }
    return str;
}
