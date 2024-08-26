#include <stdio.h>
#include <assert.h>

// Function to check if temperature is below the lower limit
int is_temperature_below_min(float temperature) {
    return temperature >= 0;
}

// Function to check if temperature is above the upper limit
int is_temperature_above_max(float temperature) {
    return temperature <= 45;
}

// Combined function to check if temperature is within range
int check_temperature(float temperature) {
    int isWithinRange = is_temperature_below_min(temperature) && is_temperature_above_max(temperature);
    if (!isWithinRange) {
        printf("temperature out of range\n");
    }
    return isWithinRange;
}

// Function to check if SOC is below the lower limit
int is_soc_below_min(float soc) {
    return soc >= 20;
}

// Function to check if SOC is above the upper limit
int is_soc_above_max(float soc) {
    return soc <= 80;
}

// Combined function to check if SOC is within range
int check_soc(float soc) {
    int isWithinRange = is_soc_below_min(soc) && is_soc_above_max(soc);
    if (!isWithinRange) {
        printf("soc out of range\n");
    }
    return isWithinRange;
}

// Function to check if chargeRate is within range
int check_chargeRate(float chargeRate) {
    if (chargeRate > 0.8) {
        printf("chargeRate out of range\n");
        return 0;
    }
    return 1;
}

// Combined function to check all parameters
int batteryIsOk(float temperature, float soc, float chargeRate) {
    return check_temperature(temperature) && check_soc(soc) && check_chargeRate(chargeRate);
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    //assert(!batteryIsOk(25, 85, 0.7));
    //assert(batteryIsOk(44, 26, 0.2));
    return 0;
}
