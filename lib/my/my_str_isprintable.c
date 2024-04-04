/*
** EPITECH PROJECT, 2023
** isprintable
** File description:
** printable
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 32 && str[i] <= 126) {
            i = i + 1;
        } else {
            return 1;
        }
    }
    return 0;
}
