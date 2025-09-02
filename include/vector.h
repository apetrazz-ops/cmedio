#ifndef VECTOR_H
#define VECTOR_H
#include <stddef.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} IntVector;

void vec_init(IntVector *v);
void vec_free(IntVector *v);
void vec_push(IntVector *v, int value);
int  vec_pop(IntVector *v, int *ok);
double vec_mean(const IntVector *v);

#endif

