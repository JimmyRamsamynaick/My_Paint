/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** new_file_opt.c
*/

#include "../my.h"
#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

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

struct s_gui_object *init_new_file_options(void)
{
    struct s_gui_object *option = malloc(sizeof(struct s_gui_object));

    option->cliked = button_clicked;
    option->over = mouse_over;
    option->font = sfFont_createFromFile(FONT);
    option->text = init_new_file_text(option->font);
    option->state = NONE;
    option->rect = init_new_file_button_rect();
    return option;
}
