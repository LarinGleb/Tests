#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test.h"
#include "output.h"

test* test_constructor(char* name_test, char* group_name_test, test_func* test_f) {
    test* __test = (test*) malloc(sizeof(test));

    __test-> name_test = (char*) calloc(strlen(name_test), sizeof(char));
    strcpy(__test->name_test, name_test);

    __test-> group_name_test = (char*) calloc(strlen(group_name_test), sizeof(char));
    strcpy(__test->group_name_test, group_name_test);

    __test->test_f = *test_f;

    return __test;
}

void test_free(test* free_test) {
    free(free_test->name_test);
    free(free_test->group_name_test);
    free(free_test);
}

void add_test(test* new_test) {
    GLOBAL_COUNT++;
    test* temp_tests = (test*) calloc(GLOBAL_COUNT, sizeof(test));

    for(size_t i = 0; i < GLOBAL_COUNT-1; i ++) {
        *(temp_tests+i) = *(GLOBAL_TESTS+i);
    }

    free(GLOBAL_TESTS);

    GLOBAL_TESTS = (test*) calloc(GLOBAL_COUNT, sizeof(test));
    for(size_t i = 0; i < GLOBAL_COUNT-1; i ++) {
        *(GLOBAL_TESTS+i)= *(temp_tests+i);
    }
    free(temp_tests);
    *(GLOBAL_TESTS+GLOBAL_COUNT-1) = *new_test;
}

void run_all_tests() {
    for(size_t i = 0; i < GLOBAL_COUNT; i ++) {
        if ((GLOBAL_TESTS+i)->test_f()) {
            print_access(GLOBAL_TESTS);
        }
        else {
            print_failed(GLOBAL_TESTS);
        }
    }
}