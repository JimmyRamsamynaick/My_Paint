/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-sokoban-jimmy.ramsamynaick
** File description:
** my_str_dup.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *duplicate = (char *) malloc(sizeof(my_strlen(src) +1));

    if (src == NULL)
        return NULL;
    if (duplicate == NULL)
        exit(EXIT_FAILURE);
    my_strcpy(duplicate, src);
    return duplicate;
}
