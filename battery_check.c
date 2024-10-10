#include <stdio.h>
#include "battery_check.h"
#include "soc_check.h"
#include "temperature_check.h"
#include "charge_rate_check.h"



// Function to evaluate the result of all checks
bool evaluate_checks(bool tempCheck, bool socCheck, bool chargeRateCheck) {
    return tempCheck && socCheck && chargeRateCheck;
}

// Combined function to check all parameters
bool batteryIsOk(float temperature, float soc, float chargeRate) {
    bool tempCheck = check_temperature(temperature);
    bool socCheck = check_soc(soc);
    bool chargeRateCheck = check_chargeRate(chargeRate);

    return evaluate_checks(tempCheck, socCheck, chargeRateCheck);
}
