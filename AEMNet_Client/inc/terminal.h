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

#ifndef TERMINAL_H_
#define TERMINAL_H_

typedef enum
{
    BLACK = 0,
    RED = 1,
    GREEN = 2,
    YELLOW = 3,
    BLUE = 4,
    MAGENTA = 5,
    CYAN = 6,
    WHITE = 7,
    DEFAULT = 8
} terminal_color_t;

/**
 * Set position to home (0, 0).
 */
void terminal_set_position_home();

/**
 * Set position to a screen column and row.
 *
 * @param column    The horizontal position from the left, indexed from 0.
 * @param row       The vertical position from the top, indexed from 0.
 */
void terminal_set_position(int column, int row);

/**
 * Hide the terminal cursor.  This is handy when printing a lot of data to the cursor, on top of itself.
 * This setting seems to persist beyond program operation.
 */
void terminal_set_cursor_invisible();

/**
 * Make the terminal cursor visible.
 * This setting seems to persist beyond program operation.
 */
void terminal_set_cursor_visible();

/**
 * Clear the screen and locate to 0,0.
 */
void terminal_reset_screen();

/**
 * Set the foreground color.
 */
void terminal_set_foreground_color(terminal_color_t color);

/**
 * Set the background color
 */
void terminal_set_background_color(terminal_color_t color);


#endif /* TERMINAL_H_ */
