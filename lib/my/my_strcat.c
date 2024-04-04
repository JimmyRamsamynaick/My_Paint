/*
** EPITECH PROJECT, 2023
** strcat
** File description:
** cat
*/

#include <string.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int dest_len = strlen(dest);

    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i = i + 1;
    }
    dest[dest_len + i] = '\0';
    return dest;
}
