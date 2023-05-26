#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"

int main() {
    vector v = createVector(10);
    v.data[5] = 1;

    reserve(&v, 22);
    printf("%d\n", v.data[5]);


    return 0;
}