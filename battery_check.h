#ifndef BATTERY_CHECK_H
#define BATTERY_CHECK_H
#include <stdbool.h>

bool batteryIsOk(float temperature, float soc, float chargeRate);

#endif // BATTERY_CHECK_H
