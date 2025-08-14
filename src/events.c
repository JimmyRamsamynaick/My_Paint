/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** events.c
*/

#include "../include/my_paint.h"
#include "../include/all_macros.h"
#include "../include/struct.h"

static void handle_menu_click(all_object_t *obj, sfVector2i mouse_pos)
{
    menu_bar_t *menu_bar = obj->menu_bar;
    
    for (int i = 0; i < menu_bar->num_menus; i++) {
        menu_t *menu = menu_bar->menus[i];
        // Simple menu title positioning
        sfVector2i title_pos = {i * 80, 0};
        sfVector2i title_size = {80, MENU_BAR_HEIGHT};
        
        // Check if click is on menu title
        if (mouse_pos.x >= title_pos.x && mouse_pos.x <= title_pos.x + title_size.x &&
            mouse_pos.y >= title_pos.y && mouse_pos.y <= title_pos.y + title_size.y) {
            menu->is_open = !menu->is_open;
            // Close other menus
            for (int j = 0; j < menu_bar->num_menus; j++) {
                if (j != i)
                    menu_bar->menus[j]->is_open = 0;
            }
            return;
        }
        
        // Check if click is on menu items (if menu is open)
        if (menu->is_open) {
            for (int j = 0; j < menu->num_items; j++) {
                menu_item_t *item = &menu->items[j];
                sfVector2i item_pos = {title_pos.x, title_pos.y + title_size.y + j * 25};
                sfVector2i item_size = {title_size.x, 25};
                
                if (mouse_pos.x >= item_pos.x && mouse_pos.x <= item_pos.x + item_size.x &&
                    mouse_pos.y >= item_pos.y && mouse_pos.y <= item_pos.y + item_size.y) {
                    // Handle menu item click based on menu and item index
                    // Handle menu action for menu i, item j
                    printf("Menu %d, Item %d clicked\n", i, j);
                    menu->is_open = 0;
                    return;
                }
            }
        }
    }
    
    // Close all menus if click is outside
    for (int i = 0; i < menu_bar->num_menus; i++) {
        menu_bar->menus[i]->is_open = 0;
    }
}

static void handle_toolbar_click(all_object_t *obj, sfVector2i mouse_pos)
{
    toolbar_t *toolbar = obj->toolbar;
    
    // Check tool buttons
    for (int i = 0; i < toolbar->num_tools; i++) {
        button_t *button = toolbar->tool_buttons[i];
        sfVector2i btn_pos = button->position;
        sfVector2i btn_size = button->size;
        
        if (mouse_pos.x >= btn_pos.x && mouse_pos.x <= btn_pos.x + btn_size.x &&
            mouse_pos.y >= btn_pos.y && mouse_pos.y <= btn_pos.y + btn_size.y) {
            // Reset all buttons to normal state
            for (int j = 0; j < toolbar->num_tools; j++) {
                toolbar->tool_buttons[j]->is_pressed = 0;
            }
            
            // Set clicked button as pressed/selected
            button->is_pressed = 1;
            toolbar->selected_tool = i;
            obj->current_tool->type = (tool_type_t)i;
            
            // Update button colors
            change_all_colors(obj);
            return;
        }
    }
    
    // Check size plus button
    if (toolbar->size_plus_button) {
        button_t *button = toolbar->size_plus_button;
        sfVector2i btn_pos = button->position;
        sfVector2i btn_size = button->size;
        
        if (mouse_pos.x >= btn_pos.x && mouse_pos.x <= btn_pos.x + btn_size.x &&
            mouse_pos.y >= btn_pos.y && mouse_pos.y <= btn_pos.y + btn_size.y) {
            if (toolbar->current_size < MAX_BRUSH_SIZE) {
                toolbar->current_size++;
                obj->current_tool->size = toolbar->current_size;
            }
            return;
        }
    }
    
    // Check size minus button
    if (toolbar->size_minus_button) {
        button_t *button = toolbar->size_minus_button;
        sfVector2i btn_pos = button->position;
        sfVector2i btn_size = button->size;
        
        if (mouse_pos.x >= btn_pos.x && mouse_pos.x <= btn_pos.x + btn_size.x &&
            mouse_pos.y >= btn_pos.y && mouse_pos.y <= btn_pos.y + btn_size.y) {
            if (toolbar->current_size > MIN_BRUSH_SIZE) {
                toolbar->current_size--;
                obj->current_tool->size = toolbar->current_size;
            }
            return;
        }
    }
    
    // Check save button
    if (toolbar->save_button) {
        button_t *button = toolbar->save_button;
        sfVector2i btn_pos = button->position;
        sfVector2i btn_size = button->size;
        
        if (mouse_pos.x >= btn_pos.x && mouse_pos.x <= btn_pos.x + btn_size.x &&
            mouse_pos.y >= btn_pos.y && mouse_pos.y <= btn_pos.y + btn_size.y) {
            save_file(obj, NULL);
            return;
        }
    }
    
    // Check save as button
    if (toolbar->save_as_button) {
        button_t *button = toolbar->save_as_button;
        sfVector2i btn_pos = button->position;
        sfVector2i btn_size = button->size;
        
        if (mouse_pos.x >= btn_pos.x && mouse_pos.x <= btn_pos.x + btn_size.x &&
            mouse_pos.y >= btn_pos.y && mouse_pos.y <= btn_pos.y + btn_size.y) {
            save_file_as(obj, "untitled.png");
            return;
        }
    }
    
    // Check open button
    if (toolbar->open_button) {
        button_t *button = toolbar->open_button;
        sfVector2i btn_pos = button->position;
        sfVector2i btn_size = button->size;
        
        if (mouse_pos.x >= btn_pos.x && mouse_pos.x <= btn_pos.x + btn_size.x &&
            mouse_pos.y >= btn_pos.y && mouse_pos.y <= btn_pos.y + btn_size.y) {
            open_file(obj, NULL);
            return;
        }
    }
    
    // Check new button
    if (toolbar->new_button) {
        button_t *button = toolbar->new_button;
        sfVector2i btn_pos = button->position;
        sfVector2i btn_size = button->size;
        
        if (mouse_pos.x >= btn_pos.x && mouse_pos.x <= btn_pos.x + btn_size.x &&
            mouse_pos.y >= btn_pos.y && mouse_pos.y <= btn_pos.y + btn_size.y) {
            new_file(obj);
            return;
        }
    }
}

