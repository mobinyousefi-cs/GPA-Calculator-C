/**
 * Project: GPA Calculator (C)
 * File: grade_scale.h
 * Author: Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created: 2025-11-16
 * Updated: 2025-11-16
 * License: MIT License (see LICENSE file for details)
 */

#ifndef GRADE_SCALE_H
#define GRADE_SCALE_H

/**
 * Converts a raw grade input (letter or numeric string) into grade points.
 *
 * Supported formats:
 *   - Letter grades: "A", "A-", "B+", ..., "F" (case-insensitive).
 *   - Numeric grades: "0"–"100" (integer or decimal).
 *
 * If the input is not recognized as a valid grade, returns a negative value.
 *
 * @param input  Null-terminated C string representing the grade.
 * @return Grade points (0.0–4.0, etc.) on success, negative on error.
 */
double grade_to_points(const char *input);

#endif /* GRADE_SCALE_H */
