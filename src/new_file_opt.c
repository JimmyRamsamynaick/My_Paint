/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** new_file_opt.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

// Define missing constants
#define FILE_LEN 100
#define FILE_WID 30
#define FILE_OFFSET_LEN 10
#define FILE_OFFSET_WID 10
#define BUTTON_THICK 2
// FILE_TEXT_WID is already defined in all_macros.h
#define FONT "assets/fonts/arial.ttf"
#define NONE 0

// Forward declarations
extern void button_clicked(button_t *button, sfMouseButtonEvent *mouse);
extern void mouse_over(button_t *button, sfVector2i mouse_pos);

sfText *init_new_file_text(sfFont *font)
{
    sfVector2f position = { 0 };
    sfText *text = sfText_create();

    position.x = 10;
    position.y = FILE_TEXT_WID + 31;
    sfText_setFont(text, font);
    sfText_setString(text, "New file");
    sfText_setCharacterSize(text, 19);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, position);
    return text;
}

sfRectangleShape *init_new_file_button_rect(void)
{
    sfVector2f size = { 0 };
    sfRectangleShape *result = sfRectangleShape_create();
    sfVector2f position = { 0 };

    size.x = FILE_LEN;
    size.y = FILE_WID;
    position.x = FILE_OFFSET_LEN;
    position.y = FILE_OFFSET_WID + 31;
    sfRectangleShape_setSize(result, size);
    sfRectangleShape_setPosition(result, position);
    sfRectangleShape_setFillColor(result, sfWhite);
    sfRectangleShape_setOutlineThickness(result, BUTTON_THICK);
    sfRectangleShape_setOutlineColor(result, sfBlack);
    return result;
}

button_t *init_new_file_options(void)
{
    button_t *option = malloc(sizeof(button_t));
    
    if (!option)
        return NULL;
    
    option->position = VECTOR2I(FILE_OFFSET_LEN, FILE_OFFSET_WID + 31);
    option->size = VECTOR2I(FILE_LEN, FILE_WID);
    option->is_pressed = 0;
    option->is_hovered = 0;
    
    return option;
}

// Helper functions are now defined in click.c and over.c
