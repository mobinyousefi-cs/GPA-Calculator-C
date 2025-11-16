/**
 * Project: GPA Calculator (C)
 * File: test_gpa_calculator.c
 * Author: Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created: 2025-11-16
 * Updated: 2025-11-16
 * License: MIT License (see LICENSE file for details)
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "gpa_calculator.h"
#include "grade_scale.h"

static int double_equals(double a, double b, double eps)
{
    return fabs(a - b) <= eps;
}

static void test_grade_scale(void)
{
    /* Letter grades */
    assert(double_equals(grade_to_points("A"), 4.0, 1e-6));
    assert(double_equals(grade_to_points("a-"), 3.7, 1e-6));
    assert(double_equals(grade_to_points("B+"), 3.3, 1e-6));
    assert(double_equals(grade_to_points("c"), 2.0, 1e-6));
    assert(double_equals(grade_to_points("F"), 0.0, 1e-6));

    /* Numeric grades */
    assert(double_equals(grade_to_points("95"), 4.0, 1e-6));
    assert(double_equals(grade_to_points("87"), 3.7, 1e-6));
    assert(double_equals(grade_to_points("82"), 3.3, 1e-6));
    assert(double_equals(grade_to_points("40"), 0.0, 1e-6));

    /* Invalid input */
    assert(grade_to_points("Z") < 0.0);
    assert(grade_to_points("101") < 0.0);
}

static void test_gpa_simple(void)
{
    Course courses[3];

    /* Course 1: 3 credits, A (4.0) */
    courses[0].credits = 3.0;
    courses[0].grade_points = 4.0;

    /* Course 2: 4 credits, B (3.0) */
    courses[1].credits = 4.0;
    courses[1].grade_points = 3.0;

    /* Course 3: 2 credits, C (2.0) */
    courses[2].credits = 2.0;
    courses[2].grade_points = 2.0;

    double total_credits = 0.0;
    double total_points = 0.0;

    double gpa = calculate_gpa(courses, 3U, &total_credits, &total_points);

    /* Expected: (3*4 + 4*3 + 2*2) / (3+4+2) = 26 / 9 ≈ 2.8889 */
    assert(double_equals(total_credits, 9.0, 1e-6));
    assert(double_equals(total_points, 26.0, 1e-6));
    assert(double_equals(gpa, 26.0 / 9.0, 1e-6));
}

int main(void)
{
    test_grade_scale();
    test_gpa_simple();

    printf("All tests passed.\n");
    return 0;
}
