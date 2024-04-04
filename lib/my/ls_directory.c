/*
** EPITECH PROJECT, 2023
** ls_d
** File description:
** flag d
*/

#include <dirent.h>
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int directory(int argc, char **argv)
{
    DIR *dir;
    struct dirent *open;

    open = readdir(dir);
    my_printf("%s", open->d_name);
}
