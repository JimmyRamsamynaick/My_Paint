/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** main.c
*/

#include "./include/my_paint.h"
#include "./lib/my/my.h"

void print_help(void)
{
    my_printf("Usage: make\n");
    my_printf("    then typed\n");
    my_printf("./my_paint\n");
}

int main(int argc, char *argv[])
{
    if (argc > 1 && my_strcmp(argv[1], "-h") == 0)
        print_help();
    else
        my_paint();
}
