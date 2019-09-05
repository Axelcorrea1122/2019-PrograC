#include "strings.h"
int mi_strlen(char *cad)
{
    int c = 0;
    while(*cad){
        c++;
        cad++;
    }
    return c;
}

char* mi_strcat( char *cad, char *cad2)
{
    char *p = cad;
    char *p2 = cad2;
    while(*p)
        p++;
    while(*p2){
        *p = *p2;
        p++;
        p2++;
    }
    p++;
    *p = '\0';
    return cad;
}

char* mi_strchr(char *cad, char c)
{
    while(*cad){
        if(*cad == c)
            return cad;
        cad++;
    }
    return NULL;
}


int mi_strcmp(char *cad, char* cad2)
{
    int c = 0, cmp;
    while(*cad && *cad2){
        cmp = *cad - *cad2;
        if(cmp == 0){
            cad++;
            cad2++;
        }
        if(cmp > 0){
            return 1;
        }else
            return -1;
    }
    if(*cad)
        return -1;
    else
        return 1;
}


