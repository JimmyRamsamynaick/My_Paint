/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** click.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"

void button_clicked(t_gui_drop_object *button, sfMouseButtonEvent *mouse)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&rect, mouse->x, mouse->y) == sfTrue)
        button->state = PRESSED;
    else
        button->state = RELEASED;
}

void zone_clicked(button *draw_zone, sfMouseButtonEvent *mouse)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(draw_zone->rect);

    if (sfFloatRect_contains(&rect, mouse->x, mouse->y) == sfTrue)
        draw_zone->state = PRESSED;
    else
        draw_zone->state = RELEASED;
}
