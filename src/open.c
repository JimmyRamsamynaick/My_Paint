/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** open.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <stdlib.h>

// Define missing constants
#define OPEN_LEN 100
#define OPEN_WID 30
#define OPEN_OFFSET_LEN 10
#define OPEN_OFFSET_WID 50
#define BUTTON_THICK 2
#define OPEN_TEXT_WID 10
#define FONT "assets/fonts/arial.ttf"
#define NONE 0

// Forward declarations
extern void button_clicked(button_t *button, sfMouseButtonEvent *mouse);
extern void mouse_over(button_t *button, sfVector2i mouse_pos);

sfRectangleShape *init_open_file_button_rect(void)
{
    sfVector2f size = { 0 };
    sfRectangleShape *result = sfRectangleShape_create();
    sfVector2f position = { 0 };

    size.x = OPEN_LEN;
    size.y = OPEN_WID;
    position.x = OPEN_OFFSET_LEN;
    position.y = OPEN_OFFSET_WID + 62;
    sfRectangleShape_setSize(result, size);
    sfRectangleShape_setPosition(result, position);
    sfRectangleShape_setFillColor(result, sfWhite);
    sfRectangleShape_setOutlineThickness(result, BUTTON_THICK);
    sfRectangleShape_setOutlineColor(result, sfBlack);
    return result;
}

sfText *init_open_file_text(sfFont *font)
{
    sfVector2f position = { 0 };
    sfText *text = sfText_create();

    position.x = 10;
    position.y = FILE_TEXT_WID + 62;
    sfText_setFont(text, font);
    sfText_setString(text, "Open file");
    sfText_setCharacterSize(text, 19);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, position);
    return text;
}

button_t *init_open_file_option(void)
{
    button_t *option = malloc(sizeof(button_t));
    
    if (!option)
        return NULL;
    
    option->position = VECTOR2I(OPEN_OFFSET_LEN, OPEN_OFFSET_WID + 31);
    option->size = VECTOR2I(OPEN_LEN, OPEN_WID);
    option->is_pressed = 0;
    option->is_hovered = 0;
    
    return option;
}

// Helper functions are now defined in click.c and over.c
