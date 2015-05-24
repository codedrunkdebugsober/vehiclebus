/*
 * The MIT License (MIT)
 *
 * Copyright (c) [2015] [James O'Carroll]
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include "terminal.h"

void terminal_reset_screen()
{
    printf("\033[2J");
}

void terminal_set_position_home()
{
    printf("\033[H");
}

void terminal_set_position(int column, int row)
{
    // Cursor Home    <ESC>[{ROW};{COLUMN}H
    printf("\033[%d;%dH", row + 1, column + 1);
}

void terminal_set_cursor_invisible()
{
    printf("\033[?25l");
}

void terminal_set_cursor_visible()
{
    printf("\033[?25h");
}

void terminal_set_foreground_color(terminal_color_t color)
{
    // Set Attribute Mode    <ESC>[{n}m
    // Foreground colors : 30 + bgr
//    int c = 30 + rgb888tobgr111(color);
    int c = 30 + color;
    printf("\033[%dm", c);
}

void terminal_set_background_color(terminal_color_t color)
{
    // Set Attribute Mode    <ESC>[{n}m
    // Background colors : 40 + bgr
//    int c = 40 + rgb888tobgr111(color);
    int c = 40 + color;
    printf("\033[%dm", c);
}

/*
 * Additional settings/options:
 *
 * \033[0K    Clear line from current cursor position to end of line
 * \033[1K    Clear line from beginning to current cursor position
 * \033[2K    Clear whole line (cursor position unchanged)
 *
 * \033[0m   sgr0    Reset all attributes
 * \033[1m   bold    Set "bright" attribute
 * \033[2m   dim Set "dim" attribute
 * \033[4m   set smul unset rmul :?: Set "underscore" (underlined text) attribute
 * \033[5m   blink   Set "blink" attribute
 * \033[7m   rev Set "reverse" attribute
 * \033[8m   invis   Set "hidden" attribute
 *
 *
 *
 */


