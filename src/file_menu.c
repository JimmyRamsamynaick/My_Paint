/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** file_menu.c
*/

#include "../my.h"
#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <string.h>

// Define missing constants
#define FILE_LEN 80
#define FILE_WID 30
#define FILE_OFFSET_LEN 10
#define FILE_OFFSET_WID 10
#define BUTTON_THICK 2
#define FILE_TEXT_LEN 15
#define FILE_STR "File"
#define FONT "assets/font.ttf"

sfRectangleShape *init_file_button_rect(void)
{
    sfVector2f size = { 0 };
    sfVector2f position = { 0 };
    sfRectangleShape *result = sfRectangleShape_create();

    size.x = FILE_LEN;
    size.y = FILE_WID;
    position.x = FILE_OFFSET_LEN;
    position.y = FILE_OFFSET_WID;
    sfRectangleShape_setSize(result, size);
    sfRectangleShape_setPosition(result, position);
    sfRectangleShape_setFillColor(result, sfWhite);
    sfRectangleShape_setOutlineThickness(result, BUTTON_THICK);
    sfRectangleShape_setOutlineColor(result, sfBlack);
    return result;
}

sfText *init_file_text(sfFont *font)
{
    sfVector2f position = { 0 };
    sfText *text = sfText_create();

    position.x = FILE_TEXT_LEN;
    position.y = FILE_TEXT_WID;
    sfText_setFont(text, font);
    sfText_setString(text, FILE_STR);
    sfText_setCharacterSize(text, 19);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, position);
    return text;
}

menu_item_t *init_file_menu(void)
{
    menu_item_t *result = malloc(sizeof(menu_item_t));
    
    if (!result)
        return NULL;
    
    result->text = strdup("File");
    
    return result;
}

void draw_file_menu(all_object_t *obj)
{
    if (!obj || !obj->window)
        return;
    
    // Draw file menu button
    sfRectangleShape *rect = init_file_button_rect();
    sfFont *font = sfFont_createFromFile(FONT);
    sfText *text = init_file_text(font);
    
    if (rect && text) {
        sfRenderWindow_drawRectangleShape(obj->window, rect, NULL);
        sfRenderWindow_drawText(obj->window, text, NULL);
    }
    
    // Cleanup
     if (rect) sfRectangleShape_destroy(rect);
     if (text) sfText_destroy(text);
     if (font) sfFont_destroy(font);
}
