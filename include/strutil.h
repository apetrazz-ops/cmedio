#ifndef STRUTIL_H
#define STRUTIL_H
#include <stddef.h>

char *str_trim(char *s);                 // trim in-place (spazi iniziali/finali)
char **str_split(const char *s, char delim, size_t *out_count);
void str_split_free(char **arr, size_t count);

#endif
