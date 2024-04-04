/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** init_all.c
*/

#include "../my.h"
#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

all_object_t *init_all_obj(void)
{
    all_object_t *result = malloc(sizeof(all_object_t));

    result->window = init_window();
    result->edit_menu = init_edit_menu();
    result->file_menu = init_file_menu();
    result->help_menu = init_help_menu();
    result->draw_zone = init_draw_windows();
    result->eraser = init_eraser();
    result->pencil = init_pencil();
    result->pencil_color = sfBlack;
    return result;
}
