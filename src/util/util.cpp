//
// Created by simone on 31/10/25.
//

#include "util.hpp"
#include <iostream>

void must_init(const bool test, const char* description) {
    if (test) return;
    printf("Couldn't initialize %s\n", description);
    exit(1);
}

void error(const bool test, const char* description) {
    if (test) return;
    printf("Error: %s\n", description);
    exit(1);
}
