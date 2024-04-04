/*
** EPITECH PROJECT, 2024
** CSFMLproject
** File description:
** struct.h
*/

#ifndef STRUCT_
    #define STRUCT_

    #include <SFML/Graphics.h>
    #include "all_macros.h"

enum e_gui_state {
    NONE = 0,
    HOVER,
    PRESSED,
    RELEASED,
};

typedef struct s_gui_object_window {
    struct s_gui_object *object;
    sfRenderWindow *window;
    struct s_gui_object_window *next;
} t_gui_object_window;

typedef struct s_gui_object {
    sfRectangleShape *rect;
    sfText *text;
    sfFont *font;
    void (*cliked)(struct s_gui_object *button, sfMouseButtonEvent *mouse);
    void (*over)(struct s_gui_object *, sfMouseMoveEvent *);
    enum e_gui_state state;
} t_gui_drop_object;

typedef struct s_gui_options {
    struct s_gui_object *option;
    struct s_gui_options *next;
} t_gui_drop_options;

typedef struct s_gui_drop_menu {
    struct s_gui_object *button;
    struct s_gui_options *options;
} t_gui_drop_menu;

typedef struct button_s {
    sfRectangleShape *rect;
    void (*zone_is_cliked)(struct button_s *zone, sfMouseButtonEvent *mouse);
    enum e_gui_state state;
    sfColor color;
} button;

typedef struct all_object {
    sfRenderWindow *window;
    t_gui_drop_menu *file_menu;
    t_gui_drop_menu *edit_menu;
    t_gui_drop_menu *help_menu;
    button *draw_zone;
    button *eraser;
    button *pencil;
    sfColor pencil_color;
    sfVertexArray *vertexArray;
} all_object_t;

#endif
