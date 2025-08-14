/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** my_putchar.c
*/

#include <unistd.h>

int my_putchar(char c)
{
    return write(1, &c, 1);
}
