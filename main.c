#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"
#include <assert.h>

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    assert(v.capacity == 0);
    pushBack(&v,  4);
    assert(v.capacity == 1 && v.size == 1 && v.data[0] == 4);
}

void test_pushBack_fullVector() {
    vector v = createVector(10);
    assert(v.capacity == v.size);
    pushBack(&v, 104);
    assert(v.capacity == 20 && v.size == 11 && v.data[10] == 104);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();

}

int main() {
    test();
    return 0;
}