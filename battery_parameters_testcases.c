#include <assert.h>
#include "battery_check.h"

void runAllTests() {
    // Temperature Tests
    assert(batteryIsOk(25, 70, 0.7)); // All values within range
    assert(!batteryIsOk(50, 70, 0.7)); // Temperature out of range
    assert(batteryIsOk(41, 70, 0.7)); // Temperature warning (approaching upper limit)
    assert(batteryIsOk(3, 70, 0.7)); // Temperature warning (approaching lower limit)

    // SOC Tests
    assert(batteryIsOk(25, 70, 0.7)); // All values within range
    assert(!batteryIsOk(25, 85, 0.7)); // SOC out of range (above maximum)
    assert(!batteryIsOk(25, 15, 0.7)); // SOC out of range (below minimum)
    assert(batteryIsOk(25, 76, 0.7)); // SOC warning (approaching upper limit)
    assert(batteryIsOk(25, 24, 0.7)); // SOC warning (approaching lower limit)

    // Charge Rate Tests
    assert(batteryIsOk(25, 70, 0.7)); // All values within range
    assert(!batteryIsOk(25, 70, 0.9)); // Charge rate out of range
    assert(batteryIsOk(25, 70, 0.75)); // Charge rate warning (approaching upper limit)
}
