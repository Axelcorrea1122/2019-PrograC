#include "normalizar.h"
char * normalizar_cadena(char *cad)
{
    int mayus = 1;
    int coma = 1;
    char *escritura = cad;
    char *lectura = cad;

    while(*lectura){
        while(!isalpha(*lectura) && *lectura){
            lectura++;
        }
        while(isalpha(*lectura) && *lectura){
            if(mayus){
                *escritura = toupper(*lectura);
                mayus = 0;
            }else
                *escritura = tolower(*lectura);
            escritura++;
            lectura++;
        }
        if(coma){
            *escritura = ',';
            escritura++;
            *escritura = ' ';
            escritura++;
            coma = 0;
        }
        else{
            *escritura = ' ';
            escritura++;
        }
        mayus = 1;

    }
    escritura--;
    *escritura = '\0';
    return cad;
    /*
    char *p = cad;
    while(*p){
        while(!isalpha(*p))
        {
            strcpy(p, p+1);
            p++;
        }
        formatear_palabra(p);
        if(*p)
        {
            *p = ' ';
            p++;
        }
        else
            return cad;
    }
    p--;
    *p = '\0';
    return cad;*/
}

void formatear_palabra(char *cad)
{

    *cad = toupper(*cad);
    cad++;
    while(isalpha(*cad)){
        *cad = tolower(*cad);
        cad++;
    }
}


char* normalizar2(char* cad)
{
    char *p = cad;

    while(!isalpha(*p)){
        p++;
    }
    formatear_palabra2(&p);
}


