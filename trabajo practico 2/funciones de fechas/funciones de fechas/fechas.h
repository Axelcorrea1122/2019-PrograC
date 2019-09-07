#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int d,
        m,
        a;
    }tFecha;

int ingresar_fecha_val_DMA(tFecha* fec, char* mensaje);
int es_fecha_val(tFecha* fec);
int cant_dia_mes(tFecha *fec);
int es_biciesto(int a);
int a_juliano(tFecha *fec);
int sumar_fechas(tFecha *fec1, tFecha *fec2);

#endif // FECHAS_H_INCLUDED
