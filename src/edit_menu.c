/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** edit_menu.c
*/

#include "../my.h"
#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

sfRectangleShape *init_edit_button_rect(void)
{
    sfVector2f size = { 0 };
    sfVector2f position = { 0 };
    sfRectangleShape *result = sfRectangleShape_create();

    size.x = EDIT_LEN;
    size.y = EDIT_WID;
    position.x = EDIT_OFFSET_LEN;
    position.y = EDIT_OFFSET_WID;
    sfRectangleShape_setSize(result, size);
    sfRectangleShape_setPosition(result, position);
    sfRectangleShape_setFillColor(result, sfWhite);
    sfRectangleShape_setOutlineThickness(result, BUTTON_THICK);
    sfRectangleShape_setOutlineColor(result, sfBlack);
    return result;
}

sfText *init_edit_text(sfFont *font)
{
    sfVector2f position = { 0 };
    sfText *text = sfText_create();

    position.x = EDIT_TEXT_LEN;
    position.y = EDIT_TEXT_WID;
    sfText_setFont(text, font);
    sfText_setString(text, EDIT_STR);
    sfText_setCharacterSize(text, 19);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, position);
    return text;
}

t_gui_drop_menu *init_edit_menu(void)
{
    t_gui_drop_menu *result = malloc(sizeof(t_gui_drop_menu));

    result->options = NULL;
    result->button = malloc(sizeof(t_gui_drop_object));
    result->button->cliked = button_clicked;
    result->button->over = mouse_over;
    result->button->state = NONE;
    result->button->rect = init_edit_button_rect();
    result->button->font = sfFont_createFromFile(FONT);
    result->button->text = init_edit_text(result->button->font);
    return result;
}

void draw_toolbar(all_object_t *paint)
{
    sfRenderWindow_drawRectangleShape(WINDOW, paint->pencil->rect, NULL);
    sfRenderWindow_drawRectangleShape(WINDOW, paint->eraser->rect, NULL);
}
