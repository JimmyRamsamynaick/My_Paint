#include "include/struct.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Testing simple malloc/free...\n");
    
    all_object_t *paint = malloc(sizeof(all_object_t));
    if (!paint) {
        printf("malloc failed\n");
        return 1;
    }
    
    printf("malloc successful, paint=%p\n", (void*)paint);
    printf("sizeof(all_object_t)=%zu\n", sizeof(all_object_t));
    
    // Initialize all pointers to NULL
    paint->window = NULL;
    paint->font = NULL;
    paint->clock = NULL;
    paint->canvas = NULL;
    paint->toolbar = NULL;
    paint->palette = NULL;
    paint->menu_bar = NULL;
    paint->current_tool = NULL;
    paint->history = NULL;
    paint->file_dialog = NULL;
    paint->current_filename = NULL;
    
    printf("About to free...\n");
    free(paint);
    printf("free successful\n");
    
    return 0;
}