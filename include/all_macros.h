/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** all_macros.h
*/

#ifndef ALL_MACROS_H_
    #define ALL_MACROS_H_

    // Return values
    #define SUCCESS 0
    #define FAILURE 84
    #define ERROR -1

    // Window settings
    #define WINDOW_WIDTH 1200
    #define WINDOW_HEIGHT 800
    #define WINDOW_TITLE "My Paint - Epitech Project"
    #define FRAMERATE_LIMIT 60

    // Canvas settings
    #define CANVAS_WIDTH 800
    #define CANVAS_HEIGHT 600
    #define CANVAS_X 200
    #define CANVAS_Y 50
    #define CANVAS_BACKGROUND_COLOR sfWhite

    // Toolbar settings
    #define TOOLBAR_WIDTH 180
    #define TOOLBAR_HEIGHT 600
    #define TOOLBAR_X 10
    #define TOOLBAR_Y 50
    #define TOOLBAR_BACKGROUND_COLOR (sfColor){220, 220, 220, 255}

    // Color palette settings
    #define PALETTE_WIDTH 180
    #define PALETTE_HEIGHT 150
    #define PALETTE_X 1010
    #define PALETTE_Y 50
    #define PALETTE_BACKGROUND_COLOR (sfColor){200, 200, 200, 255}
    #define PALETTE_COLORS_PER_ROW 6
    #define PALETTE_COLOR_SIZE 25
    #define PALETTE_COLOR_SPACING 5

    // Menu bar settings
    #define MENU_BAR_HEIGHT 40
    #define MENU_BAR_WIDTH WINDOW_WIDTH
    #define MENU_BAR_X 0
    #define MENU_BAR_Y 0
    #define MENU_BAR_BACKGROUND_COLOR (sfColor){180, 180, 180, 255}
    #define MENU_ITEM_WIDTH 80
    #define MENU_ITEM_HEIGHT 30

    // Button settings
    #define BUTTON_WIDTH 160
    #define BUTTON_HEIGHT 40
    #define BUTTON_SPACING 10
    #define BUTTON_NORMAL_COLOR (sfColor){240, 240, 240, 255}
    #define BUTTON_HOVER_COLOR (sfColor){220, 220, 220, 255}
    #define BUTTON_PRESSED_COLOR (sfColor){200, 200, 200, 255}
    #define BUTTON_TEXT_COLOR sfBlack

    // Tool settings
    #define MIN_BRUSH_SIZE 1
    #define MAX_BRUSH_SIZE 50
    #define DEFAULT_BRUSH_SIZE 3
    #define DEFAULT_COLOR sfBlack

    // File settings
    #define MAX_FILENAME_LENGTH 256
    #define DEFAULT_SAVE_FORMAT ".png"
    #define SUPPORTED_FORMATS ".png .jpg .bmp"

    // Font and text settings
    #define FONT_PATH "./res/font/arial.ttf"
    #define FONT_SIZE 14
    #define MENU_FONT_SIZE 12
    #define TITLE_FONT_SIZE 16
    #define FILE_TEXT_WID 100

    // Colors
    #define COLOR_BLACK sfBlack
    #define COLOR_WHITE sfWhite
    #define COLOR_RED sfRed
    #define COLOR_GREEN sfGreen
    #define COLOR_BLUE sfBlue
    #define COLOR_YELLOW sfYellow
    #define COLOR_MAGENTA sfMagenta
    #define COLOR_CYAN sfCyan
    #define COLOR_GRAY (sfColor){128, 128, 128, 255}
    #define COLOR_ORANGE (sfColor){255, 165, 0, 255}
    #define COLOR_PURPLE (sfColor){128, 0, 128, 255}
    #define COLOR_BROWN (sfColor){165, 42, 42, 255}
    #define COLOR_PINK (sfColor){255, 192, 203, 255}

    // Math constants
    #define PI 3.14159265359
    #define SQRT2 1.41421356237

    // Utility macros
    #define ABS(x) ((x) < 0 ? -(x) : (x))
    #define MIN(a, b) ((a) < (b) ? (a) : (b))
    #define MAX(a, b) ((a) > (b) ? (a) : (b))
    #define CLAMP(x, min, max) (MIN(MAX(x, min), max))

    // Vector macros
    #define VECTOR2I(x, y) ((sfVector2i){x, y})
    #define VECTOR2F(x, y) ((sfVector2f){x, y})

    // Distance calculation
    #define DISTANCE(x1, y1, x2, y2) sqrt(((x2)-(x1))*((x2)-(x1)) + ((y2)-(y1))*((y2)-(y1)))

    // Help text
    #define HELP_TEXT "My Paint - A simple paint application\n\n" \
                  "Usage: ./my_paint [options]\n\n" \
                  "Options:\n" \
                  "  -h, --help    Show this help message\n\n" \
                  "Controls:\n" \
                  "  Left click    Draw/Select\n" \
                  "  Right click   Erase\n" \
                  "  Ctrl+N        New file\n" \
                  "  Ctrl+O        Open file\n" \
                  "  Ctrl+S        Save file\n" \
                  "  Ctrl+Z        Undo\n" \
                  "  Ctrl+Y        Redo\n" \
                  "  ESC           Exit\n\n" \
                  "Tools:\n" \
                  "  Pencil        Draw freehand\n" \
                  "  Brush         Draw with brush\n" \
                  "  Eraser        Erase pixels\n" \
                  "  Line          Draw straight lines\n" \
                  "  Rectangle     Draw rectangles\n" \
                  "  Circle        Draw circles\n" \
                  "  Fill          Fill areas with color\n"

    // About text
    #define ABOUT_TEXT "My Paint v1.0\n\n" \
                   "A simple paint application built with CSFML\n" \
                   "Epitech Project - B-MUL-200\n\n" \
                   "Features:\n" \
                   "- Multiple drawing tools\n" \
                   "- Color palette\n" \
                   "- File operations (New, Open, Save)\n" \
                   "- Undo/Redo functionality\n" \
                   "- Adjustable brush sizes\n"

#endif /* !ALL_MACROS_H_ */
