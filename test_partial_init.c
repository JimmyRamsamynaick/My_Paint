#include "include/my_paint.h"
#include "include/struct.h"
#include "include/all_macros.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Testing partial initialization scenario...\n");
    
    // Simulate what happens in init_all_obj when one component fails
    all_object_t *paint = malloc(sizeof(all_object_t));
    if (!paint) {
        printf("Failed to allocate main structure\n");
        return 1;
    }
    
    // Initialize basic components (like in init_basic_components)
    paint->clock = sfClock_create();
    paint->current_filename = NULL;
    paint->file_dialog = NULL;
    paint->show_help = 0;
    paint->font = NULL; // Simulate font loading failure
    
    // Initialize window
    paint->window = init_window();
    if (!paint->window) {
        printf("Window initialization failed\n");
        free(paint);
        return 1;
    }
    
    // Initialize some components successfully
    paint->canvas = init_canvas();
    paint->toolbar = init_toolbar();
    paint->palette = init_color_palette();
    paint->menu_bar = init_menu_bar();
    
    // Simulate failure of current_tool initialization
    paint->current_tool = NULL;
    paint->history = NULL;
    
    printf("Partial initialization complete, now testing cleanup_all...\n");
    
    // This should reproduce the bug
    cleanup_all(paint);
    
    printf("cleanup_all completed successfully\n");
    return 0;
}