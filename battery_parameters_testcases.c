#include <assert.h>
#include <stdbool.h>  // Include for boolean types
#include "battery_check.h"

bool runAllTests() {
    bool allTestsPassed = true;

    // Temperature Tests
    allTestsPassed &= batteryIsOk(25, 70, 0.7);   // All values within range
    allTestsPassed &= !batteryIsOk(50, 70, 0.7);  // Temperature out of range
    allTestsPassed &= batteryIsOk(41, 70, 0.7);   // Temperature warning (approaching upper limit)
    allTestsPassed &= batteryIsOk(3, 70, 0.7);    // Temperature warning (approaching lower limit)

    // SOC Tests
    allTestsPassed &= batteryIsOk(25, 70, 0.7);   // All values within range
    allTestsPassed &= !batteryIsOk(25, 85, 0.7);  // SOC out of range (above maximum)
    allTestsPassed &= !batteryIsOk(25, 15, 0.7);  // SOC out of range (below minimum)
    allTestsPassed &= batteryIsOk(25, 76, 0.7);   // SOC warning (approaching upper limit)
    allTestsPassed &= batteryIsOk(25, 24, 0.7);   // SOC warning (approaching lower limit)

    // Charge Rate Tests
    allTestsPassed &= batteryIsOk(25, 70, 0.7);   // All values within range
    allTestsPassed &= !batteryIsOk(25, 70, 0.9);  // Charge rate out of range
    allTestsPassed &= batteryIsOk(25, 70, 0.75);  // Charge rate warning (approaching upper limit)

    return allTestsPassed;
}
