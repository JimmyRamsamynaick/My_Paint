/*
** EPITECH PROJECT, 2024
** CSFMLproject
** File description:
** all_macros.h
*/

#ifndef MACROS_
    #define MACROS_

    #include "struct.h"

    #define SUCCESS 0
    #define FAILURE 84

    #define WINDOWS_NAME "My_paint"
    #define WINDOWS_WID 1080
    #define WINDOWS_HEI 1920

    #define FILE_WID 28
    #define FILE_LEN 98
    #define FILE_OFFSET_WID 0
    #define FILE_OFFSET_LEN 0
    #define FILE_STR "File"
    #define FILE_TEXT_WID 0
    #define FILE_TEXT_LEN 30

    #define EDIT_WID 28
    #define EDIT_LEN 98
    #define EDIT_OFFSET_WID 0
    #define EDIT_OFFSET_LEN 100
    #define EDIT_STR "Edition"
    #define EDIT_TEXT_WID 0
    #define EDIT_TEXT_LEN 115

    #define HELP_WID 28
    #define HELP_LEN 98
    #define HELP_OFFSET_WID 0
    #define HELP_OFFSET_LEN 200
    #define HELP_STR "Help"
    #define HELP_TEXT_WID 0
    #define HELP_TEXT_LEN 230

    #define FONT "./res/font/arial.ttf"

    #define BUTTON_THICK 2

    #define MOUSE &event.mouseButton

    #define MOUSE_X currsor_pos.x
    #define MOUSE_Y currsor_pos.y

    #define COLOR_PEN paint->pencil_color

    #define WINDOW paint->window

#endif
