/*
** EPITECH PROJECT, 2023
** ls.h
** File description:
** my_ls.h
*/

#include "my.h"
#ifndef MY_LS
    #define MY_LS

    #include <stdarg.h>

    #define FORMAT_N 2

typedef int (func_t);

typedef struct {
    char format;
    int (*funct)(int argc, char **argv);
} format_t;

const format_t FORMAT_FUNCS[FORMAT_N] = {
    {'a', &ls_cache},
    {'d', &directory},
};

#endif
