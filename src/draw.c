/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** draw.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"
#include <stdlib.h>
#include <string.h>

void draw_pixel(all_object_t *obj, int x, int y)
{
    if (!obj || !obj->canvas || !obj->canvas->texture)
        return;
    
    tool_t *tool = obj->current_tool;
    if (!tool)
        return;
    
    if (x < 0 || x >= obj->canvas->size.x ||
        y < 0 || y >= obj->canvas->size.y)
        return;
    
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setRadius(circle, tool->size / 2.0f);
    sfCircleShape_setFillColor(circle, tool->color);
    sfCircleShape_setPosition(circle, (sfVector2f){x - tool->size / 2.0f, y - tool->size / 2.0f});
    
    sfRenderTexture_drawCircleShape(obj->canvas->texture, circle, NULL);
    sfRenderTexture_display(obj->canvas->texture);
    
    sfCircleShape_destroy(circle);
    obj->canvas->modified = 1;
}

void draw_line(all_object_t *obj, sfVector2i start, sfVector2i end)
{
    if (!obj || !obj->canvas || !obj->canvas->texture)
        return;
    
    tool_t *tool = obj->current_tool;
    
    // Simple line drawing using Bresenham's algorithm
    int dx = abs(end.x - start.x);
    int dy = abs(end.y - start.y);
    int sx = start.x < end.x ? 1 : -1;
    int sy = start.y < end.y ? 1 : -1;
    int err = dx - dy;
    
    sfVector2i current = start;
    
    while (1) {
        draw_pixel(obj, current.x, current.y);
        
        if (current.x == end.x && current.y == end.y)
            break;
        
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            current.x += sx;
        }
        if (e2 < dx) {
            err += dx;
            current.y += sy;
        }
    }
}

void draw_rectangle(all_object_t *obj, sfVector2i start, sfVector2i end)
{
    if (!obj || !obj->canvas || !obj->canvas->texture)
        return;
    
    tool_t *tool = obj->current_tool;
    
    // Draw rectangle outline
    for (int x = start.x; x <= end.x; x++) {
        draw_pixel(obj, x, start.y);
        draw_pixel(obj, x, end.y);
    }
    
    for (int y = start.y; y <= end.y; y++) {
        draw_pixel(obj, start.x, y);
        draw_pixel(obj, end.x, y);
    }
}

