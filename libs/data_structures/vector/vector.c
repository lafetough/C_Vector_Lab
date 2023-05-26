
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

vector createVector(size_t n) {
    vector res;
    res.data = (int*)malloc(n * sizeof(int));

    if (res.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    res.capacity = n;
    res.size = n;
    return res;
}