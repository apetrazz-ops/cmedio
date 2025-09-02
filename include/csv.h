#ifndef CSV_H
#define CSV_H
#include "vector.h"

// Parsifica una riga CSV con numeri interi separati da virgola e li mette nel vettore.
int csv_parse_ints_line(const char *line, IntVector *out);

#endif
