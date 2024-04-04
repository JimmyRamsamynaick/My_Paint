/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** my_paint.h
*/

#ifndef PAINT_
    #define PAINT_

    #include "struct.h"

int my_paint(void);
void mouse_over(t_gui_drop_object *button, sfMouseMoveEvent *mouse);
void zone_clicked(button *draw_zone, sfMouseButtonEvent *mouse);
void button_clicked(t_gui_drop_object *button, sfMouseButtonEvent *mouse);
void draw_pencil(button *draw_zone, all_object_t *paint);
void change_all_colors(all_object_t *paint);
void change_colors_button(t_gui_drop_object *button);
void analye_events(all_object_t *paint);
void handle_mouse_movement(all_object_t *paint, sfMouseMoveEvent *mouse);
void handle_cliks(all_object_t *paint, sfEvent event);
void after_act_draw(all_object_t *paint);
void check_tools_act(all_object_t *paint);
void before_action(all_object_t *paint);
void draw_button(sfRenderWindow *window, t_gui_drop_object *button);
button *init_pencil(void);
t_gui_drop_menu *init_help_menu(void);
sfText *init_help_text(void);
sfRectangleShape *init_help_button_rect(void);
t_gui_drop_menu *init_file_menu(void);
sfText *init_file_text(sfFont *font);
sfRectangleShape *init_file_button_rect(void);
button *init_eraser(void);
t_gui_drop_menu *init_edit_menu(void);
sfText *init_edit_text(sfFont *font);
sfRectangleShape *init_edit_button_rect(void);
button *init_draw_windows(void);
sfRenderWindow *init_window(void);
all_object_t *init_all_obj(void);
struct s_gui_object *init_new_file_options(void);
sfRectangleShape *init_new_file_button_rect(void);
sfText *init_new_file_text(sfFont *font);
void free_drawings(all_object_t *paint);
void free_all_obj(all_object_t *paint);
void save_draw_as_jpg(sfRenderWindow *window);
t_gui_object_window *init_save_file_option(void);

#endif
