#include "strutil.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *str_trim(char *s){
    if(!s) return s;
    size_t n = strlen(s);
    size_t i=0, j=n;
    while(i<n && isspace((unsigned char)s[i])) i++;
    while(j>i && isspace((unsigned char)s[j-1])) j--;
    size_t len = j - i;
    if(i>0) memmove(s, s+i, len);
    s[len]='\0';
    return s;
}

char **str_split(const char *s, char delim, size_t *out_count){
    *out_count = 0;
    if(!s) return NULL;
    // Conta sezioni
    size_t count = 1;
    for(const char *p=s; *p; ++p) if(*p==delim) count++;
    char **arr = (char**)malloc(count * sizeof(char*));
    if(!arr) return NULL;

    const char *start = s;
    size_t idx=0;
    for(const char *p=s;;++p){
        if(*p==delim || *p=='\0'){
            size_t len = (size_t)(p-start);
            char *token = (char*)malloc(len+1);
            if(!token){ for(size_t k=0;k<idx;k++) free(arr[k]); free(arr); return NULL; }
            memcpy(token, start, len);
            token[len]='\0';
            arr[idx++] = token;
            if(*p=='\0') break;
            start = p+1;
        }
    }
    *out_count = idx;
    return arr;
}

void str_split_free(char **arr, size_t count){
    if(!arr) return;
    for(size_t i=0;i<count;i++) free(arr[i]);
    free(arr);
}