static void handle_palette_click(all_object_t *obj, sfVector2i mouse_pos)
{
    if (!obj->palette)
        return;
    
    color_palette_t *palette = obj->palette;
    
    for (int i = 0; i < palette->num_colors; i++) {
        sfVector2f pos = sfRectangleShape_getPosition(palette->color_squares[i]);
        sfVector2f size = sfRectangleShape_getSize(palette->color_squares[i]);
        
        if (mouse_pos.x >= pos.x && mouse_pos.x <= pos.x + size.x &&
            mouse_pos.y >= pos.y && mouse_pos.y <= pos.y + size.y) {
            palette->selected_color = i;
            obj->current_tool->color = palette->colors[i];
            return;
        }
    }
}

static void handle_canvas_click(all_object_t *obj, sfVector2i mouse_pos)
{
    canvas_t *canvas = obj->canvas;
    
    // Check if click is within canvas bounds
    if (mouse_pos.x >= canvas->position.x && 
        mouse_pos.x <= canvas->position.x + canvas->size.x &&
        mouse_pos.y >= canvas->position.y && 
        mouse_pos.y <= canvas->position.y + canvas->size.y) {
        
        // Convert to canvas coordinates
        sfVector2i canvas_pos = {
            mouse_pos.x - canvas->position.x,
            mouse_pos.y - canvas->position.y
        };
        
        // Start drawing mode for continuous tools
        if (obj->current_tool->type == TOOL_PENCIL || obj->current_tool->type == TOOL_BRUSH || obj->current_tool->type == TOOL_ERASER) {
            obj->current_tool->is_drawing = 1;
            obj->current_tool->last_pos = canvas_pos;
        }
        
        // Perform drawing action based on current tool
        draw_on_canvas(obj, canvas_pos);
        canvas->modified = 1;
    }
}

void handle_mouse_click(all_object_t *obj, sfMouseButtonEvent *event)
{
    if (!obj || !event)
        return;
    
    sfVector2i mouse_pos = {event->x, event->y};
    
    // Check menu bar first
    if (mouse_pos.y <= MENU_BAR_HEIGHT) {
        handle_menu_click(obj, mouse_pos);
        return;
    }
    
    // Check toolbar
    if (mouse_pos.x >= TOOLBAR_X && mouse_pos.x <= TOOLBAR_X + TOOLBAR_WIDTH &&
        mouse_pos.y >= TOOLBAR_Y && mouse_pos.y <= TOOLBAR_Y + TOOLBAR_HEIGHT) {
        handle_toolbar_click(obj, mouse_pos);
        return;
    }
    
    // Check color palette
    if (mouse_pos.x >= PALETTE_X && mouse_pos.x <= PALETTE_X + PALETTE_WIDTH &&
        mouse_pos.y >= PALETTE_Y && mouse_pos.y <= PALETTE_Y + PALETTE_HEIGHT) {
        handle_palette_click(obj, mouse_pos);
        return;
    }
    
    // Check canvas
    handle_canvas_click(obj, mouse_pos);
}

