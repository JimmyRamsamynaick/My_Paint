/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** draw.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <stdlib.h>
#include <stdio.h>

void draw_button(sfRenderWindow *window, t_gui_drop_object *button)
{
    sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
    sfRenderWindow_drawText(window, button->text, NULL);
}

void before_action(all_object_t *paint)
{
    sfRenderWindow_drawRectangleShape(WINDOW, paint->eraser->rect, NULL);
    sfRenderWindow_drawRectangleShape(WINDOW, paint->pencil->rect, NULL);
    draw_button(WINDOW, paint->edit_menu->button);
    draw_button(WINDOW, paint->help_menu->button);
    draw_button(WINDOW, paint->file_menu->button);
}

void check_tools_act(all_object_t *paint)
{
    if (paint->eraser->state == PRESSED) {
        paint->pencil_color = sfWhite;
        sfRectangleShape_setOutlineColor(paint->eraser->rect, sfRed);
        sfRectangleShape_setOutlineColor(paint->pencil->rect, sfWhite);
    }
    if (paint->pencil->state == PRESSED) {
        paint->pencil_color = sfBlack;
        sfRectangleShape_setOutlineColor(paint->pencil->rect, sfRed);
        sfRectangleShape_setOutlineColor(paint->eraser->rect, sfBlack);
    }
}

void after_act_draw(all_object_t *paint)
{
    if (paint->file_menu->button->state == PRESSED)
        draw_button(WINDOW, paint->file_menu->options->option);
    check_tools_act(paint);
    sfRenderWindow_display(WINDOW);
}
