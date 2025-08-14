/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** menu_actions.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Define missing constants
#define APP_EXITING 1

// Helper function to duplicate strings
char *my_strdup(const char *str)
{
    if (!str)
        return NULL;
    
    size_t len = strlen(str) + 1;
    char *dup = malloc(len);
    if (dup) {
        memcpy(dup, str, len);
    }
    return dup;
}

// Forward declaration
void save_file_as(all_object_t *obj, const char *filename);

void new_file(all_object_t *obj)
{
    if (!obj || !obj->canvas)
        return;
    
    // Save current state before clearing
    save_canvas_state(obj);
    
    // Clear the canvas
    sfRenderTexture_clear(obj->canvas->texture, obj->canvas->background_color);
    sfRenderTexture_display(obj->canvas->texture);
    
    // Reset canvas state
    obj->canvas->modified = 0;
    
    // Reset current filename
    if (obj->current_filename) {
        free(obj->current_filename);
        obj->current_filename = NULL;
    }
    
    printf("New file created - canvas cleared\n");
}

void open_file(all_object_t *obj, const char *filename)
{
    if (!obj || !obj->canvas)
        return;
    
    // If no filename provided, use a default test file
    const char *file_to_open = filename ? filename : "test_image.png";
    
    // Load image from file
    sfImage *image = sfImage_createFromFile(file_to_open);
    if (!image) {
        printf("Failed to load image: %s\n", file_to_open);
        printf("Note: You can place an image file named 'test_image.png' in the project directory to test the open functionality.\n");
        return;
    }
    
    // Get image dimensions
    sfVector2u image_size = sfImage_getSize(image);
    
    // Create texture from image
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    if (!texture) {
        printf("Failed to create texture from image: %s\n", filename);
        sfImage_destroy(image);
        return;
    }
    
    // Create sprite from texture
    sfSprite *sprite = sfSprite_create();
    if (!sprite) {
        printf("Failed to create sprite\n");
        sfTexture_destroy(texture);
        sfImage_destroy(image);
        return;
    }
    
    sfSprite_setTexture(sprite, texture, sfTrue);
    
    // Scale sprite to fit canvas if necessary
    float scale_x = (float)obj->canvas->size.x / image_size.x;
    float scale_y = (float)obj->canvas->size.y / image_size.y;
    float scale = (scale_x < scale_y) ? scale_x : scale_y;
    
    if (scale < 1.0f) {
        sfSprite_setScale(sprite, (sfVector2f){scale, scale});
    }
    
    // Clear canvas and draw the loaded image
    sfRenderTexture_clear(obj->canvas->texture, obj->canvas->background_color);
    sfRenderTexture_drawSprite(obj->canvas->texture, sprite, NULL);
    sfRenderTexture_display(obj->canvas->texture);
    
    // Update current filename
    if (obj->current_filename) {
        free(obj->current_filename);
    }
    obj->current_filename = my_strdup(filename);
    obj->canvas->modified = 0;
    
    printf("File opened: %s\n", filename);
    
    // Cleanup
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfImage_destroy(image);
}

void save_file(all_object_t *obj, const char *filename)
{
    if (!obj || !obj->canvas)
        return;
    
    const char *file_to_save = filename ? filename : 
                              (obj->current_filename ? obj->current_filename : "untitled.png");
    
    save_file_as(obj, file_to_save);
}

void save_file_as(all_object_t *obj, const char *filename)
{
    if (!obj || !obj->canvas || !filename)
        return;
    
    // Get the texture from the canvas
    const sfTexture *texture = sfRenderTexture_getTexture(obj->canvas->texture);
    if (!texture)
        return;
    
    // Create an image from the texture
    sfImage *image = sfTexture_copyToImage(texture);
    if (!image)
        return;
    
    // Save the image
    if (sfImage_saveToFile(image, filename)) {
        // Update current filename
        if (obj->current_filename) {
            free(obj->current_filename);
        }
        obj->current_filename = my_strdup(filename);
        obj->canvas->modified = 0;
        printf("File saved as: %s\n", filename);
    } else {
        printf("Failed to save file: %s\n", filename);
    }
    
    sfImage_destroy(image);
}

// History management functions
history_t *init_history(void)
{
    history_t *history = malloc(sizeof(history_t));
    if (!history)
        return NULL;
    
    history->current = NULL;
    history->head = NULL;
    history->max_states = 20; // Limit to 20 undo states
    history->current_states = 0;
    
    return history;
}

