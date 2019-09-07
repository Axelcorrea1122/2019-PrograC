#include "fechas.h"


int ingresar_fecha_val_DMA(tFecha* fec, char* mensaje)
{
    do{
        printf("%s",mensaje);

        fflush(stdin);
        scanf("%d/%d/%d",fec->d, fec->m, fec->a);

    }while(!es_fecha_val(fec));

    return 0;
}


int es_fecha_val(tFecha *fec)
{
    return fec->a>1600 && fec->a<3000 && fec->m>0 && fec->m<13 && fec->d>0 && fec->d<cant_dia_mes(fec);
}

int cant_dia_mes(tFecha *fec)
{
    int dias[2][12] = { {31,28,31,30,31,30,31,31,30,31,30,31},
                        {31,29,31,30,31,30,31,31,30,31,30,31} };

    return dias[fec->m][es_biciesto(fec->a)];
}

int es_biciesto(int a)
{
    return (a%4 == 0 && a%100 != 0) || a%400 == 0;
}

int a_juliano(tFecha *fec)
{

    int sum =0, i =0;
    while(i < fec->m){
        sum += cant_dia_mes(fec);
        i++;
    }
    return sum + fec->m;
}

int sumar_fechas(tFecha *fec1, tFecha *fec2)
{
    int dias1 = a_juliano(fec1);
    int dias2 = a_juliano(fec2);

    0.

}
