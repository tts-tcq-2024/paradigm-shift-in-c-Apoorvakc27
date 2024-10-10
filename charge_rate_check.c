#include <stdio.h>
#include <stdbool.h>
#include "charge_rate_check.h"
#include "range_check.h"

bool check_chargeRate(float chargeRate) {
    float maxChargeRate = 0.8, tolerance = 0.08; // 10% tolerance
    bool isInRange = is_value_in_range(chargeRate, 0.0, maxChargeRate);
    check_warning_and_error("Charge Rate", chargeRate, 0.0, maxChargeRate, tolerance, tolerance);

    return isInRange;
}