void handle_mouse_movement(all_object_t *obj, sfVector2i mouse_pos)
{
    if (!obj)
        return;
    
    // Handle continuous drawing for pencil and brush tools
    if (obj->current_tool && obj->current_tool->is_drawing) {
        if (obj->current_tool->type == TOOL_PENCIL || obj->current_tool->type == TOOL_BRUSH) {
            // Check if mouse is in canvas area
            if (mouse_pos.x >= obj->canvas->position.x && 
                mouse_pos.x <= obj->canvas->position.x + obj->canvas->size.x &&
                mouse_pos.y >= obj->canvas->position.y && 
                mouse_pos.y <= obj->canvas->position.y + obj->canvas->size.y) {
                
                // Convert to canvas coordinates
                sfVector2i canvas_pos = {
                    mouse_pos.x - obj->canvas->position.x,
                    mouse_pos.y - obj->canvas->position.y
                };
                
                // Draw line from last position to current position for smooth drawing
                if (obj->current_tool->last_pos.x >= 0 && obj->current_tool->last_pos.y >= 0) {
                    draw_line(obj, obj->current_tool->last_pos, canvas_pos);
                } else {
                    draw_pixel(obj, canvas_pos.x, canvas_pos.y);
                }
                
                obj->current_tool->last_pos = canvas_pos;
                obj->canvas->modified = 1;
            }
        } else if (obj->current_tool->type == TOOL_ERASER) {
            // Handle continuous erasing
            if (mouse_pos.x >= obj->canvas->position.x && 
                mouse_pos.x <= obj->canvas->position.x + obj->canvas->size.x &&
                mouse_pos.y >= obj->canvas->position.y && 
                mouse_pos.y <= obj->canvas->position.y + obj->canvas->size.y) {
                
                sfVector2i canvas_pos = {
                    mouse_pos.x - obj->canvas->position.x,
                    mouse_pos.y - obj->canvas->position.y
                };
                
                erase_area(obj, canvas_pos);
                obj->current_tool->last_pos = canvas_pos;
                obj->canvas->modified = 1;
            }
        }
    }
    
    // Update hover states for toolbar buttons
    if (obj->toolbar) {
        for (int i = 0; i < obj->toolbar->num_tools; i++) {
            button_t *button = obj->toolbar->tool_buttons[i];
            sfVector2i btn_pos = button->position;
            sfVector2i btn_size = button->size;
            
            // Check if mouse is over button
            if (mouse_pos.x >= btn_pos.x && mouse_pos.x <= btn_pos.x + btn_size.x &&
                mouse_pos.y >= btn_pos.y && mouse_pos.y <= btn_pos.y + btn_size.y) {
                button->is_hovered = 1;
            } else {
                button->is_hovered = 0;
            }
        }
        
        // Update button colors based on hover state
        change_all_colors(obj);
    }
}

void handle_mouse_move(all_object_t *obj, sfMouseMoveEvent *event)
{
    if (!obj || !event)
        return;
    
    sfVector2i mouse_pos = {event->x, event->y};
    handle_mouse_movement(obj, mouse_pos);
}

