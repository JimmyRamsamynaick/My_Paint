/*
** EPITECH PROJECT, 2023
** strncat
** File description:
** strncat.c
*/

#include <string.h>
#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int dest_len = strlen(dest);

    while (src[i] != nb - 1) {
        dest[dest_len + i] = src[i];
        i = i + 1;
    }
    dest[dest_len + i] = '\0';
    return dest;
}
