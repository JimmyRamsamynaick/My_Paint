/*
** EPITECH PROJECT, 2023
** strncpy.c
** File description:
** ncopie
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i != n - 1) {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return dest;
}
