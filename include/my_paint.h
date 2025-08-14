/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** my_paint.h
*/

#ifndef MY_PAINT_H_
    #define MY_PAINT_H_

    #include "struct.h"
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <math.h>

// Main function
int my_paint(void);

// Initialization functions
all_object_t *init_all_obj(void);
sfRenderWindow *init_window(void);
canvas_t *init_canvas(void);
toolbar_t *init_toolbar(void);
color_palette_t *init_color_palette(void);
menu_bar_t *init_menu_bar(void);

//// Event handling
void handle_events(all_object_t *paint);
void analye_events(all_object_t *paint);
void handle_mouse_click(all_object_t *paint, sfMouseButtonEvent *event);
void handle_mouse_move(all_object_t *paint, sfMouseMoveEvent *event);
void handle_key_press(all_object_t *paint, sfKeyEvent *event);

// Drawing functions
void draw_on_canvas(all_object_t *paint, sfVector2i pos);
void draw_pixel(all_object_t *paint, int x, int y);
void draw_line(all_object_t *paint, sfVector2i start, sfVector2i end);
void draw_rectangle(all_object_t *paint, sfVector2i start, sfVector2i end);
void draw_circle(all_object_t *paint, sfVector2i center, int radius);
void erase_pixel(all_object_t *paint, int x, int y);
void erase_area(all_object_t *paint, sfVector2i pos);
void flood_fill(all_object_t *paint, sfVector2i start, sfColor fill_color);

// Tool functions
void set_tool(all_object_t *paint, tool_type_t tool);
void set_brush_size(all_object_t *paint, int size);
void set_color(all_object_t *paint, sfColor color);

// File operations
void new_file(all_object_t *paint);
void open_file(all_object_t *paint, const char *filename);
void save_file(all_object_t *paint, const char *filename);
void save_as_file(all_object_t *paint);
void save_file_as(all_object_t *obj, const char *filename);

// History management
history_t *init_history(void);
void save_canvas_state(all_object_t *obj);
void undo_action(all_object_t *obj);
void redo_action(all_object_t *obj);
void clear_canvas(all_object_t *obj);
void show_about(all_object_t *obj);
void show_help(all_object_t *obj);
void exit_application(all_object_t *obj);
void handle_menu_action(all_object_t *obj, int menu_index, int item_index);

// Menu functions
void show_file_menu(all_object_t *paint);
void show_edit_menu(all_object_t *paint);
void show_help_menu(all_object_t *paint);
void show_about_dialog(all_object_t *paint);

// Rendering functions
void render_all(all_object_t *paint);
void render_canvas(all_object_t *paint);
void render_toolbar(all_object_t *paint);
void render_color_palette(all_object_t *paint);
void render_menu_bar(all_object_t *paint);

// Utility functions
sfVector2i get_mouse_position(all_object_t *paint);
int is_point_in_canvas(all_object_t *paint, sfVector2i pos);
int is_point_in_toolbar(all_object_t *paint, sfVector2i pos);
int is_point_in_palette(all_object_t *paint, sfVector2i pos);
sfColor get_pixel_color(all_object_t *paint, int x, int y);
void set_pixel_color(all_object_t *paint, int x, int y, sfColor color);

// Button and color functions
void change_all_colors(all_object_t *paint);
void change_colors_button(button_t *button);

// Cleanup functions
void free_all_obj(all_object_t *paint);
void free_canvas(canvas_t *canvas);
void free_toolbar(toolbar_t *toolbar);
void free_color_palette(color_palette_t *palette);
void free_menu_bar(menu_bar_t *menu_bar);
void cleanup_all(all_object_t *obj);
void cleanup_toolbar(toolbar_t *toolbar);
void cleanup_canvas(canvas_t *canvas);
void cleanup_color_palette(color_palette_t *palette);
void cleanup_menu_bar(menu_bar_t *menu_bar);
void cleanup_file_dialog(file_dialog_t *dialog);
void cleanup_history(history_t *history);

// Help function
void print_help(void);

#endif /* !MY_PAINT_H_ */
