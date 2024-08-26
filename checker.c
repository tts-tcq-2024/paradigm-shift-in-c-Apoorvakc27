#include <stdio.h>
#include <assert.h>

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int out_of_range = 0;

    // Single decision point to check for all conditions
    if (temperature < 0 ||  temperature > 45 ||  soc < 20 || soc > 80 || chargeRate > 0.8) {
      
        // Print the variable if there condition is out of range
        if (temperature < 0 || temperature > 45) {
            printf("temperature out of range\n");
        }
        if (soc < 20 || soc > 80) {
            printf("soc out of range\n");
        }
        if (chargeRate > 0.8) {
            printf("chargeRate out of range\n");
        }
        out_of_range = 1; // Set to 1 if any condition is out of range
    }

    // Return 0 if any condition is out of range, otherwise return 1
    return !out_of_range;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));  // Should return 1 (no condition out of range, no output)
    assert(!batteryIsOk(50, 85, 0));
    assert(!batteryIsOk(-4, 90, 1)); // Should return 0 (one or more conditions out of range, output messages)
    return 0;
}
