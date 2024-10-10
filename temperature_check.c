#include <stdio.h>
#include <stdbool.h>
#include "temperature_check.h"
#include "range_check.h"

bool check_temperature(float temperature) {
    float minTemp = 0.0, maxTemp = 45.0, tolerance = 5.0; // 10% tolerance
    bool isInRange = is_value_in_range(temperature, minTemp, maxTemp);
    check_warning_and_error("Temperature", temperature, minTemp, maxTemp, tolerance, tolerance);

    return isInRange;
}

