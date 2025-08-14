/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** init_all.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include "../my.h"

static tool_t *init_tool(void)
{
    tool_t *tool = malloc(sizeof(tool_t));
    
    if (!tool)
        return NULL;
    
    tool->type = TOOL_PENCIL;
    tool->color = DEFAULT_COLOR;
    tool->size = DEFAULT_BRUSH_SIZE;
    tool->last_pos = VECTOR2I(-1, -1);
    tool->is_drawing = 0;
    
    return tool;
}

static int load_font(all_object_t *paint)
{
    paint->font = sfFont_createFromFile(FONT_PATH);
    if (!paint->font) {
        my_putstr("Warning: Could not load font from ");
        my_putstr(FONT_PATH);
        my_putstr(". Using default font.\n");
        return ERROR;
    }
    return SUCCESS;
}

static void init_basic_components(all_object_t *paint)
{
    paint->clock = sfClock_create();
    paint->current_filename = NULL;
    paint->file_dialog = NULL;
    paint->show_help = 0;
}

all_object_t *init_all_obj(void)
{
    all_object_t *paint = malloc(sizeof(all_object_t));
    
    if (!paint)
        return NULL;
    
    // Initialize basic components
    init_basic_components(paint);
    
    // Load font
    load_font(paint);
    
    // Initialize window
    paint->window = init_window();
    if (!paint->window) {
        free(paint);
        return NULL;
    }
    
    // Initialize main components
    paint->canvas = init_canvas();
    paint->toolbar = init_toolbar();
    paint->palette = init_color_palette();
    paint->menu_bar = init_menu_bar();
    paint->current_tool = init_tool();
    paint->history = init_history();
    
    // Check if all components were initialized successfully
    if (!paint->canvas || !paint->toolbar || !paint->palette || 
        !paint->menu_bar || !paint->current_tool || !paint->history) {
        cleanup_all(paint);
        return NULL;
    }
    
    return paint;
}
