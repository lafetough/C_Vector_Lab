
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

void shrinkToFit(vector *v) {
    v->capacity = v->size;
}

void deleteVector(vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0) {
        reserve(v, 1);
    }
    if (v->capacity == v->size) {
        reserve(v, v->capacity * 2);
    }
    v->data[v->size++] = x;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Vector is empty");
        exit(1);
    }
    v->data[v->size - 1] = 0;
    v->size -= 1;
}

int* atVector(vector *v, size_t index) {
    if (v->size <= index || index < 0) {
        fprintf(stderr, "\"IndexError: a %d", index);
        fprintf(stderr, " is not exists\"\n");
        return NULL;
    }
    return &v->data[index];
}

int* back(vector *v) {
    if (v->size == 0) {
        return NULL;
    }
    return &v->data[v->size - 1];
}

int* front(vector *v) {
    if (v->size == 0) {
        return NULL;
    }
    return &v->data[0];
}