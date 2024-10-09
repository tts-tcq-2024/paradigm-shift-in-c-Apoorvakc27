#ifndef BATTERY_CHECK_H
#define BATTERY_CHECK_H

int batteryIsOk(float temperature, float soc, float chargeRate);
int evaluate_checks(int tempCheck, int socCheck, int chargeRateCheck);

#endif // BATTERY_CHECK_H
