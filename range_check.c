#include <stdio.h>
#include "range_check.h"

// General range check function
int is_value_in_range(float value, float min, float max) {
    return (value >= min) && (value <= max);
}

// Function to print errors or warnings based on tolerance and range
void check_error_or_warning(const char *paramName, float value, float min, float max, float tolerance) {
    if (value < min || value > max) {
        printf("Error: %s %.6f is out of range\n", paramName, value);
    } else if (value > max - tolerance) {
        printf("Warning: %s %.6f is breaching upper limit\n", paramName, value);
    } else if (value < min + tolerance) {
        printf("Warning: %s %.6f is breaching lower limit\n", paramName, value);
    }
}

// Check if temperature is within range and issue warnings or errors if necessary
int check_temperature(float temperature) {
    float minTemp = 0.0, maxTemp = 45.0, tolerance = 5; // 10% tolerance
    int isInRange = is_value_in_range(temperature, minTemp, maxTemp);
    check_error_or_warning("Temperature", temperature, minTemp, maxTemp, tolerance);
    
    return isInRange;
}

// Check if SOC is within range and issue warnings or errors if necessary
int check_soc(float soc) {
    float minSoc = 20.0, maxSoc = 80.0, tolerance = 4.0; // 10% tolerance
    int isInRange = is_value_in_range(soc, minSoc, maxSoc);
    check_error_or_warning("SOC", soc, minSoc, maxSoc, tolerance);

    return isInRange;
}

// Check if charge rate is within range and issue warnings or errors if necessary
int check_chargeRate(float chargeRate) {
    float maxChargeRate = 0.8, tolerance = 0.08; // 10% tolerance
    int isInRange = is_value_in_range(chargeRate, 0.0, maxChargeRate);
    check_error_or_warning("Charge Rate", chargeRate, 0.0, maxChargeRate, tolerance);

    return isInRange;
}
