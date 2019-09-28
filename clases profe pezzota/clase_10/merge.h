#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int d,
        m,
        a;
}t_fecha;

typedef struct{
    int dni;
    char apyn[30];
    t_fecha fec;
}t_socio;

void ingresar_socios(t_socio *socio, int ce, char *path);
void ingresar_socios(t_socio *socio, int ce, char *path);
void recorrer_archivo(char *path);
void merge_entre_archivos(char *path1, char *path2, char *result);



#endif // MERGE_H_INCLUDED
