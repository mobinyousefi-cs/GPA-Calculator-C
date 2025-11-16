/**
 * Project: GPA Calculator (C)
 * File: main.c
 * Author: Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created: 2025-11-16
 * Updated: 2025-11-16
 * License: MIT License (see LICENSE file for details)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gpa_calculator.h"
#include "grade_scale.h"
#include "input_utils.h"

#define MAX_COURSES 50

static void print_banner(void)
{
    printf("===============================\n");
    printf("     GPA Calculator (C)\n");
    printf("===============================\n\n");
}

int main(void)
{
    print_banner();

    for (;;) {
        int course_count = read_int_in_range(
            "Enter number of courses (1-50): ", 1, MAX_COURSES);

        Course *courses = (Course *)calloc((size_t)course_count, sizeof(Course));
        if (courses == NULL) {
            fprintf(stderr, "Error: Failed to allocate memory for courses.\n");
            return EXIT_FAILURE;
        }

        for (int i = 0; i < course_count; ++i) {
            char grade_input[32];

            printf("\n--- Course %d ---%n", i + 1, &(int){0});
            printf("\n");

            read_string("Course name: ", courses[i].name, sizeof(courses[i].name));

            courses[i].credits = read_double_in_range(
                "Credit hours (0.5–10.0): ", 0.5, 10.0);

            /* Read and validate grade */
            for (;;) {
                read_string(
                    "Grade (letter like A- or numeric 0–100): ",
                    grade_input,
                    sizeof(grade_input));

                double gp = grade_to_points(grade_input);
                if (gp < 0.0) {
                    printf("Invalid grade input. Please try again.\n");
                } else {
                    courses[i].grade_points = gp;
                    break;
                }
            }
        }

        double total_credits = 0.0;
        double total_points = 0.0;
        double gpa = calculate_gpa(
            courses,
            (size_t)course_count,
            &total_credits,
            &total_points);

        printf("\n--------------------------------\n");
        printf("Total credits: %.2f\n", total_credits);
        printf("Total grade points: %.2f\n", total_points);
        if (total_credits > 0.0) {
            printf("GPA: %.2f\n", gpa);
        } else {
            printf("GPA: N/A (no credits)\n");
        }
        printf("--------------------------------\n\n");

        free(courses);

        if (!read_yes_no("Do you want to calculate GPA for another student? (y/n): ")) {
            printf("\nGoodbye!\n");
            break;
        }

        printf("\n");
    }

    return EXIT_SUCCESS;
}
