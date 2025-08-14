#include "include/my_paint.h"
#include "include/struct.h"
#include "include/all_macros.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Testing init_all_obj...\n");
    
    all_object_t *paint = init_all_obj();
    if (!paint) {
        printf("init_all_obj failed - returned NULL\n");
        return 1;
    }
    
    printf("init_all_obj successful\n");
    printf("Testing cleanup_all...\n");
    
    cleanup_all(paint);
    
    printf("cleanup_all successful\n");
    printf("Test completed successfully!\n");
    
    return 0;
}