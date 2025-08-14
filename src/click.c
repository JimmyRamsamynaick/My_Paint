/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** click.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"

void button_clicked(button_t *button, sfMouseButtonEvent *mouse)
{
    if (!button || !button->shape)
        return;
        
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->shape);

    if (sfFloatRect_contains(&rect, mouse->x, mouse->y) == sfTrue) {
        button->is_pressed = 1;
        if (button->callback)
            button->callback(button);
    } else {
        button->is_pressed = 0;
    }
}

int is_point_in_canvas(all_object_t *paint, sfVector2i pos)
{
    if (!paint || !paint->canvas)
        return 0;
        
    canvas_t *canvas = paint->canvas;
    return (pos.x >= canvas->position.x && pos.x < canvas->position.x + canvas->size.x &&
            pos.y >= canvas->position.y && pos.y < canvas->position.y + canvas->size.y);
}

sfVector2i get_mouse_position(all_object_t *paint)
{
    sfVector2i pos = {0, 0};
    if (!paint || !paint->window)
        return pos;
    
    return sfMouse_getPositionRenderWindow(paint->window);
}

void handle_events(all_object_t *paint)
{
    if (!paint)
        return;
    
    analye_events(paint);
}

int is_point_in_toolbar(all_object_t *paint, sfVector2i pos)
{
    if (!paint || !paint->toolbar)
        return 0;
    
    // Simple toolbar bounds check - adjust based on actual toolbar layout
    return (pos.x >= 0 && pos.x <= 100 && pos.y >= 50 && pos.y <= 400);
}

int is_point_in_palette(all_object_t *paint, sfVector2i pos)
{
    if (!paint || !paint->palette)
        return 0;
    
    // Simple palette bounds check - adjust based on actual palette layout
    return (pos.x >= 0 && pos.x <= 100 && pos.y >= 400 && pos.y <= 600);
}
