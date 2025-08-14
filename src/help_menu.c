/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** help_menu.c
*/

#include "../my.h"
#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <string.h>

// Define missing constants
#define HELP_LEN 80
#define HELP_WID 30
#define HELP_OFFSET_LEN 170
#define HELP_OFFSET_WID 10
#define BUTTON_THICK 2
#define HELP_TEXT_LEN 175
#define HELP_STR "Help"
#define FONT "assets/font.ttf"

sfRectangleShape *init_help_button_rect(void)
{
    sfVector2f size = { 0 };
    sfVector2f position = { 0 };
    sfRectangleShape *result = sfRectangleShape_create();

    size.x = HELP_LEN;
    size.y = HELP_WID;
    position.x = HELP_OFFSET_LEN;
    position.y = HELP_OFFSET_WID;
    sfRectangleShape_setSize(result, size);
    sfRectangleShape_setPosition(result, position);
    sfRectangleShape_setFillColor(result, sfWhite);
    sfRectangleShape_setOutlineThickness(result, BUTTON_THICK);
    sfRectangleShape_setOutlineColor(result, sfBlack);
    return result;
}

sfText *init_help_text(void)
{
    sfVector2f position = { 0 };
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(FONT);

    position.x = HELP_TEXT_LEN;
    position.y = HELP_OFFSET_WID;
    sfText_setFont(text, font);
    sfText_setString(text, HELP_STR);
    sfText_setCharacterSize(text, 19);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, position);
    return text;
}

menu_item_t *init_help_menu(void)
{
    menu_item_t *result = malloc(sizeof(menu_item_t));
    
    if (!result)
        return NULL;
    
    result->text = strdup("Help");
    
    return result;
}

void draw_help_menu(all_object_t *obj)
{
    if (!obj || !obj->window)
        return;
    
    // Draw help menu button
    sfRectangleShape *rect = init_help_button_rect();
    sfText *text = init_help_text();
    
    if (rect && text) {
        sfRenderWindow_drawRectangleShape(obj->window, rect, NULL);
        sfRenderWindow_drawText(obj->window, text, NULL);
    }
    
    // Cleanup
    if (rect) sfRectangleShape_destroy(rect);
    if (text) sfText_destroy(text);
}
