#include "include/my_paint.h"
#include "include/struct.h"
#include "include/all_macros.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Testing individual component initialization...\n");
    
    // Test window initialization
    printf("1. Testing window initialization...\n");
    sfRenderWindow *window = init_window();
    if (!window) {
        printf("Window initialization failed\n");
        return 1;
    }
    printf("Window: OK\n");
    
    // Test canvas initialization
    printf("2. Testing canvas initialization...\n");
    canvas_t *canvas = init_canvas();
    if (!canvas) {
        printf("Canvas initialization failed\n");
        sfRenderWindow_destroy(window);
        return 1;
    }
    printf("Canvas: OK\n");
    
    // Test toolbar initialization
    printf("3. Testing toolbar initialization...\n");
    toolbar_t *toolbar = init_toolbar();
    if (!toolbar) {
        printf("Toolbar initialization failed\n");
        cleanup_canvas(canvas);
        sfRenderWindow_destroy(window);
        return 1;
    }
    printf("Toolbar: OK\n");
    
    // Test cleanup
    printf("4. Testing cleanup...\n");
    cleanup_toolbar(toolbar);
    cleanup_canvas(canvas);
    sfRenderWindow_destroy(window);
    printf("Cleanup: OK\n");
    
    printf("All individual tests passed!\n");
    return 0;
}