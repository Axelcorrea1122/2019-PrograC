#include "atoi_itoa.h"

int mi_atoi(char *vec)
{
    int dig = 0, acum = 0, esNegativo = 0;

    if(*vec == '-'){
        esNegativo = 1;
        vec++;
    }

    while(*vec){
        dig = (*vec)-'0';
        acum += dig;
        acum *= 10;
        vec++;
    }
    acum /= 10;

    return esNegativo ? acum*(-1) : acum;
}

char* mi_itoa(char * vec, long long n, int base)
{
    char *p = vec;
    int esNegativo = 0;
    char car;

    if(n < 0){
        esNegativo = 1;
        n = abs(n);
    }
    while(n>0) {
        car = to_ascii(n%base);
        *p = car;
        n /= base;
        p++;0
    }

    if(esNegativo){
        *p = '-';
        p++;
    }
    *p = '\0';

    invertir_cadena(vec);
    return vec;
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
