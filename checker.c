#include <stdio.h>
#include <assert.h>

// Separate the check for temperature out of range
int is_temperature_in_range(float temperature) {
    return (temperature >= 0) && (temperature <= 45);
}

// Function to check if temperature is within range
int check_temperature(float temperature) {
    int isInRange = is_temperature_in_range(temperature);
    if (!isInRange) {
        printf("temperature out of range\n");
    }
    return isInRange;
}

// Separate the check for SOC out of range
int is_soc_in_range(float soc) {
    return (soc >= 20) && (soc <= 80);
}

// Function to check if SOC is within range
int check_soc(float soc) {
    int isInRange = is_soc_in_range(soc);
    if (!isInRange) {
        printf("soc out of range\n");
    }
    return isInRange;
}

// Separate the check for chargeRate out of range
int is_chargeRate_in_range(float chargeRate) {
    return chargeRate <= 0.8;
}

// Function to check if chargeRate is within range
int check_chargeRate(float chargeRate) {
    int isInRange = is_chargeRate_in_range(chargeRate);
    if (!isInRange) {
        printf("chargeRate out of range\n");
    }
    return isInRange;
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
