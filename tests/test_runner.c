#include <assert.h>
#include <stdio.h>
#include "vector.h"
#include "csv.h"
#include "stats.h"

int main(void){
    IntVector v; vec_init(&v);
    vec_push(&v, 3); vec_push(&v, 7); vec_push(&v, 5);
    assert(v.size==3);
    assert((int)(vec_mean(&v)+0.5)==5); // ~5.0

    double med = stats_median(&v); // 3,5,7 -> 5
    assert((int)(med+0.5)==5);

    IntVector v2; vec_init(&v2);
    int n = csv_parse_ints_line("1,2, 100, -3, abc, 7", &v2);
    assert(n==5);
    assert(v2.data[0]==1 && v2.data[2]==100 && v2.data[3]==-3);

    vec_free(&v); vec_free(&v2);
    printf("OK tests\n");
    return 0;
}
