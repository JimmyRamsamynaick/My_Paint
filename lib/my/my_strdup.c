/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** my_strdup.c
*/

#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    char *dup;
    int len;
    
    if (!src)
        return NULL;
    
    len = my_strlen(src);
    dup = malloc(sizeof(char) * (len + 1));
    
    if (!dup)
        return NULL;
    
    my_strcpy(dup, src);
    return dup;
}