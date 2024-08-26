#include <stdio.h>
#include <assert.h>



void temp_func(void)
{
     // Print the variable if there condition is out of range
        if (temperature < 0 || temperature > 45) {
            printf("temperature out of range\n");
        }
}
void soc_func(void)
{
    if (soc < 20 || soc > 80) {
            printf("soc out of range\n");
        }
}
void chargeRate_func(void)
{
    if (chargeRate > 0.8) {
            printf("chargeRate out of range\n");
        }
}
void comparison(int *flag)
{
    if (temperature < 0 ||  temperature > 45 ||  soc < 20 || soc > 80 || chargeRate > 0.8)
    {
        flag = 1;
    }
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int out_of_range = 0;
    int flag = 0;
    // Single decision point to check for all conditions
    comparison(&flag)
     if (flag)
     {
        temp_func();
        soc_func();
        chargeRate_func();   
        out_of_range = 1; // Set to 1 if any condition is out of range
    }

    // Return 0 if any condition is out of range, otherwise return 1
    return !out_of_range;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));  // Should return 1 (no condition out of range, no output)
    assert(!batteryIsOk(50, 85, 0));
    assert(!batteryIsOk(-4, 90, 1)); // Should return 0 (one or more conditions out of range, output messages)
    return 0;
}

