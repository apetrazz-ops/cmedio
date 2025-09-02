#include "csv.h"
#include "strutil.h"
#include <stdlib.h>
#include <string.h>

int csv_parse_ints_line(const char *line, IntVector *out){
    IntVector tmp; vec_init(&tmp);
    size_t n=0; 
    char *dup = strdup(line);
    if(!dup) return 0;
    char *work = str_trim(dup);
    size_t cnt=0;
    char **parts = str_split(work, ',', &cnt);
    if(!parts){ free(dup); return 0; }

    for(size_t i=0;i<cnt;i++){
        char *t = str_trim(parts[i]);
        char *end=NULL;
        long v = strtol(t, &end, 10);
        if (end==t){ /* non è numero */ continue; }
        vec_push(&tmp, (int)v);
        n++;
    }

    for(size_t i=0;i<tmp.size;i++) vec_push(out, tmp.data[i]);
    str_split_free(parts, cnt);
    free(dup);
    vec_free(&tmp);
    return (int)n;
}
