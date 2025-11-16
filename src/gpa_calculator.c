/**
 * Project: GPA Calculator (C)
 * File: gpa_calculator.c
 * Author: Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created: 2025-11-16
 * Updated: 2025-11-16
 * License: MIT License (see LICENSE file for details)
 */

#include "gpa_calculator.h"

#include <stddef.h>

double calculate_gpa(const Course *courses,
                     size_t count,
                     double *total_credits,
                     double *total_points)
{
    double credits_sum = 0.0;
    double points_sum = 0.0;

    if (courses == NULL || count == 0) {
        if (total_credits) {
            *total_credits = 0.0;
        }
        if (total_points) {
            *total_points = 0.0;
        }
        return 0.0;
    }

    for (size_t i = 0; i < count; ++i) {
        const Course *c = &courses[i];
        if (c->credits <= 0.0) {
            continue; /* Ignore non-credit courses */
        }

        credits_sum += c->credits;
        points_sum += c->credits * c->grade_points;
    }

    if (total_credits) {
        *total_credits = credits_sum;
    }
    if (total_points) {
        *total_points = points_sum;
    }

    if (credits_sum <= 0.0) {
        return 0.0;
    }

    return points_sum / credits_sum;
}
