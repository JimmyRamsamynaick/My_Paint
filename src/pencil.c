/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** pencil.c
*/

#include "../my.h"
#include "../include/all_macros.h"
#include "../include/my_paint.h"
#include "../include/struct.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

/*button_t *init_pencil(void)
{
    button_t *result = malloc(sizeof(button_t));
    result->zone_is_cliked = zone_clicked;
    result->state = NONE;
    result->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(result->rect, (sfVector2f){50, 50});
    sfRectangleShape_setPosition(result->rect, (sfVector2f){1000, 25});
    sfRectangleShape_setOutlineThickness(result->rect, BUTTON_THICK);
    sfRectangleShape_setOutlineColor(result->rect, sfRed);
    sfRectangleShape_setFillColor(result->rect, sfBlack);
    return result;
}*/

button *init_pencil(void)
{
    button *result = malloc(sizeof(button_t));
    sfTexture *texture = sfTexture_createFromFile(
    "res/logo/crayon_rouge.png", NULL);

    result->zone_is_cliked = zone_clicked;
    result->state = NONE;
    result->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(result->rect, texture, sfTrue);
    sfRectangleShape_setSize(result->rect, (sfVector2f){50, 50});
    sfRectangleShape_setPosition(result->rect, (sfVector2f){1000, 25});
    sfRectangleShape_setOutlineThickness(result->rect, BUTTON_THICK);
    sfRectangleShape_setOutlineColor(result->rect, sfWhite);
    return result;
}
