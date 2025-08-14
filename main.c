/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** main.c
*/

#include "include/my_paint.h"
#include "include/all_macros.h"
#include "my.h"

void print_help(void)
{
    my_putstr(HELP_TEXT);
}

static int check_arguments(int argc, char **argv)
{
    if (argc == 1)
        return SUCCESS;
    if (argc == 2) {
        if (my_strcmp(argv[1], "-h") == 0 || my_strcmp(argv[1], "--help") == 0) {
            print_help();
            return SUCCESS;
        }
        my_putstr("Error: Unknown argument '" );
        my_putstr(argv[1]);
        my_putstr("'\n");
        my_putstr("Use -h or --help for usage information.\n");
        return FAILURE;
    }
    my_putstr("Error: Too many arguments.\n");
    my_putstr("Use -h or --help for usage information.\n");
    return FAILURE;
}

int main(int argc, char **argv)
{
    int arg_result = check_arguments(argc, argv);
    
    if (arg_result != SUCCESS)
        return arg_result;
    if (argc == 2)
        return SUCCESS;
    return my_paint();
}
