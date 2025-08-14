/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** cleanup.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"

static void cleanup_button(button_t *button)
{
    if (!button)
        return;
    
    if (button->shape)
        sfRectangleShape_destroy(button->shape);
    if (button->text)
        sfText_destroy(button->text);
    
    free(button);
}

static void cleanup_menu_item(menu_item_t *item)
{
    if (!item)
        return;
    
    if (item->background)
        sfRectangleShape_destroy(item->background);
    if (item->sf_text)
        sfText_destroy(item->sf_text);
    if (item->text)
        free(item->text);
    
    free(item);
}

static void cleanup_menu(menu_t *menu)
{
    if (!menu)
        return;
    
    // Clean up title
    if (menu->title_text)
        sfText_destroy(menu->title_text);
    if (menu->title_background)
        sfRectangleShape_destroy(menu->title_background);
    if (menu->title)
        free(menu->title);
    
    // Clean up items (allocated as array, not linked list)
    if (menu->items) {
        for (int i = 0; i < menu->num_items; i++) {
            if (menu->items[i].text)
                free(menu->items[i].text);
            if (menu->items[i].background)
                sfRectangleShape_destroy(menu->items[i].background);
            if (menu->items[i].sf_text)
                sfText_destroy(menu->items[i].sf_text);
        }
        free(menu->items);
    }
    
    free(menu);
}

void cleanup_canvas(canvas_t *canvas)
{
    if (!canvas)
        return;
    
    if (canvas->texture)
        sfRenderTexture_destroy(canvas->texture);
    if (canvas->sprite)
        sfSprite_destroy(canvas->sprite);
    
    free(canvas);
}

void cleanup_toolbar(toolbar_t *toolbar)
{
    if (!toolbar)
        return;
    
    if (toolbar->background)
        sfRectangleShape_destroy(toolbar->background);
    
    if (toolbar->tool_buttons) {
        for (int i = 0; i < toolbar->num_tools; i++) {
            cleanup_button(toolbar->tool_buttons[i]);
        }
        free(toolbar->tool_buttons);
    }
    
    if (toolbar->size_plus_button)
        cleanup_button(toolbar->size_plus_button);
    
    if (toolbar->size_minus_button)
        cleanup_button(toolbar->size_minus_button);
    
    if (toolbar->save_button)
        cleanup_button(toolbar->save_button);
    
    if (toolbar->save_as_button)
        cleanup_button(toolbar->save_as_button);
    
    if (toolbar->open_button)
        cleanup_button(toolbar->open_button);
    
    if (toolbar->new_button)
        cleanup_button(toolbar->new_button);
    
    if (toolbar->size_text)
        sfText_destroy(toolbar->size_text);
    
    free(toolbar);
}

void cleanup_color_palette(color_palette_t *palette)
{
    if (!palette)
        return;
    
    if (palette->background)
        sfRectangleShape_destroy(palette->background);
    
    if (palette->color_squares) {
        for (int i = 0; i < palette->num_colors; i++) {
            if (palette->color_squares[i])
                sfRectangleShape_destroy(palette->color_squares[i]);
        }
        free(palette->color_squares);
    }
    
    if (palette->colors)
        free(palette->colors);
    
    free(palette);
}

void cleanup_menu_bar(menu_bar_t *menu_bar)
{
    if (!menu_bar)
        return;
    
    if (menu_bar->background)
        sfRectangleShape_destroy(menu_bar->background);
    
    if (menu_bar->menus) {
        for (int i = 0; i < menu_bar->num_menus; i++) {
            cleanup_menu(menu_bar->menus[i]);
        }
        free(menu_bar->menus);
    }
    
    free(menu_bar);
}

void cleanup_file_dialog(file_dialog_t *dialog)
{
    if (!dialog)
        return;
    
    if (dialog->title)
        sfText_destroy(dialog->title);
    if (dialog->filename_text)
        sfText_destroy(dialog->filename_text);
    cleanup_button(dialog->ok_button);
    cleanup_button(dialog->cancel_button);
    if (dialog->filename)
        free(dialog->filename);
    
    free(dialog);
}

void cleanup_history(history_t *history)
{
    if (!history)
        return;
    
    undo_state_t *current = history->head;
    while (current) {
        undo_state_t *next = current->next;
        if (current->canvas_state)
            sfImage_destroy(current->canvas_state);
        free(current);
        current = next;
    }
    
    free(history);
}

void cleanup_all(all_object_t *obj)
{
    if (!obj)
        return;
    
    // Clean up SFML objects first
    if (obj->window) {
        sfRenderWindow_destroy(obj->window);
        obj->window = NULL;
    }
    if (obj->font) {
        sfFont_destroy(obj->font);
        obj->font = NULL;
    }
    if (obj->clock) {
        sfClock_destroy(obj->clock);
        obj->clock = NULL;
    }
    
    // Clean up main components
    if (obj->canvas) {
        cleanup_canvas(obj->canvas);
        obj->canvas = NULL;
    }
    if (obj->toolbar) {
        cleanup_toolbar(obj->toolbar);
        obj->toolbar = NULL;
    }
    if (obj->palette) {
        cleanup_color_palette(obj->palette);
        obj->palette = NULL;
    }
    if (obj->menu_bar) {
        cleanup_menu_bar(obj->menu_bar);
        obj->menu_bar = NULL;
    }
    if (obj->file_dialog) {
        cleanup_file_dialog(obj->file_dialog);
        obj->file_dialog = NULL;
    }
    if (obj->history) {
        cleanup_history(obj->history);
        obj->history = NULL;
    }

    // Clean up current tool
    if (obj->current_tool) {
        free(obj->current_tool);
        obj->current_tool = NULL;
    }

    // Clean up strings
    if (obj->current_filename) {
        free(obj->current_filename);
        obj->current_filename = NULL;
    }
    
    // Free main structure
    free(obj);
}