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

// Define missing constants
#define SAVE_LEN 100
#define SAVE_WID 30
#define SAVE_OFFSET_LEN 10
#define SAVE_OFFSET_WID 10
#define BUTTON_THICK 2
#define SAVE_TEXT_WID 20
#define FONT "assets/font.ttf"
#define NONE 0

// Forward declarations
void save_file_clicked(button_t *button, sfMouseButtonEvent *mouse);
void mouse_over(button_t *button, sfVector2i mouse_pos);

void save_file_clicked(button_t *button, sfMouseButtonEvent *mouse)
{
    (void)button;
    (void)mouse;
    printf("Save file clicked\n");
    // TODO: Implement save file functionality
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

    size.x = SAVE_LEN;
    size.y = SAVE_WID;
    position.x = SAVE_OFFSET_LEN;
    position.y = SAVE_OFFSET_WID + 93;
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

button_t *init_save_file_option(void)
{
    button_t *button = malloc(sizeof(button_t));
    if (!button)
        return NULL;

    // Initialize button properties
    button->position.x = SAVE_OFFSET_LEN;
    button->position.y = SAVE_OFFSET_WID;
    button->size.x = SAVE_LEN;
    button->size.y = SAVE_WID;
    button->is_pressed = 0;
    button->is_hovered = 0;

    return button;
}
