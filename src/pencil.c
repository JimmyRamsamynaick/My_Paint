/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** pencil.c
*/

#include "../include/all_macros.h"
#include "../include/my_paint.h"
#include "../include/struct.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

// Define missing constants
#define BUTTON_THICK 2
#define NONE 0

// Forward declaration
int zone_clicked(void);

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

button_t *init_pencil(void)
{
    button_t *result = malloc(sizeof(button_t));
    
    if (!result)
        return NULL;
    
    result->position = VECTOR2I(1000, 25);
    result->size = VECTOR2I(50, 50);
    result->is_pressed = 0;
    result->is_hovered = 0;
    
    return result;
}

// Helper function for zone clicked
int zone_clicked(void)
{
    return 0; // TODO: Implement zone click detection
}
