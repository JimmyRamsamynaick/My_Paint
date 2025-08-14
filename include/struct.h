/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include "all_macros.h"

// Enumerations
typedef enum {
    TOOL_PENCIL,
    TOOL_BRUSH,
    TOOL_ERASER,
    TOOL_LINE,
    TOOL_RECTANGLE,
    TOOL_CIRCLE,
    TOOL_FILL
} tool_type_t;

typedef enum {
    STATE_IDLE,
    STATE_DRAWING,
    STATE_MENU_OPEN
} app_state_t;

// Canvas structure
typedef struct {
    sfRenderTexture *texture;
    sfSprite *sprite;
    sfVector2i size;
    sfVector2i position;
    sfColor background_color;
    int modified;
} canvas_t;

// Tool structure
typedef struct {
    tool_type_t type;
    sfColor color;
    int size;
    sfVector2i last_pos;
    int is_drawing;
} tool_t;

// Button structure
typedef struct {
    sfRectangleShape *shape;
    sfText *text;
    sfVector2i position;
    sfVector2i size;
    sfColor normal_color;
    sfColor hover_color;
    sfColor pressed_color;
    int is_hovered;
    int is_pressed;
    void (*callback)(void *data);
} button_t;

// Toolbar structure
typedef struct {
    sfRectangleShape *background;
    button_t **tool_buttons;
    button_t *size_plus_button;
    button_t *size_minus_button;
    button_t *save_button;
    button_t *save_as_button;
    button_t *open_button;
    button_t *new_button;
    sfText *size_text;
    int num_tools;
    int selected_tool;
    int current_size;
    sfVector2i position;
    sfVector2i size;
} toolbar_t;

// Color palette structure
typedef struct {
    sfRectangleShape *background;
    sfRectangleShape **color_squares;
    sfColor *colors;
    int num_colors;
    int selected_color;
    sfVector2i position;
    sfVector2i size;
} color_palette_t;

// Menu item structure
typedef struct menu_item {
    char *text;
    sfText *sf_text;
    sfRectangleShape *background;
    void (*callback)(void *data);
    struct menu_item *next;
} menu_item_t;

// Menu structure
typedef struct {
    char *title;
    sfText *title_text;
    sfRectangleShape *title_background;
    menu_item_t *items;
    int is_open;
    int num_items;
    sfVector2i position;
} menu_t;

// Menu bar structure
typedef struct {
    sfRectangleShape *background;
    menu_t **menus;
    int num_menus;
    int active_menu;
    sfVector2i position;
    sfVector2i size;
} menu_bar_t;

// File dialog structure
typedef struct {
    sfRenderWindow *window;
    sfText *title;
    sfText *filename_text;
    char *filename;
    button_t *ok_button;
    button_t *cancel_button;
    int is_open;
    int result;
} file_dialog_t;

// Undo/Redo structure
typedef struct undo_state {
    sfImage *canvas_state;
    struct undo_state *next;
    struct undo_state *prev;
} undo_state_t;

// History manager
typedef struct {
    undo_state_t *current;
    undo_state_t *head;
    int max_states;
    int current_states;
} history_t;

typedef struct {
    sfRenderWindow *window;
    sfFont *font;
    sfClock *clock;
    
    canvas_t *canvas;
    toolbar_t *toolbar;
    color_palette_t *palette;
    menu_bar_t *menu_bar;
    tool_t *current_tool;
    
    app_state_t state;
    sfVector2i mouse_pos;
    sfVector2i last_mouse_pos;
    
    file_dialog_t *file_dialog;
    char *current_filename;
    history_t *history;
    
    int running;
    int show_help;
} all_object_t;

#endif /* !STRUCT_H_ */
