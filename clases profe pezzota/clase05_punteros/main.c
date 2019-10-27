#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia,
        mes,
        anio;
}t_fecha;

typedef struct {
    int dni;
    char apyn[30];
    float prom;
    float notas[3];
    t_fecha fnac;
    }t_alumno;



void intercambiar(int *x, int *y);



int main()
{
    int vec[5] = {0};
    int x=5;
    int *px;
    px = &x;
    printf("%d - %p", x, &x);
    printf("\n %d - %p - %p", *px, px, &px);
    int *pv1 = vec;
    pv1 = &vec[1];
    *pv1 = 6;
    pv1 = vec;

    printf("\n %p - %p", vec, &vec);
    printf("\n %p - %p", pv1, &pv1);

    //------------------------------------------------------//

    x = 5;
    int y = 8;
    intercambiar(&x, &y);
    printf("\n%d - %d", x, y);

    //------------------------------------------------------//
    t_alumno alu = {123, "Ax, Co", 7.08, {4, 7, 9}, {2, 9, 1996}};
    t_alumno *palu = &alu;

    printf("\n%d",palu->dni); //si es un puntero a una estructura va (->) si es una variable va (.)
    printf("\n %d/%d/%d",palu->fnac.dia,palu->fnac.mes, palu->fnac.anio);

    //---------------------------------------------------------//
    //si es un parametro de entrada y de tipo nativo se envio por copia
    // si es una parametro de entrada y de tipo estructura se coloca const tipo *nombrepuntero
    //si son parametros de salida o de entrada/salida se ponen punteros
    // void imp_alu( const t_alumno *palu);




    return 0;
}


void intercambiar(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}
