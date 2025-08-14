/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** over.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"

// Define missing constants
#define PRESSED 1
#define HOVER 2
#define RELEASED 0

void mouse_over_button(button_t *button, sfVector2i mouse_pos)
{
    if (!button)
        return;
    
    // Check if mouse is over button
    if (mouse_pos.x >= button->position.x && 
        mouse_pos.x <= button->position.x + button->size.x &&
        mouse_pos.y >= button->position.y && 
        mouse_pos.y <= button->position.y + button->size.y) {
        if (!button->is_pressed)
            button->is_hovered = 1;
    } else {
        button->is_hovered = 0;
    }
}

// Legacy function for compatibility
void mouse_over(void *button, void *mouse)
{
    // TODO: Implement legacy mouse over functionality
    (void)button;
    (void)mouse;
}
