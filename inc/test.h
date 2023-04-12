#ifndef __ADD_TEST__
#define __ADD_TEST__

#include <stdio.h>

#define EXCEPT_TRUE(__l_value__, __r_value__) __l_value__ == __r_value
#define EXCEPT_FALSE(__l_value__, __r_value__) __l_value__ != __r_value

typedef int (*test_func)();

struct __test_s
{
    char* name_test;
    char* group_name_test;
    test_func test_f; 
};
typedef struct __test_s test;

extern test* GLOBAL_TESTS;
extern size_t GLOBAL_COUNT;

test* test_constructor(char* name_test, char* group_name_test, test_func* test);
void test_free(test* free_test);

void add_test(test* new_test);
void run_all_tests();

#endif