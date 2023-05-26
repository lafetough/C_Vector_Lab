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

void test_atVector_notEmptyVector() {
    vector v = createVector(10);
    assert(atVector(&v, 12) == NULL);
    assert(atVector(&v, -21) == NULL);
    *atVector(&v, 6) = 123;
    assert(v.data[6] == 123);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(10);
    assert(atVector(&v, 10) == NULL);
}

void test_back_oneElementInVector() {
    vector v = createVector(0);
    assert(back(&v) == NULL);
    pushBack(&v, 1);
    assert(*back(&v) == 1);
}

void test_front_oneElementInVector() {
    vector v = createVector(0);
    assert(front(&v) == NULL);
    pushBack(&v, 1);
    assert(*front(&v) == 1);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();
    return 0;
}