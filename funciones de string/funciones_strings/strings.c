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
    int cmp;
    while(*cad && cad2){
        cmp = to_upper(*cad) - to_upper(*cad2);
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



int es_palindromo(char *cad, char *cad2)
{
    if(mi_strcmp(cad, invertir_cadena(cad2) == 0)
        return 1;
    else
        return 0;
}

char* invertir_cadena(char *vec)
{
    int c = mi_strlen(vec), aux;
    char *ult = vec + (c-1) , *pri = vec;

    while(pri<ult){
        aux = *pri;
        *pri = *ult;
        *ult = aux;
        pri++;
        ult--;
    }
    return vec;
}


char* mi_strcpy(char *cad, char *cad2)
{
    char *p =cad;
    while(*cad2){
        *p = *cad2;
        p++;
        cad2++;
    }
    return cad2;
}
