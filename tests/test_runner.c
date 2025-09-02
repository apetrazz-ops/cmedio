#include <stdio.h>
#include <assert.h>
#include "vector.h"
#include "stats.h"

int main(void) {
    printf("Running simple tests...\n");

    // Test vector
    Vec v;
    vec_init(&v);
    vec_push(&v, 10);
    vec_push(&v, 20);
    assert(v.size == 2);
    assert(v.data[0] == 10);
    assert(v.data[1] == 20);

    // Test stats
    double mean = vec_mean(&v);
    assert(mean == 15.0);

    double median = stats_median(&v);
    assert(median == 15.0);

    vec_free(&v);

    printf("All tests passed!\n");
    return 0;
}
