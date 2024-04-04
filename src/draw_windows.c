/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** draw_windows.c
*/

#include "../my.h"
#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

button *init_draw_windows(void)
{
    button *result = malloc(sizeof(button_t));

    result->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(result->rect, (sfVector2f){1500, 600});
    sfRectangleShape_setFillColor(result->rect, sfWhite);
    sfRectangleShape_setPosition(result->rect, (sfVector2f){200, 200});
    result->state = NONE;
    result->zone_is_cliked = zone_clicked;
    return result;
}
