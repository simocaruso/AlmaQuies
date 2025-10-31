//
// Created by simone on 31/10/25.
//

#include "util.hpp"
#include <iostream>

void must_init(bool test, const char* description) {
    if (test) return;
    printf("Couldn't initialize %s\n", description);
    exit(1);
}