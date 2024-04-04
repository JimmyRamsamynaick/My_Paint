/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** events_analyse.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <stdlib.h>
#include <stdio.h>

void handle_cliks(all_object_t *paint, sfEvent event)
{
    paint->edit_menu->button->cliked(paint->edit_menu->button, MOUSE);
    paint->file_menu->button->cliked(paint->file_menu->button, MOUSE);
    paint->help_menu->button->cliked(paint->help_menu->button, MOUSE);
    paint->draw_zone->zone_is_cliked(paint->draw_zone, MOUSE);
    paint->eraser->zone_is_cliked(paint->eraser, MOUSE);
    paint->pencil->zone_is_cliked(paint->pencil, MOUSE);
}

void handle_mouse_movement(all_object_t *paint, sfMouseMoveEvent *mouse)
{
    paint->edit_menu->button->over(paint->edit_menu->button, mouse);
    paint->file_menu->button->over(paint->file_menu->button, mouse);
    paint->help_menu->button->over(paint->help_menu->button, mouse);
}

void analye_events(all_object_t *paint)
{
    sfEvent event = { 0 };

    while (sfRenderWindow_pollEvent(paint->window, &event)) {
        switch (event.type) {
            case sfEvtMouseMoved:
                handle_mouse_movement(paint, &event.mouseMove);
                break;
            case sfEvtClosed:
                sfRenderWindow_close(paint->window);
                break;
            case sfEvtMouseButtonPressed:
                handle_cliks(paint, event);
                break;
            case sfEvtMouseButtonReleased:
                paint->draw_zone->state = RELEASED;
                break;
            default:
                break;
        }
    }
}
