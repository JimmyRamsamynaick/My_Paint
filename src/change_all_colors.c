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

void change_colors_button(button_t *button)
{
    if (!button || !button->shape)
        return;
        
    if (button->is_pressed) {
        // Selected tool - use a distinct color and thicker border
        sfRectangleShape_setFillColor(button->shape, button->pressed_color);
        sfRectangleShape_setOutlineThickness(button->shape, 3);
        sfRectangleShape_setOutlineColor(button->shape, sfBlue);
    } else if (button->is_hovered) {
        // Hovered button
        sfRectangleShape_setFillColor(button->shape, button->hover_color);
        sfRectangleShape_setOutlineThickness(button->shape, 2);
        sfRectangleShape_setOutlineColor(button->shape, sfBlack);
    } else {
        // Normal button
        sfRectangleShape_setFillColor(button->shape, button->normal_color);
        sfRectangleShape_setOutlineThickness(button->shape, 1);
        sfRectangleShape_setOutlineColor(button->shape, sfBlack);
    }
}

void change_all_colors(all_object_t *paint)
{
    if (!paint || !paint->toolbar || !paint->toolbar->tool_buttons)
        return;
        
    for (int i = 0; i < paint->toolbar->num_tools; i++) {
        if (paint->toolbar->tool_buttons[i])
            change_colors_button(paint->toolbar->tool_buttons[i]);
    }
}
