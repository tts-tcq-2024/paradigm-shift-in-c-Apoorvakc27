#include <stdio.h>
#include <assert.h>

// Function to check if T is within range
int check_temperature(float temperature) {
    if (temperature < 0 || temperature > 45) {
        printf("temperature out of range\n");
        return 0;
    }
    return 1;
}

// Function to check if S is within range
int check_soc(float soc) {
    if (soc < 20 || soc > 80) {
        printf("soc out of range\n");
        return 0;
    }
    return 1;
}

// Function to check if C is within range
int check_chargeRate(float chargeRate) {
    if (chargeRate > 0.8) {
        printf("chargeRate out of range\n");
        return 0;
    }
    return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    // Call the range-checking functions
    return check_temperature(temperature) && check_soc(soc) && check_chargeRate(chargeRate);
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    //assert(!batteryIsOk(25, 85, 0.7));
    //assert(batteryIsOk(44, 26, 0.2));
    return 0;
}



