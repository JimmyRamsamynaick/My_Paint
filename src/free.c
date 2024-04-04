/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** free.c
*/

#include "../my.h"
#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void free_drawings(all_object_t *paint)
{
    sfRectangleShape_destroy(paint->draw_zone->rect);
    free(paint->draw_zone);
    sfRectangleShape_destroy(paint->eraser->rect);
    free(paint->eraser);
    sfRectangleShape_destroy(paint->pencil->rect);
    free(paint->pencil);
}

void free_all_obj(all_object_t *paint)
{
    sfRectangleShape_destroy(paint->edit_menu->button->rect);
    sfFont_destroy(paint->edit_menu->button->font);
    sfText_destroy(paint->edit_menu->button->text);
    free(paint->edit_menu->button);
    sfRectangleShape_destroy(paint->file_menu->button->rect);
    sfFont_destroy(paint->file_menu->button->font);
    sfText_destroy(paint->file_menu->button->text);
    free(paint->file_menu->button);
    sfRectangleShape_destroy(paint->help_menu->button->rect);
    sfFont_destroy(paint->help_menu->button->font);
    sfText_destroy(paint->help_menu->button->text);
    sfRenderWindow_destroy(paint->window);
    free_drawings(paint);
    free(paint->help_menu->button);
    free(paint->edit_menu);
    free(paint->help_menu);
    free(paint->file_menu);
    free(paint);
}
