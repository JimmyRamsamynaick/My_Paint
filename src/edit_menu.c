/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** edit_menu.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <string.h>

menu_item_t *init_edit_menu(void)
{
    menu_item_t *edit_menu = malloc(sizeof(menu_item_t));
    
    if (!edit_menu)
        return NULL;
    
    edit_menu->text = strdup("Edit");
    if (!edit_menu->text) {
        free(edit_menu);
        return NULL;
    }
    edit_menu->sf_text = NULL;
    edit_menu->background = NULL;
    edit_menu->callback = NULL;
    edit_menu->next = NULL;
    
    return edit_menu;
}

void draw_edit_menu(all_object_t *paint)
{
    if (!paint || !paint->menu_bar)
        return;
    
    // Draw edit menu implementation
    // This would be handled by the main menu rendering system
}

void draw_toolbar(all_object_t *paint)
{
    if (!paint || !paint->toolbar)
        return;
    
    // Draw toolbar implementation
    // This would be handled by the main toolbar rendering system
}
