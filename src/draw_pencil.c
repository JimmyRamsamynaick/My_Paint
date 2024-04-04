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

void save_draw(sfVertexArray *vertexArray, sfVector2f currsor_pos,
    button *draw_zone, all_object_t *paint)
{
    sfVertex vert1 = {{MOUSE_X - 20, MOUSE_Y - 20},
    COLOR_PEN, {0, 0}};
    sfVertex vert2 = {{MOUSE_X, MOUSE_Y - 20}, COLOR_PEN, {1, 0}};
    sfVertex vert3 = {{MOUSE_X, MOUSE_Y}, COLOR_PEN, {1, 1}};
    sfVertex vert4 = {{MOUSE_X - 20, MOUSE_Y}, COLOR_PEN, {0, 1}};

    sfVertexArray_append(vertexArray, vert1);
    sfVertexArray_append(vertexArray, vert2);
    sfVertexArray_append(vertexArray, vert3);
    sfVertexArray_append(vertexArray, vert4);
    sfVertexArray_setPrimitiveType(vertexArray, sfQuads);
    sfRenderWindow_drawVertexArray(paint->window, vertexArray, NULL);
}

void draw_pencil(button *draw_zone, all_object_t *paint)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(paint->window);
    sfVector2f currsor_pos = { 0 };
    sfFloatRect rect = { 0 };
    sfVertexArray *vertexArray = { 0 };

    currsor_pos = sfRenderWindow_mapPixelToCoords(paint->window,
    mouse_pos, NULL);
    if (draw_zone->state == PRESSED) {
        rect = sfRectangleShape_getGlobalBounds(draw_zone->rect);
        if (sfFloatRect_contains(&rect, MOUSE_X - 20, MOUSE_Y - 20) == 1) {
            vertexArray = sfVertexArray_create();
            save_draw(vertexArray, currsor_pos, draw_zone, paint);
        }
        return;
    }
}
