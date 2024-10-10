#include <stdio.h>
#include <stdbool.h>
#include "battery_parameters_testcases.h"

int main() {
    bool allTestsPassed = runAllTests();
    return allTestsPassed ? 0 : 1; // Return 0 if all tests pass, 1 otherwise
}

