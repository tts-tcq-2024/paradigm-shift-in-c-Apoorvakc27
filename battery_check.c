#include <stdio.h>
#include "battery_check.h"
#include "range_check.h"

// Function to evaluate the result of all checks
int evaluate_checks(int tempCheck, int socCheck, int chargeRateCheck) {
    return tempCheck * socCheck * chargeRateCheck;
}

// Combined function to check all parameters
int batteryIsOk(float temperature, float soc, float chargeRate) {
    int tempCheck = check_temperature(temperature);
    int socCheck = check_soc(soc);
    int chargeRateCheck = check_chargeRate(chargeRate);

    return evaluate_checks(tempCheck, socCheck, chargeRateCheck);
}
