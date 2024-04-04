/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** write a function that displays the number given as a parameter.
*/

#include "my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar((nb % 10) + '0');
}
