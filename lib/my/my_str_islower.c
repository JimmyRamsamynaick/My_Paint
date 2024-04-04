/*
** EPITECH PROJECT, 2023
** str_is_lower
** File description:
** is lower
*/

#include "my.h"

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            i = i +1;
        } else {
            return 0;
        }
    }
    return 1;
}
