/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** init_canvas.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"

canvas_t *init_canvas(void)
{
    canvas_t *canvas = malloc(sizeof(canvas_t));
    
    if (!canvas)
        return NULL;
    
    // Set canvas properties
    canvas->size = VECTOR2I(CANVAS_WIDTH, CANVAS_HEIGHT);
    canvas->position = VECTOR2I(CANVAS_X, CANVAS_Y);
    canvas->background_color = CANVAS_BACKGROUND_COLOR;
    canvas->modified = 0;
    
    // Create render texture for the canvas
    canvas->texture = sfRenderTexture_create(CANVAS_WIDTH, CANVAS_HEIGHT, sfFalse);
    if (!canvas->texture) {
        free(canvas);
        return NULL;
    }
    
    // Create sprite to display the canvas
    canvas->sprite = sfSprite_create();
    if (!canvas->sprite) {
        sfRenderTexture_destroy(canvas->texture);
        free(canvas);
        return NULL;
    }
    
    // Set sprite texture and position
    sfSprite_setTexture(canvas->sprite, sfRenderTexture_getTexture(canvas->texture), sfFalse);
    sfSprite_setPosition(canvas->sprite, VECTOR2F(CANVAS_X, CANVAS_Y));
    
    // Clear canvas with background color
    sfRenderTexture_clear(canvas->texture, canvas->background_color);
    sfRenderTexture_display(canvas->texture);
    
    return canvas;
}