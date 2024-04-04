/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** my_paint.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"

int my_paint(void)
{
    all_object_t *paint = init_all_obj();

    sfRenderWindow_clear(WINDOW, sfBlack);
    sfRenderWindow_drawRectangleShape(WINDOW, paint->draw_zone->rect, NULL);
    while (sfRenderWindow_isOpen(WINDOW)) {
        before_action(paint);
        analye_events(paint);
        draw_pencil(paint->draw_zone, paint);
        after_act_draw(paint);
    }
    free_all_obj(paint);
    return SUCCESS;
}
