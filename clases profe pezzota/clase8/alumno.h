#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
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
    t_fecha fec;
    char sexo;
    int cat_mat;
    int notas[50];
    char estado;

}t_alumno;

int ingresar_alumno(t_alumno *alu);
void recorrer_archivo(t_alumno *al);
void actualizar_archivo(t_alumno *alu);
int crea_lote_alus(char * path, t_alumno *alus, int ce);

#endif // ALUMNO_H_INCLUDED
