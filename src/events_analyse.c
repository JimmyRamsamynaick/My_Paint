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
    if (!paint)
        return;
    
    // Use the comprehensive mouse click handler from events.c
    handle_mouse_click(paint, &event.mouseButton);
}

// handle_mouse_movement is defined in events.c

void analye_events(all_object_t *paint)
{
    sfEvent event = { 0 };

    while (sfRenderWindow_pollEvent(paint->window, &event)) {
        switch (event.type) {
            case sfEvtMouseMoved:
                handle_mouse_move(paint, &event.mouseMove);
                break;
            case sfEvtClosed:
                sfRenderWindow_close(paint->window);
                break;
            case sfEvtMouseButtonPressed:
                if (event.mouseButton.button == sfMouseLeft) {
                    handle_mouse_click(paint, &event.mouseButton);
                }
                break;
            case sfEvtMouseButtonReleased:
                // Handle mouse button release
                if (paint->current_tool && paint->current_tool->is_drawing) {
                    paint->current_tool->is_drawing = 0;
                }
                break;
            default:
                break;
        }
    }
}
