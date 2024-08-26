#include <stdio.h>
#include <assert.h>

int batteryIsOk(float temperature, float soc, float chargeRate) {
    // Check if any condition is out of range
    int out_of_range = (temperature < 0 || temperature > 45) || (soc < 20 || soc > 80) || (chargeRate > 0.8);

    // Print statements for each condition
    printf("temperature %s\n", (temperature < 0 || temperature > 45) ? "out of range" : "in range");
    printf("soc %s\n", (soc < 20 || soc > 80) ? "out of range" : "in range");
    printf("chargeRate %s\n", (chargeRate > 0.8) ? "out of range" : "in range");

    // Return 0 if any condition is out of range, otherwise return 1
    return !out_of_range;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));  // Should return 1 (all conditions false)
    assert(!batteryIsOk(50, 85, 0));   // Should return 0 (one or more conditions true)
}
