#ifndef RANGE_CHECK_H
#define RANGE_CHECK_H

#include <stdbool.h>

bool is_value_in_range(float value, float min, float max);
bool check_warning(const char *paramName, float value, float min, float max, float lowerTolerance, float upperTolerance);
bool check_error(const char *paramName, float value, float min, float max);
void check_warning_and_error(const char *paramName, float value, float min, float max, float lowerTolerance, float upperTolerance);

#endif // RANGE_CHECK_H

