/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-sokoban-jimmy.ramsamynaick
** File description:
** my_str_to_word_array.c
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

int my_str_replace(char *str, char c, char d)
{
    int i = 0;
    int compt = 0;

    while (str[i] != '\0') {
        if (str[i] == c) {
            str[i] = d;
            compt = compt + 1;
        }
        i = i + 1;
    }
    return compt;
}

char **my_strdup_to_word_array(char *str)
{
    int space_count = 0;
    char **word_array = NULL;
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ') {
            space_count = space_count + 1;
        }
        i = i + 1;
    }
    word_array = malloc(sizeof(char *) *(space_count + 2));
    i = 0;
    while (j < space_count + 1) {
        word_array[j] = my_strdup(str);
        i = i + my_strlen(word_array[j]) + 1;
        j = j + 1;
    }
    word_array[j] = NULL;
    return word_array;
}

char **my_str_to_word_array(char const *str)
{
    char *tempo = my_strdup(str);
    char **result = my_strdup_to_word_array(tempo);

    free(tempo);
    return result;
}
