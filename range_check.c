#include <stdio.h>
#include "range_check.h"

// General range check function
int is_value_in_range(float value, float min, float max) {
    return (value >= min) && (value <= max);
}

// Function to print warnings based on tolerance
void check_warning(const char *paramName, float value, float min, float max, float tolerance) {
    if (value > max - tolerance) {
        printf("Warning: %s is approaching the upper limit.\n", paramName);
    } else if (value < min + tolerance) {
        printf("Warning: %s is approaching the lower limit.\n", paramName);
    }
}

// Check if temperature is within range and issue warnings if close to the limit
int check_temperature(float temperature) {
    float minTemp = 0.0, maxTemp = 45.0, tolerance = 4.5; // 10% tolerance
    check_warning("Temperature", temperature, minTemp, maxTemp, tolerance);
    
    int isInRange = is_value_in_range(temperature, minTemp, maxTemp);
    if (!isInRange) {
        printf("temperature out of range\n");
    }
    return isInRange;
}

// Check if SOC is within range and issue warnings if close to the limit
int check_soc(float soc) {
    float minSoc = 20.0, maxSoc = 80.0, tolerance = 4.0; // 10% tolerance
    check_warning("SOC", soc, minSoc, maxSoc, tolerance);
    
    int isInRange = is_value_in_range(soc, minSoc, maxSoc);
    if (!isInRange) {
        printf("soc out of range\n");
    }
    return isInRange;
}

// Check if charge rate is within range and issue warnings if close to the limit
int check_chargeRate(float chargeRate) {
    float maxChargeRate = 0.8, tolerance = 0.08; // 10% tolerance
    check_warning("Charge Rate", chargeRate, 0.0, maxChargeRate, tolerance);
    
    int isInRange = is_value_in_range(chargeRate, 0.0, maxChargeRate);
    if (!isInRange) {
        printf("chargeRate out of range\n");
    }
    return isInRange;
}
