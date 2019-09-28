#include <stdio.h>
#include <stdlib.h>
int contar_caracteres(const char *cad);

int main()
{
    char cad1[20] = {'h','o','l','a'};//completa con ceros
    char cad2[] = {'h', 'o', 'l', 'a'};
    char cad3[] = "hola";



    return 0;
}


int contar_caracteres(const char *cad){
    int c = 0;
    while(*cad){
        cad++;
        c++;
    }
    return c;
}
