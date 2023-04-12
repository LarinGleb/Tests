#include <stdio.h>

#include "output.h"

void print_failed(test* failed_test) {
    __red();
    printf("FAIL test. Name: %s. Group: %s \n", failed_test->name_test, failed_test->group_name_test);
    __white();
}
void print_access(test* access_test) {
    __red();
    printf("ACCESS test. Name: %s. Group: %s \n", access_test->name_test, access_test->group_name_test);
    __white();
}