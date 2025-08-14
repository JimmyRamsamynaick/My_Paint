/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** init_eraser.c
*/

#include "../my.h"
#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

// Define missing constants
#define BUTTON_THICK 2

button_t *init_eraser(void)
{
    button_t *result = malloc(sizeof(button_t));
    
    if (!result)
        return NULL;
    
    // Initialize eraser button with basic properties
     result->position = (sfVector2i){1200, 25};
     result->size = (sfVector2i){50, 50};
    result->is_pressed = 0;
    result->is_hovered = 0;
    
    return result;
}

void draw_eraser_button(all_object_t *obj)
{
    if (!obj || !obj->window)
        return;
    
    // Create and draw eraser button
    sfRectangleShape *rect = sfRectangleShape_create();
    sfTexture *texture = sfTexture_createFromFile("res/logo/gomme.png", NULL);
    
    if (rect) {
        if (texture)
            sfRectangleShape_setTexture(rect, texture, sfTrue);
        sfRectangleShape_setSize(rect, (sfVector2f){50, 50});
        sfRectangleShape_setPosition(rect, (sfVector2f){1200, 25});
        sfRectangleShape_setOutlineThickness(rect, BUTTON_THICK);
        sfRectangleShape_setOutlineColor(rect, sfWhite);
        
        sfRenderWindow_drawRectangleShape(obj->window, rect, NULL);
        
        sfRectangleShape_destroy(rect);
    }
    
    if (texture)
        sfTexture_destroy(texture);
}
