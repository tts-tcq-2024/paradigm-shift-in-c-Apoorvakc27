#include <assert.h>
#include "battery_check.h"

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 88, 0));
    assert(!batteryIsOk(25, 85, 0.7));
    assert(batteryIsOk(44, 26, 0.2));
    return 0;
}
