/**
 * Project: GPA Calculator (C)
 * File: grade_scale.c
 * Author: Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created: 2025-11-16
 * Updated: 2025-11-16
 * License: MIT License (see LICENSE file for details)
 */

#include "grade_scale.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/* Internal helpers -------------------------------------------------------- */

static void trim_whitespace(char *s)
{
    if (s == NULL) {
        return;
    }

    size_t len = strlen(s);
    while (len > 0 && (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n' || s[len - 1] == '\r')) {
        s[--len] = '\0';
    }

    size_t start = 0U;
    while (s[start] == ' ' || s[start] == '\t') {
        ++start;
    }

    if (start > 0U) {
        size_t i = 0U;
        while (s[start + i] != '\0') {
            s[i] = s[start + i];
            ++i;
        }
        s[i] = '\0';
    }
}

static int contains_alpha(const char *s)
{
    if (s == NULL) {
        return 0;
    }
    for (; *s != '\0'; ++s) {
        if (isalpha((unsigned char)*s)) {
            return 1;
        }
    }
    return 0;
}

static double letter_to_points(const char *grade)
{
    if (grade == NULL) {
        return -1.0;
    }

    char buf[8];
    memset(buf, 0, sizeof(buf));

    /* Copy and normalize to uppercase */
    size_t len = strlen(grade);
    if (len >= sizeof(buf)) {
        len = sizeof(buf) - 1U;
    }

    for (size_t i = 0; i < len; ++i) {
        buf[i] = (char)toupper((unsigned char)grade[i]);
    }
    buf[len] = '\0';

    if (strcmp(buf, "A+") == 0 || strcmp(buf, "A") == 0) return 4.0;
    if (strcmp(buf, "A-") == 0) return 3.7;
    if (strcmp(buf, "B+") == 0) return 3.3;
    if (strcmp(buf, "B") == 0)  return 3.0;
    if (strcmp(buf, "B-") == 0) return 2.7;
    if (strcmp(buf, "C+") == 0) return 2.3;
    if (strcmp(buf, "C") == 0)  return 2.0;
    if (strcmp(buf, "C-") == 0) return 1.7;
    if (strcmp(buf, "D+") == 0) return 1.3;
    if (strcmp(buf, "D") == 0)  return 1.0;
    if (strcmp(buf, "F") == 0)  return 0.0;

    return -1.0;
}

static double numeric_to_points(double numeric)
{
    /* Simple numeric-to-GPA mapping; adapt to your own scale if needed. */
    if (numeric < 0.0 || numeric > 100.0) {
        return -1.0;
    }

    if (numeric >= 90.0) return 4.0;   /* A */
    if (numeric >= 85.0) return 3.7;   /* A- */
    if (numeric >= 80.0) return 3.3;   /* B+ */
    if (numeric >= 75.0) return 3.0;   /* B */
    if (numeric >= 70.0) return 2.7;   /* B- */
    if (numeric >= 65.0) return 2.3;   /* C+ */
    if (numeric >= 60.0) return 2.0;   /* C */
    if (numeric >= 55.0) return 1.7;   /* C- */
    if (numeric >= 50.0) return 1.0;   /* D */

    return 0.0; /* F */
}

/* Public API -------------------------------------------------------------- */

double grade_to_points(const char *input)
{
    if (input == NULL) {
        return -1.0;
    }

    char buf[32];
    memset(buf, 0, sizeof(buf));

    size_t len = strlen(input);
    if (len >= sizeof(buf)) {
        len = sizeof(buf) - 1U;
    }
    memcpy(buf, input, len);
    buf[len] = '\0';

    trim_whitespace(buf);

    if (buf[0] == '\0') {
        return -1.0;
    }

    if (contains_alpha(buf)) {
        return letter_to_points(buf);
    }

    char *endptr = NULL;
    double numeric = strtod(buf, &endptr);
    if (endptr == buf || *endptr != '\0') {
        return -1.0;
    }

    return numeric_to_points(numeric);
}
