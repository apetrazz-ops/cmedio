#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "stats.h"

int main(void) {
    // --- Codice normale ---
    IntVector v;
    vec_init(&v);
    vec_push(&v, 10);
    vec_push(&v, 20);
    printf("Mean: %f\n", vec_mean(&v));

    // --- Vulnerabilità intenzionali ---
    char buf[10];
    buf[20] = 'A'; // buffer overflow

    int* leak = malloc(5 * sizeof(int)); // memory leak
    // non facciamo mai free(leak)

    return 0;
}
