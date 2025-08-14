/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** draw_pencil.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

void draw_pencil_pixel(all_object_t *paint, sfVector2i pos)
{
    if (!paint || !paint->canvas || !paint->current_tool)
        return;
        
    // Convert window coordinates to canvas coordinates
    int canvas_x = pos.x - paint->canvas->position.x;
    int canvas_y = pos.y - paint->canvas->position.y;
    
    // Check if position is within canvas bounds
    if (canvas_x < 0 || canvas_x >= paint->canvas->size.x ||
        canvas_y < 0 || canvas_y >= paint->canvas->size.y)
        return;
    
    // Draw pixel on canvas texture
    sfRenderTexture_setActive(paint->canvas->texture, sfTrue);
    
    // Create a small circle for pencil drawing
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setRadius(circle, paint->current_tool->size / 2.0f);
    sfCircleShape_setFillColor(circle, paint->current_tool->color);
    sfCircleShape_setPosition(circle, (sfVector2f){canvas_x - paint->current_tool->size / 2.0f, 
                                                   canvas_y - paint->current_tool->size / 2.0f});
    
    sfRenderTexture_drawCircleShape(paint->canvas->texture, circle, NULL);
    sfRenderTexture_display(paint->canvas->texture);
    
    sfCircleShape_destroy(circle);
    paint->canvas->modified = 1;
}

void draw_pencil_line(all_object_t *paint, sfVector2i start, sfVector2i end)
{
    if (!paint)
        return;
        
    // Simple line drawing using Bresenham's algorithm
    int dx = abs(end.x - start.x);
    int dy = abs(end.y - start.y);
    int sx = start.x < end.x ? 1 : -1;
    int sy = start.y < end.y ? 1 : -1;
    int err = dx - dy;
    
    sfVector2i current = start;
    
    while (1) {
        draw_pencil_pixel(paint, current);
        
        if (current.x == end.x && current.y == end.y)
            break;
            
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            current.x += sx;
        }
        if (e2 < dx) {
            err += dx;
            current.y += sy;
        }
    }
}
