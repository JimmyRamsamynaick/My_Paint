/*
** EPITECH PROJECT, 2024
** CSFMLproject
** File description:
** window.c
*/

#include "../my.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <SFML/Graphics.h>

sfRenderWindow *init_window(void)
{
    sfVideoMode mode = {WINDOWS_HEI, WINDOWS_WID, 32};
    sfRenderWindow *window = NULL;

    window = sfRenderWindow_create(mode, WINDOWS_NAME, sfResize | sfClose,
    NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}
