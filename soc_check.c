#include <stdio.h>
#include <stdbool.h>
#include "soc_check.h"
#include "range_check.h"

bool check_soc(float soc) {
    float minSoc = 20.0;
    float maxSoc = 80.0;
    float minTolerance = 2.0;  // 10% of minSoc
    float maxTolerance = 8.0;  // 10% of maxSoc

    bool isInRange = is_value_in_range(soc, minSoc, maxSoc);
    check_warning_and_error("SOC", soc, minSoc, maxSoc, minTolerance, maxTolerance);

    return isInRange;
}
