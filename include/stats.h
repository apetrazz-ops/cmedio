#ifndef STATS_H
#define STATS_H
#include "vector.h"

double stats_median(const IntVector *v);   // calcola mediana (copia e ordina)
void   stats_sort_copy(const IntVector *v, int **out_arr, size_t *out_n);

#endif
