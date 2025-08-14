/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** free.c
*/

#include "../my.h"
#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void free_drawings(all_object_t *paint)
{
    if (!paint)
        return;
    
    // Free canvas if it exists
    if (paint->canvas) {
        if (paint->canvas->texture)
            sfTexture_destroy(paint->canvas->texture);
        if (paint->canvas->sprite)
            sfSprite_destroy(paint->canvas->sprite);
        free(paint->canvas);
    }
}

void free_all_obj(all_object_t *paint)
{
    if (!paint)
        return;
    
    // Free window
    if (paint->window)
        sfRenderWindow_destroy(paint->window);
    
    // Free menu bar
    if (paint->menu_bar) {
        if (paint->menu_bar->menus) {
            for (int i = 0; i < paint->menu_bar->num_menus; i++) {
                if (paint->menu_bar->menus[i]) {
                    if (paint->menu_bar->menus[i]->items)
                        free(paint->menu_bar->menus[i]->items);
                    free(paint->menu_bar->menus[i]);
                }
            }
            free(paint->menu_bar->menus);
        }
        free(paint->menu_bar);
    }
    
    // Free toolbar
    if (paint->toolbar) {
        if (paint->toolbar->tool_buttons)
            free(paint->toolbar->tool_buttons);
        free(paint->toolbar);
    }
    
    // Free palette
    if (paint->palette) {
        if (paint->palette->colors)
            free(paint->palette->colors);
        free(paint->palette);
    }
    
    // Free current tool
    if (paint->current_tool)
        free(paint->current_tool);
    
    // Free drawings
    free_drawings(paint);
    
    // Free main structure
    free(paint);
}
