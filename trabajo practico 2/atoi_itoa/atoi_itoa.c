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

char* mi_itoa(char * vec, int n, int base)
{
    char *p = vec;
    int esNegativo = 0;
    char car;

    if(n < 0){
        esNegativo = 1;
        n = abs(n);
    }
    while(n>base) {
        car = toascii(n%base);
        *p = car;
        n /= base;
        p++;
    }

    if(esNegativo){
        *p = '-';
        p++;
    }
    *p = '\0';


    return p;

}


