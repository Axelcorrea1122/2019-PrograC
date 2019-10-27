#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int d,
        m,
        a;
}t_fecha;

typedef struct {
    int dni;
    char apyn[30];
    t_fecha fing;
    char estado;
    float promedio;
}t_alumno;


int bin_a_txt_fijo(char *pathbin, char *pathtxt, t_alumno *alu);


#endif // HEADER_H_INCLUDED
