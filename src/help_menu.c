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

t_gui_drop_menu *init_help_menu(void)
{
    t_gui_drop_menu *result = malloc(sizeof(t_gui_drop_menu));

    result->options = NULL;
    result->button = malloc(sizeof(t_gui_drop_object));
    result->button->cliked = button_clicked;
    result->button->over = mouse_over;
    result->button->state = NONE;
    result->button->rect = init_help_button_rect();
    result->button->text = init_help_text();
    return result;
}
