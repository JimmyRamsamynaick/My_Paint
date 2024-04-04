/*
** EPITECH PROJECT, 2023
** My printf
** File description:
** my_put_double
*/

#include "my.h"

int my_put_double(double n, int precision)
{
    return my_put_double_base(n, BASE_DEC, precision);
}