void draw_circle(all_object_t *obj, sfVector2i center, int radius)
{
    if (!obj || !obj->canvas || !obj->canvas->texture)
        return;
    
    tool_t *tool = obj->current_tool;
    
    // Simple circle drawing using midpoint circle algorithm
    int x = 0;
    int y = radius;
    int d = 1 - radius;
    
    while (x <= y) {
        draw_pixel(obj, center.x + x, center.y + y);
        draw_pixel(obj, center.x - x, center.y + y);
        draw_pixel(obj, center.x + x, center.y - y);
        draw_pixel(obj, center.x - x, center.y - y);
        draw_pixel(obj, center.x + y, center.y + x);
        draw_pixel(obj, center.x - y, center.y + x);
        draw_pixel(obj, center.x + y, center.y - x);
        draw_pixel(obj, center.x - y, center.y - x);
        
        if (d < 0) {
            d += 2 * x + 3;
        } else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

void erase_area(all_object_t *obj, sfVector2i pos)
{
    if (!obj || !obj->canvas || !obj->canvas->texture)
        return;
    
    tool_t *tool = obj->current_tool;
    
    if (pos.x < 0 || pos.x >= obj->canvas->size.x ||
        pos.y < 0 || pos.y >= obj->canvas->size.y)
        return;
    
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setRadius(circle, tool->size / 2.0f);
    sfCircleShape_setFillColor(circle, obj->canvas->background_color);
    sfCircleShape_setPosition(circle, (sfVector2f){pos.x - tool->size / 2.0f, pos.y - tool->size / 2.0f});
    
    sfRenderTexture_drawCircleShape(obj->canvas->texture, circle, NULL);
    sfRenderTexture_display(obj->canvas->texture);
    
    sfCircleShape_destroy(circle);
    obj->canvas->modified = 1;
}

void draw_on_canvas(all_object_t *obj, sfVector2i pos)
{
    if (!obj || !obj->current_tool)
        return;
        
    tool_t *tool = obj->current_tool;
    
    if (!is_point_in_canvas(obj, pos))
        return;
    
    // Save canvas state before drawing (for undo functionality)
    if (!tool->is_drawing) {
        save_canvas_state(obj);
    }
    
    switch (tool->type) {
        case TOOL_PENCIL:
        case TOOL_BRUSH:
            draw_pixel(obj, pos.x, pos.y);
            break;
        case TOOL_ERASER:
            erase_area(obj, pos);
            break;
        case TOOL_LINE:
            if (tool->is_drawing) {
                draw_line(obj, tool->last_pos, pos);
                tool->is_drawing = 0;
            } else {
                tool->last_pos = pos;
                tool->is_drawing = 1;
            }
            break;
        case TOOL_RECTANGLE:
            if (tool->is_drawing) {
                draw_rectangle(obj, tool->last_pos, pos);
                tool->is_drawing = 0;
            } else {
                tool->last_pos = pos;
                tool->is_drawing = 1;
            }
            break;
        case TOOL_CIRCLE:
            if (tool->is_drawing) {
                int radius = sqrt((tool->last_pos.x - pos.x) * (tool->last_pos.x - pos.x) + 
                                 (tool->last_pos.y - pos.y) * (tool->last_pos.y - pos.y));
                draw_circle(obj, tool->last_pos, radius);
                tool->is_drawing = 0;
            } else {
                tool->last_pos = pos;
                tool->is_drawing = 1;
            }
            break;
        case TOOL_FILL:
            // Use flood fill algorithm to fill connected area
            flood_fill(obj, pos, tool->color);
            printf("Fill tool used at (%d, %d)\n", pos.x, pos.y);
            break;
        default:
            break;
    }
}

sfColor get_pixel_color(all_object_t *obj, int x, int y)
{
    if (!obj || !obj->canvas || !obj->canvas->texture)
        return sfBlack;
    
    // Check bounds
    if (x < 0 || y < 0 || x >= obj->canvas->size.x || y >= obj->canvas->size.y)
        return sfBlack;
    
    // Get the texture from the render texture
    const sfTexture *texture = sfRenderTexture_getTexture(obj->canvas->texture);
    if (!texture)
        return sfBlack;
    
    // Create an image from the texture to read pixel data
    sfImage *image = sfTexture_copyToImage(texture);
    if (!image)
        return sfBlack;
    
    sfColor color = sfImage_getPixel(image, x, y);
    sfImage_destroy(image);
    
    return color;
}

static int colors_equal(sfColor c1, sfColor c2)
{
    return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a);
}

void flood_fill(all_object_t *obj, sfVector2i start, sfColor fill_color)
{
    if (!obj || !obj->canvas || !obj->canvas->texture)
        return;
    
    // Check bounds
    if (start.x < 0 || start.y < 0 || start.x >= obj->canvas->size.x || start.y >= obj->canvas->size.y)
        return;
    
    // Get the original color at the starting position
    sfColor original_color = get_pixel_color(obj, start.x, start.y);
    
    // If the fill color is the same as the original color, no need to fill
    if (colors_equal(original_color, fill_color))
        return;
    
    // Use a more memory-efficient approach with a smaller stack
    typedef struct {
        int x, y;
    } point_t;
    
    // Limit stack size to prevent memory issues
    const int MAX_STACK_SIZE = 10000;
    point_t *stack = malloc(sizeof(point_t) * MAX_STACK_SIZE);
    if (!stack)
        return;
    
    int stack_size = 0;
    
    // Push starting point
    stack[stack_size++] = (point_t){start.x, start.y};
    
    while (stack_size > 0 && stack_size < MAX_STACK_SIZE - 4) {
        // Pop point from stack
        point_t current = stack[--stack_size];
        
        // Check bounds
        if (current.x < 0 || current.y < 0 || 
            current.x >= obj->canvas->size.x || current.y >= obj->canvas->size.y)
            continue;
        
        // Check if current pixel has the original color
        sfColor current_color = get_pixel_color(obj, current.x, current.y);
        if (!colors_equal(current_color, original_color))
            continue;
        
        // Fill the current pixel
        draw_pixel(obj, current.x, current.y);
        
        // Add neighboring pixels to stack (check bounds to prevent overflow)
        if (current.x + 1 < obj->canvas->size.x)
            stack[stack_size++] = (point_t){current.x + 1, current.y};
        if (current.x - 1 >= 0)
            stack[stack_size++] = (point_t){current.x - 1, current.y};
        if (current.y + 1 < obj->canvas->size.y)
            stack[stack_size++] = (point_t){current.x, current.y + 1};
        if (current.y - 1 >= 0)
            stack[stack_size++] = (point_t){current.x, current.y - 1};
    }
    
    free(stack);
}
