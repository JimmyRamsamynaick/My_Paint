/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** init_toolbar.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"

static button_t *create_tool_button(int x, int y, const char *text)
{
    button_t *button = malloc(sizeof(button_t));
    
    if (!button)
        return NULL;
    
    // Set button properties
    button->position = VECTOR2I(x, y);
    button->size = VECTOR2I(BUTTON_WIDTH, BUTTON_HEIGHT);
    button->normal_color = BUTTON_NORMAL_COLOR;
    button->hover_color = BUTTON_HOVER_COLOR;
    button->pressed_color = BUTTON_PRESSED_COLOR;
    button->is_hovered = 0;
    button->is_pressed = 0;
    button->callback = NULL;
    
    // Create rectangle shape
    button->shape = sfRectangleShape_create();
    if (!button->shape) {
        free(button);
        return NULL;
    }
    
    sfRectangleShape_setSize(button->shape, VECTOR2F(BUTTON_WIDTH, BUTTON_HEIGHT));
    sfRectangleShape_setPosition(button->shape, VECTOR2F(x, y));
    sfRectangleShape_setFillColor(button->shape, button->normal_color);
    sfRectangleShape_setOutlineThickness(button->shape, 1);
    sfRectangleShape_setOutlineColor(button->shape, sfBlack);
    
    // Create text
    button->text = sfText_create();
    if (!button->text) {
        sfRectangleShape_destroy(button->shape);
        free(button);
        return NULL;
    }
    
    // Set text properties
    sfText_setString(button->text, text);
    sfText_setCharacterSize(button->text, 12);
    sfText_setColor(button->text, sfBlack);
    sfText_setPosition(button->text, VECTOR2F(x + 5, y + BUTTON_HEIGHT/2 - 6));
    
    return button;
}

static int init_tool_buttons(toolbar_t *toolbar)
{
    const char *tool_names[] = {"Pencil", "Brush", "Eraser", "Line", "Rectangle", "Circle", "Fill"};
    int y_offset = TOOLBAR_Y + 20;
    
    toolbar->num_tools = 7;
    toolbar->tool_buttons = malloc(sizeof(button_t*) * toolbar->num_tools);
    
    if (!toolbar->tool_buttons)
        return ERROR;
    
    for (int i = 0; i < toolbar->num_tools; i++) {
        toolbar->tool_buttons[i] = create_tool_button(
            TOOLBAR_X + 10, 
            y_offset + i * (BUTTON_HEIGHT + BUTTON_SPACING),
            tool_names[i]
        );
        
        if (!toolbar->tool_buttons[i]) {
            // Free previously allocated buttons
            for (int j = 0; j < i; j++) {
                sfRectangleShape_destroy(toolbar->tool_buttons[j]->shape);
                sfText_destroy(toolbar->tool_buttons[j]->text);
                free(toolbar->tool_buttons[j]);
            }
            free(toolbar->tool_buttons);
            return ERROR;
        }
    }
    
    toolbar->selected_tool = 0; // Default to pencil
    
    // Set the first button (pencil) as selected by default
    if (toolbar->tool_buttons[0]) {
        toolbar->tool_buttons[0]->is_pressed = 1;
    }
    
    return SUCCESS;
}

toolbar_t *init_toolbar(void)
{
    toolbar_t *toolbar = malloc(sizeof(toolbar_t));
    
    if (!toolbar)
        return NULL;
    
    // Set toolbar properties
    toolbar->position = VECTOR2I(TOOLBAR_X, TOOLBAR_Y);
    toolbar->size = VECTOR2I(TOOLBAR_WIDTH, TOOLBAR_HEIGHT);
    
    // Create background
    toolbar->background = sfRectangleShape_create();
    if (!toolbar->background) {
        free(toolbar);
        return NULL;
    }
    
    sfRectangleShape_setSize(toolbar->background, VECTOR2F(TOOLBAR_WIDTH, TOOLBAR_HEIGHT));
    sfRectangleShape_setPosition(toolbar->background, VECTOR2F(TOOLBAR_X, TOOLBAR_Y));
    sfRectangleShape_setFillColor(toolbar->background, TOOLBAR_BACKGROUND_COLOR);
    sfRectangleShape_setOutlineThickness(toolbar->background, 2);
    sfRectangleShape_setOutlineColor(toolbar->background, sfBlack);
    
    // Initialize tool buttons
    if (init_tool_buttons(toolbar) != SUCCESS) {
        sfRectangleShape_destroy(toolbar->background);
        free(toolbar);
        return NULL;
    }
    
    // Initialize size controls
    toolbar->current_size = DEFAULT_BRUSH_SIZE;
    
    // Create size plus button
    toolbar->size_plus_button = create_tool_button(
        TOOLBAR_X + 10, 
        TOOLBAR_Y + TOOLBAR_HEIGHT - 120,
        "+"
    );
    if (!toolbar->size_plus_button) {
        cleanup_toolbar(toolbar);
        return NULL;
    }
    
    // Create size minus button
    toolbar->size_minus_button = create_tool_button(
        TOOLBAR_X + 90, 
        TOOLBAR_Y + TOOLBAR_HEIGHT - 120,
        "-"
    );
    if (!toolbar->size_minus_button) {
        cleanup_toolbar(toolbar);
        return NULL;
    }
    
    // Create file operation buttons
    toolbar->save_button = create_tool_button(
        TOOLBAR_X + 10,
        TOOLBAR_Y + TOOLBAR_HEIGHT - 90,
        "Save"
    );
    if (!toolbar->save_button) {
        // Cleanup and return error
        cleanup_toolbar(toolbar);
        return NULL;
    }
    
    toolbar->save_as_button = create_tool_button(
        TOOLBAR_X + 90,
        TOOLBAR_Y + TOOLBAR_HEIGHT - 90,
        "Save As"
    );
    if (!toolbar->save_as_button) {
        cleanup_toolbar(toolbar);
        return NULL;
    }
    
    toolbar->open_button = create_tool_button(
        TOOLBAR_X + 10,
        TOOLBAR_Y + TOOLBAR_HEIGHT - 60,
        "Open"
    );
    if (!toolbar->open_button) {
        cleanup_toolbar(toolbar);
        return NULL;
    }
    
    toolbar->new_button = create_tool_button(
        TOOLBAR_X + 90,
        TOOLBAR_Y + TOOLBAR_HEIGHT - 60,
        "New"
    );
    if (!toolbar->new_button) {
        cleanup_toolbar(toolbar);
        return NULL;
    }
    
    // Create size text
    toolbar->size_text = sfText_create();
    if (!toolbar->size_text) {
        cleanup_toolbar(toolbar);
        return NULL;
    }
    
    return toolbar;
}