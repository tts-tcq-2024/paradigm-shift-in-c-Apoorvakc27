#include <stdio.h>
#include <stdbool.h>
#include "range_check.h"

bool is_value_in_range(float value, float min, float max) {
    return (value >= min) && (value <= max);
}

bool check_warning(const char *paramName, float value, float min, float max, float lowerTolerance, float upperTolerance) {
    if (value > max - upperTolerance) {
        printf("Warning: %s %.6f is breaching upper limit\n", paramName, value);
        return true;
    } else if (value < min + lowerTolerance) {
        printf("Warning: %s %.6f is breaching lower limit\n", paramName, value);
        return true;
    }
    return false;
}

bool check_error(const char *paramName, float value, float min, float max) {
    if (value < min || value > max) {
        printf("Error: %s %.6f is out of range\n", paramName, value);
        return true; // Error found
    }
    return false; // No error
}

void check_warning_and_error(const char *paramName, float value, float min, float max, float lowerTolerance, float upperTolerance) {
    if (check_warning(paramName, value, min, max, lowerTolerance, upperTolerance)) {
        check_error(paramName, value, min, max);
    }
}