void handle_key_press(all_object_t *obj, sfKeyEvent *event)
{
    if (!obj || !event)
        return;
    
    switch (event->code) {
        case sfKeyEscape:
            sfRenderWindow_close(obj->window);
            break;
        case sfKeyZ:
            if (sfKeyboard_isKeyPressed(sfKeyLControl) || 
                sfKeyboard_isKeyPressed(sfKeyRControl)) {
                undo_action(obj);
            }
            break;
        case sfKeyY:
            if (sfKeyboard_isKeyPressed(sfKeyLControl) || 
                sfKeyboard_isKeyPressed(sfKeyRControl)) {
                redo_action(obj);
            }
            break;
        case sfKeyS:
            if (sfKeyboard_isKeyPressed(sfKeyLControl) || 
                sfKeyboard_isKeyPressed(sfKeyRControl)) {
                save_file(obj, "untitled.png");
            }
            break;
        case sfKeyO:
            if (sfKeyboard_isKeyPressed(sfKeyLControl) || 
                sfKeyboard_isKeyPressed(sfKeyRControl)) {
                open_file(obj, "file.png");
            }
            break;
        case sfKeyN:
            if (sfKeyboard_isKeyPressed(sfKeyLControl) || 
                sfKeyboard_isKeyPressed(sfKeyRControl)) {
                new_file(obj);
            }
            break;
        // Tool shortcuts
        case sfKeyP:
            // Switch to Pencil tool
            if (obj->toolbar && obj->toolbar->num_tools > 0) {
                for (int i = 0; i < obj->toolbar->num_tools; i++) {
                    obj->toolbar->tool_buttons[i]->is_pressed = 0;
                }
                obj->toolbar->tool_buttons[0]->is_pressed = 1;
                obj->toolbar->selected_tool = 0;
                obj->current_tool->type = TOOL_PENCIL;
                change_all_colors(obj);
            }
            break;
        case sfKeyB:
            // Switch to Brush tool
            if (obj->toolbar && obj->toolbar->num_tools > 1) {
                for (int i = 0; i < obj->toolbar->num_tools; i++) {
                    obj->toolbar->tool_buttons[i]->is_pressed = 0;
                }
                obj->toolbar->tool_buttons[1]->is_pressed = 1;
                obj->toolbar->selected_tool = 1;
                obj->current_tool->type = TOOL_BRUSH;
                change_all_colors(obj);
            }
            break;
        case sfKeyE:
            // Switch to Eraser tool
            if (obj->toolbar && obj->toolbar->num_tools > 2) {
                for (int i = 0; i < obj->toolbar->num_tools; i++) {
                    obj->toolbar->tool_buttons[i]->is_pressed = 0;
                }
                obj->toolbar->tool_buttons[2]->is_pressed = 1;
                obj->toolbar->selected_tool = 2;
                obj->current_tool->type = TOOL_ERASER;
                change_all_colors(obj);
            }
            break;
        case sfKeyF:
            // Switch to Fill tool
            if (obj->toolbar && obj->toolbar->num_tools > 6) {
                for (int i = 0; i < obj->toolbar->num_tools; i++) {
                    obj->toolbar->tool_buttons[i]->is_pressed = 0;
                }
                obj->toolbar->tool_buttons[6]->is_pressed = 1;
                obj->toolbar->selected_tool = 6;
                obj->current_tool->type = TOOL_FILL;
                change_all_colors(obj);
            }
            break;
        case sfKeyL:
            // Switch to Line tool
            if (obj->toolbar && obj->toolbar->num_tools > 3) {
                for (int i = 0; i < obj->toolbar->num_tools; i++) {
                    obj->toolbar->tool_buttons[i]->is_pressed = 0;
                }
                obj->toolbar->tool_buttons[3]->is_pressed = 1;
                obj->toolbar->selected_tool = 3;
                obj->current_tool->type = TOOL_LINE;
                change_all_colors(obj);
            }
            break;
        case sfKeyR:
            // Switch to Rectangle tool
            if (obj->toolbar && obj->toolbar->num_tools > 4) {
                for (int i = 0; i < obj->toolbar->num_tools; i++) {
                    obj->toolbar->tool_buttons[i]->is_pressed = 0;
                }
                obj->toolbar->tool_buttons[4]->is_pressed = 1;
                obj->toolbar->selected_tool = 4;
                obj->current_tool->type = TOOL_RECTANGLE;
                change_all_colors(obj);
            }
            break;
        case sfKeyC:
            // Switch to Circle tool
            if (obj->toolbar && obj->toolbar->num_tools > 5) {
                for (int i = 0; i < obj->toolbar->num_tools; i++) {
                    obj->toolbar->tool_buttons[i]->is_pressed = 0;
                }
                obj->toolbar->tool_buttons[5]->is_pressed = 1;
                obj->toolbar->selected_tool = 5;
                obj->current_tool->type = TOOL_CIRCLE;
                change_all_colors(obj);
            }
            break;
        case sfKeyAdd:
        case sfKeyEqual:
            // Increase brush size
            if (obj->toolbar && obj->toolbar->current_size < MAX_BRUSH_SIZE) {
                obj->toolbar->current_size++;
                obj->current_tool->size = obj->toolbar->current_size;
            }
            break;
        case sfKeySubtract:
        case sfKeyHyphen:
            // Decrease brush size
            if (obj->toolbar && obj->toolbar->current_size > MIN_BRUSH_SIZE) {
                obj->toolbar->current_size--;
                obj->current_tool->size = obj->toolbar->current_size;
            }
            break;
        default:
            break;
    }
}

void analyze_events(all_object_t *obj)
{
    sfEvent event;
    
    while (sfRenderWindow_pollEvent(obj->window, &event)) {
        switch (event.type) {
            case sfEvtClosed:
                sfRenderWindow_close(obj->window);
                break;
            case sfEvtMouseButtonPressed:
                if (event.mouseButton.button == sfMouseLeft) {
                    handle_mouse_click(obj, &event.mouseButton);
                }
                break;
            case sfEvtMouseMoved:
                {
                    sfVector2i mouse_pos = {event.mouseMove.x, event.mouseMove.y};
                    handle_mouse_movement(obj, mouse_pos);
                }
                break;
            case sfEvtKeyPressed:
                handle_key_press(obj, &event.key);
                break;
            default:
                break;
        }
    }
}