/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** ignoring for git
*/

#include "my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putnchar(char c, int n)
{
    for (int i = 0; i < n; i = i + 1)
        my_putchar(c);
    return n;
}
