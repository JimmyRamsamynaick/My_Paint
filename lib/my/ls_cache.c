/*
** EPITECH PROJECT, 2023
** ls.c
** File description:
** affiche les dossiers cache
*/

#include <dirent.h>
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int ls_cache(int argc, char **argv)
{
    DIR *dir;
    struct dirent *open;

    dir = opendir(".");
    open = readdir(dir);
    if (dir == NULL)
        return 84;
    while (open != NULL) {
        my_putstr(open->d_name);
        my_putchar('\n');
        open = readdir(dir);
    }
}
