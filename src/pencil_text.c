/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** pencil_text.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <stdlib.h>

sfText *init_pencil_tool_text(sfFont *font)
{
    sfVector2f position = { 0 };
    sfText *text = sfText_create();

    position.x = 10;
    position.y = FILE_TEXT_WID + 31;
    sfText_setFont(text, font);
    sfText_setString(text, "Pencil Tool");
    sfText_setCharacterSize(text, 19);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, position);
    return text;
}

sfText *init_eraser_tool_text(sfFont *font)
{
    sfVector2f position = { 0 };
    sfText *text = sfText_create();

    position.x = 10;
    position.y = FILE_TEXT_WID + 31;
    sfText_setFont(text, font);
    sfText_setString(text, "Eraser Tool");
    sfText_setCharacterSize(text, 19);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, position);
    return text;
}
