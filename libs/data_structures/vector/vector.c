
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
void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        v->capacity = 0;
        v->size = 0;
        return;
    }
    if (newCapacity <= v->size) {
        v->size = newCapacity;
        v->capacity = newCapacity;
        return;
    }
    int* new_data = (int*)malloc(newCapacity * sizeof(int));
    for (int i = 0; i < v->size; ++i) {
        new_data[i] = v->data[i];
    }
    free(v->data);
    v->data = new_data;
    v->capacity = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}