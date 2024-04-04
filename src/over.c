/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** over.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"

void mouse_over(t_gui_drop_object *button, sfMouseMoveEvent *mouse)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&rect, mouse->x, mouse->y) == sfTrue &&
    button->state != PRESSED)
        button->state = HOVER;
    else
        button->state = RELEASED;
}
