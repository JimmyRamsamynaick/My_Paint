/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** save.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <stdlib.h>

void save_file_clicked(t_gui_object_window *button_window,
    sfMouseButtonEvent *mouse)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds
    (button_window->object->rect);

    if (sfFloatRect_contains(&rect, mouse->x, mouse->y) == sfTrue)
        save_draw_as_jpg(button_window->window);
}

void save_draw_as_jpg(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile("drawing.png", NULL);
    sfImage *image = sfTexture_copyToImage(texture);

    sfImage_saveToFile(image, "drawing.jpg");
}

sfRectangleShape *init_save_file_button_rect(void)
{
    sfVector2f size = { 0 };
    sfRectangleShape *result = sfRectangleShape_create();
    sfVector2f position = { 0 };

    size.x = FILE_LEN;
    size.y = FILE_WID;
    position.x = FILE_OFFSET_LEN;
    position.y = FILE_OFFSET_WID + 93;
    sfRectangleShape_setSize(result, size);
    sfRectangleShape_setPosition(result, position);
    sfRectangleShape_setFillColor(result, sfWhite);
    sfRectangleShape_setOutlineThickness(result, BUTTON_THICK);
    sfRectangleShape_setOutlineColor(result, sfBlack);
    return result;
}

sfText *init_save_file_text(sfFont *font)
{
    sfVector2f position = { 0 };
    sfText *text = sfText_create();

    position.x = 10;
    position.y = FILE_TEXT_WID + 93;
    sfText_setFont(text, font);
    sfText_setString(text, "Save file");
    sfText_setCharacterSize(text, 19);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, position);
    return text;
}

t_gui_object_window *init_save_file_option(void)
{
    t_gui_object_window *option_window = malloc(sizeof(t_gui_object_window));

    option_window->object = malloc(sizeof(struct s_gui_object));
    option_window->object->cliked = (void (*)
    (struct s_gui_object *, sfMouseButtonEvent *))save_file_clicked;
    option_window->object->over = mouse_over;
    option_window->object->font = sfFont_createFromFile(FONT);
    option_window->object->text = init_save_file_text(option_window->
    object->font);
    option_window->object->state = NONE;
    option_window->object->rect = init_save_file_button_rect();
    option_window->window = NULL;
    return option_window;
}
