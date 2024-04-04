/*
** EPITECH PROJECT, 2023
** str_isalpha
** File description:
** is alhpa
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
        (str[i] >= 'a' && str[i] <= 'z')) {
            i = i +1;
        } else {
            return 0;
        }
    }
    return 1;
}
