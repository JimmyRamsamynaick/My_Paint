/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** my_paint.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <stdio.h>

static void main_loop(all_object_t *paint)
{
    while (paint->running && sfRenderWindow_isOpen(paint->window)) {
        handle_events(paint);
        
        // Render all components (includes clear and display)
        render_all(paint);
        
        // Update mouse position
        paint->last_mouse_pos = paint->mouse_pos;
        paint->mouse_pos = get_mouse_position(paint);
    }
}

int my_paint(void)
{
    all_object_t *paint = init_all_obj();
    
    if (!paint) {
        printf("Error: Failed to initialize application.\n");
        return FAILURE;
    }
    
    if (!paint->window) {
        printf("Error: Failed to create window.\n");
        cleanup_all(paint);
        return FAILURE;
    }
    
    // Set initial state
    paint->running = 1;
    paint->state = STATE_IDLE;
    paint->mouse_pos = VECTOR2I(0, 0);
    paint->last_mouse_pos = VECTOR2I(0, 0);
    
    // Main application loop
    main_loop(paint);
    
    // Cleanup
    cleanup_all(paint);
    return SUCCESS;
}
