#include "vector.h"
#include <stdlib.h>

static int vec_grow(IntVector *v, size_t mincap) {
    size_t newcap = v->capacity ? v->capacity : 8;
    while (newcap < mincap) newcap *= 2;
    int *p = (int*)realloc(v->data, newcap * sizeof(int));
    if (!p) return 0;
    v->data = p;
    v->capacity = newcap;
    return 1;
}

void vec_init(IntVector *v){
    v->data=NULL; v->size=0; v->capacity=0;
}

void vec_free(IntVector *v){
    free(v->data); v->data=NULL; v->size=0; v->capacity=0;
}

void vec_push(IntVector *v, int value){
    if (v->size+1 > v->capacity) vec_grow(v, v->size+1);
    v->data[v->size++] = value;
}

int vec_pop(IntVector *v, int *ok){
    if (v->size==0){ if(ok)*ok=0; return 0; }
    if(ok)*ok=1;
    return v->data[--v->size];
}

double vec_mean(const IntVector *v){
    if (v->size==0) return 0.0;
    long long sum=0;
    for(size_t i=0;i<v->size;i++) sum+=v->data[i];
    return (double)sum / (double)v->size;
}