void save_canvas_state(all_object_t *obj)
{
    if (!obj || !obj->canvas || !obj->history)
        return;
    
    // Get current canvas texture
    const sfTexture *texture = sfRenderTexture_getTexture(obj->canvas->texture);
    if (!texture)
        return;
    
    // Create image from texture
    sfImage *canvas_image = sfTexture_copyToImage(texture);
    if (!canvas_image)
        return;
    
    // Create new undo state
    undo_state_t *new_state = malloc(sizeof(undo_state_t));
    if (!new_state) {
        sfImage_destroy(canvas_image);
        return;
    }
    
    new_state->canvas_state = canvas_image;
    new_state->next = NULL;
    new_state->prev = obj->history->current;
    
    // If we have a current state, link it
    if (obj->history->current) {
        // Remove any states after current (for redo)
        undo_state_t *temp = obj->history->current->next;
        while (temp) {
            undo_state_t *next = temp->next;
            sfImage_destroy(temp->canvas_state);
            free(temp);
            obj->history->current_states--;
            temp = next;
        }
        obj->history->current->next = new_state;
    } else {
        obj->history->head = new_state;
    }
    
    obj->history->current = new_state;
    obj->history->current_states++;
    
    // Remove oldest states if we exceed max
    while (obj->history->current_states > obj->history->max_states) {
        undo_state_t *old_head = obj->history->head;
        obj->history->head = old_head->next;
        if (obj->history->head)
            obj->history->head->prev = NULL;
        
        sfImage_destroy(old_head->canvas_state);
        free(old_head);
        obj->history->current_states--;
    }
}

void undo_action(all_object_t *obj)
{
    if (!obj || !obj->history || !obj->history->current)
        return;
    
    undo_state_t *prev_state = obj->history->current->prev;
    if (!prev_state) {
        printf("Nothing to undo\n");
        return;
    }
    
    // Create texture from previous state
    sfTexture *texture = sfTexture_createFromImage(prev_state->canvas_state, NULL);
    if (!texture)
        return;
    
    // Clear current canvas and draw the previous state
    sfRenderTexture_clear(obj->canvas->texture, obj->canvas->background_color);
    
    // Create sprite from texture and draw it
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderTexture_drawSprite(obj->canvas->texture, sprite, NULL);
    sfRenderTexture_display(obj->canvas->texture);
    
    // Update current state
    obj->history->current = prev_state;
    
    // Cleanup
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    
    printf("Undo completed\n");
}

void redo_action(all_object_t *obj)
{
    if (!obj || !obj->history || !obj->history->current)
        return;
    
    undo_state_t *next_state = obj->history->current->next;
    if (!next_state) {
        printf("Nothing to redo\n");
        return;
    }
    
    // Create texture from next state
    sfTexture *texture = sfTexture_createFromImage(next_state->canvas_state, NULL);
    if (!texture)
        return;
    
    // Clear current canvas and draw the next state
    sfRenderTexture_clear(obj->canvas->texture, obj->canvas->background_color);
    
    // Create sprite from texture and draw it
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderTexture_drawSprite(obj->canvas->texture, sprite, NULL);
    sfRenderTexture_display(obj->canvas->texture);
    
    // Update current state
    obj->history->current = next_state;
    
    // Cleanup
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    
    printf("Redo completed\n");
}

void clear_canvas(all_object_t *obj)
{
    if (!obj || !obj->canvas)
        return;
    
    // Save current state before clearing
    save_canvas_state(obj);
    
    // Clear the canvas with background color
    sfRenderTexture_clear(obj->canvas->texture, obj->canvas->background_color);
    sfRenderTexture_display(obj->canvas->texture);
    
    obj->canvas->modified = 1;
}

void show_about(all_object_t *obj)
{
    if (!obj)
        return;
    
    // TODO: Show about dialog
    printf("About My Paint - A simple paint application\n");
}

void show_help(all_object_t *obj)
{
    if (!obj)
        return;
    
    // TODO: Show help dialog
    printf("Help: Use the tools to draw on the canvas\n");
}

void exit_application(all_object_t *obj)
{
    if (!obj)
        return;
    
    // TODO: Set exit flag or close window
    printf("Exiting application...\n");
    if (obj->window) {
        sfRenderWindow_close(obj->window);
    }
}

void handle_menu_action(all_object_t *obj, int menu_index, int item_index)
{
    if (!obj)
        return;
    
    switch (menu_index) {
        case 0: // File menu
            switch (item_index) {
                case 0: // New
                    new_file(obj);
                    break;
                case 1: // Open
                    open_file(obj, NULL);
                    break;
                case 2: // Save
                    save_file(obj, NULL);
                    break;
                case 3: // Save As
                    save_file_as(obj, "untitled.png");
                    break;
                case 4: // Exit
                    exit_application(obj);
                    break;
                default:
                    break;
            }
            break;
        case 1: // Edit menu
            switch (item_index) {
                case 0: // Undo
                    undo_action(obj);
                    break;
                case 1: // Redo
                    redo_action(obj);
                    break;
                case 2: // Clear
                    clear_canvas(obj);
                    break;
                default:
                    break;
            }
            break;
        case 2: // Help menu
            switch (item_index) {
                case 0: // About
                    show_about(obj);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}