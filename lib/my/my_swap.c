/*
** EPITECH PROJECT, 2023
** my_swap.c
** File description:
** Write a function that swaps the content of two integers,
** Whose addresses are given as a parameter
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
