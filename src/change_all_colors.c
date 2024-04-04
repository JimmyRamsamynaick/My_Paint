/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** change_all_colors.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <stdlib.h>
#include <stdio.h>

void change_colors_button(t_gui_drop_object *button)
{
    switch (button->state) {
        case HOVER:
            sfRectangleShape_setFillColor(button->rect, sfCyan);
            break;
        case PRESSED:
            sfRectangleShape_setFillColor(button->rect, sfRed);
            break;
        default:
            sfRectangleShape_setFillColor(button->rect, sfWhite);
            break;
    }
}

void change_all_colors(all_object_t *paint)
{
    change_colors_button(paint->edit_menu->button);
    change_colors_button(paint->file_menu->button);
    change_colors_button(paint->help_menu->button);
    return;
}
