#ifndef RANGE_CHECK_H
#define RANGE_CHECK_H

int is_value_in_range(float value, float min, float max);
void check_warning_and_error(const char *paramName, float value, float min, float max, float lowerTolerance, float upperTolerance);
int check_temperature(float temperature);
int check_soc(float soc);
int check_chargeRate(float chargeRate);
int check_error(const char *paramName, float value, float min, float max);


#endif // RANGE_CHECK_H
