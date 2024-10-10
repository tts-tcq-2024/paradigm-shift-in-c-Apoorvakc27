#ifndef BATTERY_CHECK_H
#define BATTERY_CHECK_H

bool evaluate_checks(bool tempCheck, bool socCheck, bool chargeRateCheck);
bool batteryIsOk(float temperature, float soc, float chargeRate);

#endif // BATTERY_CHECK_H
