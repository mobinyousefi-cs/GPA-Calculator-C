/**
 * Project: GPA Calculator (C)
 * File: input_utils.h
 * Author: Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created: 2025-11-16
 * Updated: 2025-11-16
 * License: MIT License (see LICENSE file for details)
 */

#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <stddef.h>

/**
 * Reads a line of input from stdin into the given buffer.
 * The trailing newline (if present) is removed.
 */
void read_line(char *buffer, size_t size);

/**
 * Reads an integer from stdin within a given inclusive range.
 * Re-prompts the user until a valid value is entered.
 */
int read_int_in_range(const char *prompt, int min, int max);

/**
 * Reads a double from stdin within a given inclusive range.
 * Re-prompts the user until a valid value is entered.
 */
double read_double_in_range(const char *prompt, double min, double max);

/**
 * Reads a non-empty string from stdin into buffer.
 * Trailing newline is removed.
 */
void read_string(const char *prompt, char *buffer, size_t size);

/**
 * Reads a yes/no question from the user.
 * Returns 1 for yes, 0 for no.
 */
int read_yes_no(const char *prompt);

#endif /* INPUT_UTILS_H */
