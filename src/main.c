#include <stdio.h>
#include <string.h>
#include "vector.h"
#include "csv.h"
#include "stats.h"

int main(void){
    // Esempio: riga CSV con interi
    const char *line = "10, 5,  7, 21,  3, 3, 9";
    IntVector v; vec_init(&v);
    csv_parse_ints_line(line, &v);

    printf("Letti %zu numeri. Media=%.2f, Mediana=%.2f\n",
           v.size, vec_mean(&v), stats_median(&v));

    // Stampa valori
    printf("Valori:");
    for(size_t i=0;i<v.size;i++) printf(" %d", v.data[i]);
    printf("\n");

    vec_free(&v);
    return 0;
}
