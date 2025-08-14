/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** render.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <stdio.h>

// Define missing constants
#define WINDOW_BACKGROUND_COLOR sfColor_fromRGB(240, 240, 240)
#define MENU_NORMAL_COLOR sfColor_fromRGB(220, 220, 220)
#define MENU_HOVER_COLOR sfColor_fromRGB(200, 200, 200)

static void render_menu_item(sfRenderWindow *window, menu_item_t *item, sfFont *font)
{
    if (!item || !window || !item->text)
        return;
    
    // TODO: Implement menu item rendering with new structure
    // For now, just render the text if it exists
    (void)font; // Suppress unused parameter warning
}

static void render_menu(sfRenderWindow *window, menu_t *menu, sfFont *font)
{
    if (!menu || !window)
        return;
    
    // TODO: Implement menu rendering with new structure
    // For now, just a placeholder
    (void)font; // Suppress unused parameter warning
}

void render_menu_bar(all_object_t *paint)
{
    if (!paint || !paint->menu_bar || !paint->window)
        return;
    
    // TODO: Implement menu bar rendering with new structure
    // For now, just a placeholder
}

static void render_button(sfRenderWindow *window, button_t *button, sfFont *font, int is_selected)
{
    sfColor color;
    
    if (is_selected) {
        color = button->pressed_color;
    } else if (button->is_hovered) {
        color = button->hover_color;
    } else {
        color = button->normal_color;
    }
    
    sfRectangleShape_setFillColor(button->shape, color);
    sfRenderWindow_drawRectangleShape(window, button->shape, NULL);
    
    if (font) {
        sfText_setFont(button->text, font);
    }
    sfRenderWindow_drawText(window, button->text, NULL);
}

void render_toolbar(all_object_t *paint)
{
    if (!paint || !paint->toolbar || !paint->window)
        return;
    
    toolbar_t *toolbar = paint->toolbar;
    
    // Render toolbar background
    if (toolbar->background)
        sfRenderWindow_drawRectangleShape(paint->window, toolbar->background, NULL);
    
    // Render tool buttons
    if (toolbar->tool_buttons) {
        for (int i = 0; i < toolbar->num_tools; i++) {
            if (toolbar->tool_buttons[i]) {
                int is_selected = (i == toolbar->selected_tool);
                render_button(paint->window, toolbar->tool_buttons[i], paint->font, is_selected);
            }
        }
    }
    
    // Render size control buttons
    if (toolbar->size_plus_button) {
        render_button(paint->window, toolbar->size_plus_button, paint->font, 0);
    }
    if (toolbar->size_minus_button) {
        render_button(paint->window, toolbar->size_minus_button, paint->font, 0);
    }
    
    // Render file operation buttons
    if (toolbar->save_button) {
        render_button(paint->window, toolbar->save_button, paint->font, 0);
    }
    if (toolbar->save_as_button) {
        render_button(paint->window, toolbar->save_as_button, paint->font, 0);
    }
    if (toolbar->open_button) {
        render_button(paint->window, toolbar->open_button, paint->font, 0);
    }
    if (toolbar->new_button) {
        render_button(paint->window, toolbar->new_button, paint->font, 0);
    }
    
    // Render size text if available
    if (toolbar->size_text && paint->font) {
        char size_str[32];
        snprintf(size_str, sizeof(size_str), "Size: %d", toolbar->current_size);
        
        sfText_setFont(toolbar->size_text, paint->font);
        sfText_setString(toolbar->size_text, size_str);
        sfText_setCharacterSize(toolbar->size_text, 12);
        sfText_setColor(toolbar->size_text, sfBlack);
        sfText_setPosition(toolbar->size_text, VECTOR2F(toolbar->position.x + 10, toolbar->position.y + toolbar->size.y - 30));
        sfRenderWindow_drawText(paint->window, toolbar->size_text, NULL);
    }
}

void render_color_palette(all_object_t *paint)
{
    if (!paint || !paint->palette || !paint->window)
        return;
    
    color_palette_t *palette = paint->palette;
    
    // Render palette background
    if (palette->background)
        sfRenderWindow_drawRectangleShape(paint->window, palette->background, NULL);
    
    // Render color squares
    if (palette->color_squares) {
        for (int i = 0; i < palette->num_colors; i++) {
            if (palette->color_squares[i]) {
                // Highlight selected color with thicker border
                if (i == palette->selected_color) {
                    sfRectangleShape_setOutlineThickness(palette->color_squares[i], 3);
                    sfRectangleShape_setOutlineColor(palette->color_squares[i], sfRed);
                } else {
                    sfRectangleShape_setOutlineThickness(palette->color_squares[i], 1);
                    sfRectangleShape_setOutlineColor(palette->color_squares[i], sfBlack);
                }
                sfRenderWindow_drawRectangleShape(paint->window, palette->color_squares[i], NULL);
            }
        }
    }
}

