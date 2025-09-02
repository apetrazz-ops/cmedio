#include "stats.h"
#include <stdlib.h>

static int cmp_int(const void *a, const void *b){
    int ia=*(const int*)a, ib=*(const int*)b;
    return (ia>ib) - (ia<ib);
}

void stats_sort_copy(const IntVector *v, int **out_arr, size_t *out_n){
    *out_n = v->size;
    *out_arr = (int*)malloc(v->size * sizeof(int));
    for(size_t i=0;i<v->size;i++) (*out_arr)[i]=v->data[i];
    qsort(*out_arr, v->size, sizeof(int), cmp_int);
}

double stats_median(const IntVector *v){
    if(v->size==0) return 0.0;
    int *arr=NULL; size_t n=0;
    stats_sort_copy(v, &arr, &n);
    double med = (n%2==1) ? arr[n/2] : (arr[n/2-1] + arr[n/2]) / 2.0;
    free(arr);
    return med;
}
