/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** Worshop2 avec Etienne et Quentin
*/

#include <stdio.h>
#include "my.h"

int my_getnbr(char *str)
{
    int i = 0;
    int nbr = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr * 10;
            nbr = nbr + str[i] - '0';
        }
        i = i + 1;
    }
    return nbr;
}
