/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** Write a function that counts and returns the number
** Of characters found in the string passed as parameter
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
