#ifndef __OUTPUT_H__
#define __OUTPUT_H__

#include "test.h"

inline static void __red() {
    printf("\033[1;31m");
}

inline static void __green() {
    printf("\033[0;32m");
}

inline static void __white() {
    printf("\033[0;37m"); 
}

void print_failed(test* failed_test);
void print_access(test* access_test);

#endif