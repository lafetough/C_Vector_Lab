#ifndef C_VECTOR_LAB_VOIDVECTOR_H
#define C_VECTOR_LAB_VOIDVECTOR_H

#include <stdlib.h>
#include <limits.h>

typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
} vectorVoid;



#endif //C_VECTOR_LAB_VOIDVECTOR_H
