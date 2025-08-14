/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** init_palette.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"

static void init_default_colors(color_palette_t *palette)
{
    palette->colors[0] = COLOR_BLACK;
    palette->colors[1] = COLOR_WHITE;
    palette->colors[2] = COLOR_RED;
    palette->colors[3] = COLOR_GREEN;
    palette->colors[4] = COLOR_BLUE;
    palette->colors[5] = COLOR_YELLOW;
    palette->colors[6] = COLOR_MAGENTA;
    palette->colors[7] = COLOR_CYAN;
    palette->colors[8] = COLOR_GRAY;
    palette->colors[9] = COLOR_ORANGE;
    palette->colors[10] = COLOR_PURPLE;
    palette->colors[11] = COLOR_BROWN;
    palette->colors[12] = COLOR_PINK;
    palette->colors[13] = (sfColor){64, 64, 64, 255};    // Dark gray
    palette->colors[14] = (sfColor){192, 192, 192, 255}; // Light gray
    palette->colors[15] = (sfColor){128, 64, 0, 255};    // Dark brown
    palette->colors[16] = (sfColor){0, 128, 128, 255};   // Teal
    palette->colors[17] = (sfColor){128, 0, 64, 255};    // Maroon
}

static int create_color_squares(color_palette_t *palette)
{
    int x, y, index = 0;
    
    palette->color_squares = malloc(sizeof(sfRectangleShape*) * palette->num_colors);
    if (!palette->color_squares)
        return ERROR;
    
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < PALETTE_COLORS_PER_ROW; col++) {
            if (index >= palette->num_colors)
                break;
                
            x = PALETTE_X + 10 + col * (PALETTE_COLOR_SIZE + PALETTE_COLOR_SPACING);
            y = PALETTE_Y + 30 + row * (PALETTE_COLOR_SIZE + PALETTE_COLOR_SPACING);
            
            palette->color_squares[index] = sfRectangleShape_create();
            if (!palette->color_squares[index]) {
                // Free previously allocated squares
                for (int i = 0; i < index; i++) {
                    sfRectangleShape_destroy(palette->color_squares[i]);
                }
                free(palette->color_squares);
                return ERROR;
            }
            
            sfRectangleShape_setSize(palette->color_squares[index], 
                                   VECTOR2F(PALETTE_COLOR_SIZE, PALETTE_COLOR_SIZE));
            sfRectangleShape_setPosition(palette->color_squares[index], 
                                       VECTOR2F(x, y));
            sfRectangleShape_setFillColor(palette->color_squares[index], 
                                        palette->colors[index]);
            sfRectangleShape_setOutlineThickness(palette->color_squares[index], 1);
            sfRectangleShape_setOutlineColor(palette->color_squares[index], sfBlack);
            
            index++;
        }
    }
    
    return SUCCESS;
}

color_palette_t *init_color_palette(void)
{
    color_palette_t *palette = malloc(sizeof(color_palette_t));
    
    if (!palette)
        return NULL;
    
    // Set palette properties
    palette->position = VECTOR2I(PALETTE_X, PALETTE_Y);
    palette->size = VECTOR2I(PALETTE_WIDTH, PALETTE_HEIGHT);
    palette->num_colors = 18;
    palette->selected_color = 0; // Default to black
    
    // Allocate colors array
    palette->colors = malloc(sizeof(sfColor) * palette->num_colors);
    if (!palette->colors) {
        free(palette);
        return NULL;
    }
    
    // Initialize default colors
    init_default_colors(palette);
    
    // Create background
    palette->background = sfRectangleShape_create();
    if (!palette->background) {
        free(palette->colors);
        free(palette);
        return NULL;
    }
    
    sfRectangleShape_setSize(palette->background, VECTOR2F(PALETTE_WIDTH, PALETTE_HEIGHT));
    sfRectangleShape_setPosition(palette->background, VECTOR2F(PALETTE_X, PALETTE_Y));
    sfRectangleShape_setFillColor(palette->background, PALETTE_BACKGROUND_COLOR);
    sfRectangleShape_setOutlineThickness(palette->background, 2);
    sfRectangleShape_setOutlineColor(palette->background, sfBlack);
    
    // Create color squares
    if (create_color_squares(palette) != SUCCESS) {
        sfRectangleShape_destroy(palette->background);
        free(palette->colors);
        free(palette);
        return NULL;
    }
    
    return palette;
}