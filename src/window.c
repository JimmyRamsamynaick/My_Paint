/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** window.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"

sfRenderWindow *init_window(void)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    sfRenderWindow *window = NULL;
    
    window = sfRenderWindow_create(mode, WINDOW_TITLE, 
                                   sfResize | sfClose, NULL);
    
    if (!window)
        return NULL;
    
    sfRenderWindow_setFramerateLimit(window, FRAMERATE_LIMIT);
    sfRenderWindow_setVerticalSyncEnabled(window, sfTrue);
    
    return window;
}
