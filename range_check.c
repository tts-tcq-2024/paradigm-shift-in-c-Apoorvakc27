#include <stdio.h>
#include "range_check.h"

// General range check function
bool is_value_in_range(float value, float min, float max) {
    return (value >= min) && (value <= max);
}

// Function to check warnings based on tolerance
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

// Function to check errors based on range
bool check_error(const char *paramName, float value, float min, float max) {
    if (value < min || value > max) {
        printf("Error: %s %.6f is out of range\n", paramName, value);
        return true; // Error found
    }
    return false; // No error
}

// Refactored function to handle both warning and error messages
void check_warning_and_error(const char *paramName, float value, float min, float max, float lowerTolerance, float upperTolerance) {
    // Check for warnings first
    if (check_warning(paramName, value, min, max, lowerTolerance, upperTolerance)) {
        // Then check for errors regardless of the warning status
        check_error(paramName, value, min, max);
    }
}

// Check if temperature is within range and issue warnings or errors if necessary
bool check_temperature(float temperature) {
    float minTemp = 0.0, maxTemp = 45.0, tolerance = 5.0; // 10% tolerance
    bool isInRange = is_value_in_range(temperature, minTemp, maxTemp);
    check_warning_and_error("Temperature", temperature, minTemp, maxTemp, tolerance, tolerance);

    return isInRange;
}

// Check if SOC is within range and issue warnings or errors if necessary
bool check_soc(float soc) {
    float minSoc = 20.0;
    float maxSoc = 80.0;
    float minTolerance = 2.0;  // 10% of minSoc
    float maxTolerance = 8.0;  // 10% of maxSoc

    bool isInRange = is_value_in_range(soc, minSoc, maxSoc);
    check_warning_and_error("SOC", soc, minSoc, maxSoc, minTolerance, maxTolerance);

    return isInRange;
}

// Check if charge rate is within range and issue warnings or errors if necessary
bool check_chargeRate(float chargeRate) {
    float maxChargeRate = 0.8, tolerance = 0.08; // 10% tolerance
    bool isInRange = is_value_in_range(chargeRate, 0.0, maxChargeRate);
    check_warning_and_error("Charge Rate", chargeRate, 0.0, maxChargeRate, tolerance, tolerance);

    return isInRange;
}