void render_canvas(all_object_t *paint)
{
    if (!paint || !paint->canvas || !paint->window)
        return;
    
    // Get the texture from the render texture
    const sfTexture *texture = sfRenderTexture_getTexture(paint->canvas->texture);
    if (!texture)
        return;
    
    // Create a sprite to display the canvas
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, VECTOR2F(paint->canvas->position.x, paint->canvas->position.y));
    
    // Draw the canvas
    sfRenderWindow_drawSprite(paint->window, sprite, NULL);
    
    sfSprite_destroy(sprite);
}

void render_help_dialog(sfRenderWindow *window, sfFont *font)
{
    if (!font)
        return;
    
    // Create semi-transparent overlay
    sfRectangleShape *overlay = sfRectangleShape_create();
    if (!overlay)
        return;
    
    sfRectangleShape_setSize(overlay, VECTOR2F(WINDOW_WIDTH, WINDOW_HEIGHT));
    sfRectangleShape_setPosition(overlay, VECTOR2F(0, 0));
    sfRectangleShape_setFillColor(overlay, (sfColor){0, 0, 0, 128});
    
    sfRenderWindow_drawRectangleShape(window, overlay, NULL);
    sfRectangleShape_destroy(overlay);
    
    // Create help dialog box
    sfRectangleShape *dialog = sfRectangleShape_create();
    if (!dialog)
        return;
    
    int dialog_width = 400;
    int dialog_height = 300;
    int dialog_x = (WINDOW_WIDTH - dialog_width) / 2;
    int dialog_y = (WINDOW_HEIGHT - dialog_height) / 2;
    
    sfRectangleShape_setSize(dialog, VECTOR2F(dialog_width, dialog_height));
    sfRectangleShape_setPosition(dialog, VECTOR2F(dialog_x, dialog_y));
    sfRectangleShape_setFillColor(dialog, sfWhite);
    sfRectangleShape_setOutlineThickness(dialog, 2);
    sfRectangleShape_setOutlineColor(dialog, sfBlack);
    
    sfRenderWindow_drawRectangleShape(window, dialog, NULL);
    sfRectangleShape_destroy(dialog);
    
    // Create help text
    sfText *help_text = sfText_create();
    if (help_text) {
        sfText_setFont(help_text, font);
        sfText_setString(help_text, HELP_TEXT);
        sfText_setCharacterSize(help_text, 14);
        sfText_setColor(help_text, sfBlack);
        sfText_setPosition(help_text, VECTOR2F(dialog_x + 20, dialog_y + 20));
        
        sfRenderWindow_drawText(window, help_text, NULL);
        sfText_destroy(help_text);
    }
}

void render_about_dialog(sfRenderWindow *window, sfFont *font)
{
    if (!font)
        return;
    
    // Create semi-transparent overlay
    sfRectangleShape *overlay = sfRectangleShape_create();
    if (!overlay)
        return;
    
    sfRectangleShape_setSize(overlay, VECTOR2F(WINDOW_WIDTH, WINDOW_HEIGHT));
    sfRectangleShape_setPosition(overlay, VECTOR2F(0, 0));
    sfRectangleShape_setFillColor(overlay, (sfColor){0, 0, 0, 128});
    
    sfRenderWindow_drawRectangleShape(window, overlay, NULL);
    sfRectangleShape_destroy(overlay);
    
    // Create about dialog box
    sfRectangleShape *dialog = sfRectangleShape_create();
    if (!dialog)
        return;
    
    int dialog_width = 300;
    int dialog_height = 200;
    int dialog_x = (WINDOW_WIDTH - dialog_width) / 2;
    int dialog_y = (WINDOW_HEIGHT - dialog_height) / 2;
    
    sfRectangleShape_setSize(dialog, VECTOR2F(dialog_width, dialog_height));
    sfRectangleShape_setPosition(dialog, VECTOR2F(dialog_x, dialog_y));
    sfRectangleShape_setFillColor(dialog, sfWhite);
    sfRectangleShape_setOutlineThickness(dialog, 2);
    sfRectangleShape_setOutlineColor(dialog, sfBlack);
    
    sfRenderWindow_drawRectangleShape(window, dialog, NULL);
    sfRectangleShape_destroy(dialog);
    
    // Create about text
    sfText *about_text = sfText_create();
    if (about_text) {
        sfText_setFont(about_text, font);
        sfText_setString(about_text, ABOUT_TEXT);
        sfText_setCharacterSize(about_text, 14);
        sfText_setColor(about_text, sfBlack);
        sfText_setPosition(about_text, VECTOR2F(dialog_x + 20, dialog_y + 20));
        
        sfRenderWindow_drawText(window, about_text, NULL);
        sfText_destroy(about_text);
    }
}

void render_all(all_object_t *obj)
{
    if (!obj || !obj->window)
        return;
    
    sfRenderWindow_clear(obj->window, WINDOW_BACKGROUND_COLOR);
    
    // Render canvas first (background)
    if (obj->canvas)
        render_canvas(obj);
    
    // Render UI components
    if (obj->toolbar)
        render_toolbar(obj);
    
    if (obj->palette)
        render_color_palette(obj);
    
    if (obj->menu_bar)
        render_menu_bar(obj);
    
    // TODO: Render dialogs if needed
    // Help and about dialogs would be implemented here
    
    sfRenderWindow_display(obj->window);
}