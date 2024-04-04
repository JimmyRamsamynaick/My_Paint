/*
** EPITECH PROJECT, 2023
** my_isneg.c
** File description:
** Write a function that displays either N if the integer passed
** As parameter is negative or P, if positive or null
*/

#include "my.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    my_putchar('\n');
    return (0);
}
