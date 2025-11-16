/**
 * Project: GPA Calculator (C)
 * File: gpa_calculator.h
 * Author: Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created: 2025-11-16
 * Updated: 2025-11-16
 * License: MIT License (see LICENSE file for details)
 */

#ifndef GPA_CALCULATOR_H
#define GPA_CALCULATOR_H

#include <stddef.h>

/**
 * Represents a single course in a student's transcript.
 */
typedef struct {
    char   name[64];      /**< Course name (short title) */
    double credits;       /**< Credit hours for the course */
    double grade_points;  /**< Grade points for the course (0.0–4.0, etc.) */
} Course;

/**
 * Calculates the credit-weighted GPA.
 *
 * @param courses         Pointer to the first element of an array of Course.
 * @param count           Number of elements in the courses array.
 * @param total_credits   Output pointer; receives the sum of credits.
 * @param total_points    Output pointer; receives the sum of (credits * grade_points).
 *
 * @return The GPA (total_points / total_credits), or 0.0 if total_credits is 0.
 */
double calculate_gpa(const Course *courses,
                     size_t count,
                     double *total_credits,
                     double *total_points);

#endif /* GPA_CALCULATOR_H */
