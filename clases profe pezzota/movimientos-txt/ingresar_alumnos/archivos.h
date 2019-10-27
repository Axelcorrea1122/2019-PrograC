#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include <stdio.h>
#include <string.h>
typedef struct
{
    int dia;
    int mes;
    int an;
}t_fecha;

typedef struct
{
    int dni;
    char apyn[50];
    t_fecha fech;
    char sexo;
    int cant_notas;
    char estado;
}t_alumno;


int ingresar_alumno(t_alumno *alu);
int mostrar_archivo();
int actualizar();
int creartexto();
int txt_a_bin();

#endif // ARCHIVOS_H_INCLUDED
