#include "include/my_paint.h"
#include "include/struct.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Testing individual components...\n");
    
    // Test canvas
    printf("\nTesting canvas...\n");
    canvas_t *canvas = init_canvas();
    if (canvas) {
        printf("Canvas initialized successfully\n");
        cleanup_canvas(canvas);
        printf("Canvas cleanup completed\n");
    } else {
        printf("Canvas initialization failed\n");
    }
    
    // Test toolbar
    printf("\nTesting toolbar...\n");
    toolbar_t *toolbar = init_toolbar();
    if (toolbar) {
        printf("Toolbar initialized successfully\n");
        cleanup_toolbar(toolbar);
        printf("Toolbar cleanup completed\n");
    } else {
        printf("Toolbar initialization failed\n");
    }
    
    // Test color palette
    printf("\nTesting color palette...\n");
    color_palette_t *palette = init_color_palette();
    if (palette) {
        printf("Color palette initialized successfully\n");
        cleanup_color_palette(palette);
        printf("Color palette cleanup completed\n");
    } else {
        printf("Color palette initialization failed\n");
    }
    
    // Test history
    printf("\nTesting history...\n");
    history_t *history = init_history();
    if (history) {
        printf("History initialized successfully\n");
        cleanup_history(history);
        printf("History cleanup completed\n");
    } else {
        printf("History initialization failed\n");
    }
    
    // Test current tool (via malloc/free since init_tool is static)
    printf("\nTesting current tool...\n");
    tool_t *tool = malloc(sizeof(tool_t));
    if (tool) {
        printf("Tool allocated successfully\n");
        free(tool);
        printf("Tool cleanup completed\n");
    } else {
        printf("Tool allocation failed\n");
    }
    
    printf("\nAll individual component tests completed\n");
    return 0;
}