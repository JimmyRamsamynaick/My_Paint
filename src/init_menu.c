/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** init_menu.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <string.h>
#include <stdlib.h>

// Define missing constants
#define MENU_BAR_COLOR sfColor_fromRGB(240, 240, 240)
#define MENU_ITEM_WIDTH 100
#define MENU_ITEM_HEIGHT 30

static menu_item_t *create_menu_item(const char *text, int x, int y)
{
    menu_item_t *item = malloc(sizeof(menu_item_t));
    
    if (!item)
        return NULL;
    
    // Initialize menu item with text only
    item->text = strdup(text);
    if (!item->text) {
        free(item);
        return NULL;
    }
    
    return item;
}

static menu_t *create_menu(const char *title, int x, int y, const char **items, int num_items)
{
    menu_t *menu = malloc(sizeof(menu_t));
    
    if (!menu)
        return NULL;
    
    menu->is_open = 0;
    menu->num_items = num_items;
    
    // Initialize title fields
    menu->title_text = NULL;
    menu->title_background = NULL;
    
    // Create title
    menu->title = strdup(title);
    if (!menu->title) {
        free(menu);
        return NULL;
    }
    
    // Create dropdown items
    menu->items = malloc(sizeof(menu_item_t) * num_items);
    if (!menu->items) {
        free(menu->title);
        free(menu);
        return NULL;
    }
    
    for (int i = 0; i < num_items; i++) {
        menu->items[i].text = strdup(items[i]);
        if (!menu->items[i].text) {
            // Free previously allocated items
            for (int j = 0; j < i; j++) {
                free(menu->items[j].text);
            }
            free(menu->items);
            free(menu->title);
            free(menu);
            return NULL;
        }
        // Initialize other fields to NULL
        menu->items[i].sf_text = NULL;
        menu->items[i].background = NULL;
        menu->items[i].callback = NULL;
        menu->items[i].next = NULL;
    }
    
    return menu;
}

menu_bar_t *init_menu_bar(void)
{
    menu_bar_t *menu_bar = malloc(sizeof(menu_bar_t));
    
    if (!menu_bar)
        return NULL;
    
    menu_bar->position = VECTOR2I(0, 0);
    menu_bar->size = VECTOR2I(WINDOW_WIDTH, MENU_BAR_HEIGHT);
    menu_bar->num_menus = 3;
    
    // Create background
    menu_bar->background = sfRectangleShape_create();
    if (!menu_bar->background) {
        free(menu_bar);
        return NULL;
    }
    
    sfRectangleShape_setSize(menu_bar->background, VECTOR2F(WINDOW_WIDTH, MENU_BAR_HEIGHT));
    sfRectangleShape_setPosition(menu_bar->background, VECTOR2F(0, 0));
    sfRectangleShape_setFillColor(menu_bar->background, MENU_BAR_COLOR);
    sfRectangleShape_setOutlineThickness(menu_bar->background, 1);
    sfRectangleShape_setOutlineColor(menu_bar->background, sfBlack);
    
    // Allocate menus array
    menu_bar->menus = malloc(sizeof(menu_t*) * menu_bar->num_menus);
    if (!menu_bar->menus) {
        sfRectangleShape_destroy(menu_bar->background);
        free(menu_bar);
        return NULL;
    }
    
    // Create File menu
    const char *file_items[] = {"New", "Open", "Save", "Save As", "Exit"};
    menu_bar->menus[0] = create_menu("File", 0, 0, file_items, 5);
    
    // Create Edit menu
    const char *edit_items[] = {"Undo", "Redo", "Clear"};
    menu_bar->menus[1] = create_menu("Edit", MENU_ITEM_WIDTH, 0, edit_items, 3);
    
    // Create Help menu
    const char *help_items[] = {"About"};
    menu_bar->menus[2] = create_menu("Help", MENU_ITEM_WIDTH * 2, 0, help_items, 1);
    
    // Check if all menus were created successfully
    for (int i = 0; i < menu_bar->num_menus; i++) {
        if (!menu_bar->menus[i]) {
            // Free previously allocated menus
            for (int j = 0; j < i; j++) {
                // Free menu items
                for (int k = 0; k < menu_bar->menus[j]->num_items; k++) {
                    if (menu_bar->menus[j]->items[k].text)
                        free(menu_bar->menus[j]->items[k].text);
                }
                free(menu_bar->menus[j]->items);
                if (menu_bar->menus[j]->title)
                    free(menu_bar->menus[j]->title);
                free(menu_bar->menus[j]);
            }
            free(menu_bar->menus);
            sfRectangleShape_destroy(menu_bar->background);
            free(menu_bar);
            return NULL;
        }
    }
    
    return menu_bar;
}