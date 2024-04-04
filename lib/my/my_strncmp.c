/*
** EPITECH PROJECT, 2023
** strncmp.c
** File description:
** strncmp
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i != n - 1) {
        if (s1[i] == s2[i]) {
            i = i + 1;
        } else {
            return s1[i] - s2[i];
        }
    }
    return s1[i] - s2[i];
}
