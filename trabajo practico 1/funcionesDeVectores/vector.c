#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

int insertar_en_vector_pos(int vec[], int ce,int elem, int pos)
{
    if(pos > ce)
        return -1;

    int i=ce-1;
    int aux;
    while(i>=pos){
        aux = vec[i];
        vec[i+1] = aux;
        i--;
    }
    vec[pos] = elem;
    return ce+1;
}


int insertar_en_vector_asc(int vec[], int ce, int elem)
{
    int dato = elem, i=0, sig;
    while(i<ce && vec[i]<elem)
        i++;
    ce++;
    while(i<ce){
        sig = vec[i];
        vec[i] = dato;
        dato = sig;
        i++;
    }
    return ce;

}


int eliminar_por_pos_vec(int vec[], int ce, int pos){

    if(pos > ce)
        return 1;
    int i = pos-1, sig;
    while(i<ce-1){
        sig = vec[i+1];
        vec[i] = sig;
        i++;
    }
    return ce-1;
}



