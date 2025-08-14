#include "include/my_paint.h"
#include "include/struct.h"
#include "include/all_macros.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Testing cleanup_all step by step...\n");
    fflush(stdout);
    
    all_object_t *paint = init_all_obj();
    if (!paint) {
        printf("init_all_obj failed\n");
        return 1;
    }
    
    printf("init_all_obj successful, now testing cleanup components individually...\n");
    fflush(stdout);
    
    // Test cleanup of each component individually
    printf("Testing cleanup_canvas...\n");
    fflush(stdout);
    if (paint->canvas) {
        cleanup_canvas(paint->canvas);
        paint->canvas = NULL;
        printf("cleanup_canvas OK\n");
    }
    
    printf("Testing cleanup_toolbar...\n");
    fflush(stdout);
    if (paint->toolbar) {
        cleanup_toolbar(paint->toolbar);
        paint->toolbar = NULL;
        printf("cleanup_toolbar OK\n");
    }
    
    printf("Testing cleanup_color_palette...\n");
    fflush(stdout);
    if (paint->palette) {
        cleanup_color_palette(paint->palette);
        paint->palette = NULL;
        printf("cleanup_color_palette OK\n");
    }
    
    printf("Testing cleanup_menu_bar...\n");
    fflush(stdout);
    if (paint->menu_bar) {
        cleanup_menu_bar(paint->menu_bar);
        paint->menu_bar = NULL;
        printf("cleanup_menu_bar OK\n");
    }
    
    printf("Testing cleanup_history...\n");
    fflush(stdout);
    if (paint->history) {
        cleanup_history(paint->history);
        paint->history = NULL;
        printf("cleanup_history OK\n");
    }
    
    printf("Testing current_tool cleanup...\n");
    fflush(stdout);
    if (paint->current_tool) {
        free(paint->current_tool);
        paint->current_tool = NULL;
        printf("current_tool cleanup OK\n");
    }
    
    printf("Testing SFML objects cleanup...\n");
    fflush(stdout);
    if (paint->window) {
        sfRenderWindow_destroy(paint->window);
        paint->window = NULL;
        printf("window cleanup OK\n");
    }
    if (paint->font) {
        sfFont_destroy(paint->font);
        paint->font = NULL;
        printf("font cleanup OK\n");
    }
    if (paint->clock) {
        sfClock_destroy(paint->clock);
        paint->clock = NULL;
        printf("clock cleanup OK\n");
    }
    
    printf("Testing main structure cleanup...\n");
    fflush(stdout);
    free(paint);
    printf("All cleanup tests passed!\n");
    fflush(stdout);
    
    return 0;
}