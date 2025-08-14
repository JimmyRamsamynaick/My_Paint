#include "include/my_paint.h"
#include "include/struct.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Testing menu_bar initialization and cleanup...\n");
    
    // Test menu_bar initialization
    menu_bar_t *menu_bar = init_menu_bar();
    if (!menu_bar) {
        printf("Failed to initialize menu_bar\n");
        return 1;
    }
    
    printf("menu_bar initialized successfully\n");
    printf("menu_bar->num_menus: %d\n", menu_bar->num_menus);
    printf("menu_bar->menus: %p\n", (void*)menu_bar->menus);
    
    // Check each menu pointer
    for (int i = 0; i < menu_bar->num_menus; i++) {
        printf("menu_bar->menus[%d]: %p\n", i, (void*)menu_bar->menus[i]);
        if (menu_bar->menus[i]) {
            printf("  title: %s\n", menu_bar->menus[i]->title ? menu_bar->menus[i]->title : "NULL");
            printf("  num_items: %d\n", menu_bar->menus[i]->num_items);
            printf("  items: %p\n", (void*)menu_bar->menus[i]->items);
        }
    }
    
    printf("Testing menu_bar cleanup...\n");
    cleanup_menu_bar(menu_bar);
    printf("menu_bar cleanup completed successfully\n");
    
    return 0;
}