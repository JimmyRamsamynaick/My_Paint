/*
** EPITECH PROJECT, 2023
** str_isupper
** File description:
** upper
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            i = i +1;
        } else {
            return 0;
        }
    }
    return 1;
}
