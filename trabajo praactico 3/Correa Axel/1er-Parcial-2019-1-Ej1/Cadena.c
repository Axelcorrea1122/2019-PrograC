#include <Cadena.h>
#include <string.h>

int son_anagramas(char* palabra1, char* palabra2)
{
    int sonIguales = 1;
    char *pcad, *indice1 = palabra1;
    char *indice2 = palabra2;
    if(strlen(indice1) != strlen(palabra2))
        return 0;

    while(*indice1){
        pcad = strchr(palabra2, *indice1);
        if(!pcad)
            return 0;
        if(*indice1 != *indice2)
            sonIguales = 0;
        indice1++;
        indice2++;
    }
    if(sonIguales)
        return 0;
    else
        return 1;

}

