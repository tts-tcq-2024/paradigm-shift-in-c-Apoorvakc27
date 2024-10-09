
#include <stdio.h>
#include "range_check.h"

// General range check function
int is_value_in_range(float value, float min, float max) {
    return (value >= min) && (value <= max);
}

// Function to check errors based on range
int check_error(const char *paramName, float value, float min, float max) {
    if (value < min || value > max) {
        printf("Error: %s %.6f is out of range\n", paramName, value);
        return 1; // Error found
    }
    return 0; // No error
}

// Function to check warnings based on tolerance
void check_warning(const char *paramName, float value, float min, float max, float lowerTolerance, float upperTolerance) {
    if (value > max - upperTolerance) {
         printf("Warning: %s %.6f is breaching upper limit\n", paramName, value);
    } else if (value < min + lowerTolerance) {
        printf("Warning: %s %.6f is breaching lower limit\n", paramName, value);
    }
}

// Refactored function to handle both error and warning messages
void check_error_or_warning(const char *paramName, float value, float min, float max, float lowerTolerance, float upperTolerance) {
    if (!check_error(paramName, value, min, max)) {
        // Only check for warnings if no error is found
        check_warning(paramName, value, min, max, lowerTolerance, upperTolerance);
    }
}

// Check if temperature is within range and issue warnings or errors if necessary
int check_temperature(float temperature) {
    float minTemp = 0.0, maxTemp = 45.0, tolerance = 5.0; // 10% tolerance
    int isInRange = is_value_in_range(temperature, minTemp, maxTemp);
    check_error_or_warning("Temperature", temperature, minTemp, maxTemp, tolerance, tolerance);

    return isInRange;
}

// Check if SOC is within range and issue warnings or errors if necessary
int check_soc(float soc) {
    float minSoc = 20.0;
    float maxSoc = 80.0;
    float minTolerance = 2.0;  // 10% of minSoc
    float maxTolerance = 8.0;  // 10% of maxSoc

    int isInRange = is_value_in_range(soc, minSoc, maxSoc);
    check_error_or_warning("SOC", soc, minSoc, maxSoc, minTolerance, maxTolerance);

    return isInRange;
}

// Check if charge rate is within range and issue warnings or errors if necessary
int check_chargeRate(float chargeRate) {
    float maxChargeRate = 0.8, tolerance = 0.08; // 10% tolerance
    int isInRange = is_value_in_range(chargeRate, 0.0, maxChargeRate);
    check_error_or_warning("Charge Rate", chargeRate, 0.0, maxChargeRate, tolerance, tolerance);

    return isInRange;
}

