#include "../inc/header.h"

int rng(int min, int max) {
    return rand() % (max - min + 1) + min;
}

