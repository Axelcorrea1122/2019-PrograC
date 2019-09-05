#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

int insertar_en_vector_pos(int* vec, int ce,int elem, int pos)
{
    if(ce <= pos)
        return -1;
        int aux;
    int* act = vec + (ce - 1);
    while(act >= vec + (pos - 1)){
        aux = *act;
        *(act+1) = aux;
        act--;
    }
    *(vec+pos-1) = elem;
    return ce+1;
}


int insertar_en_vector_asc(int* vec, int ce, int elem)
{
    int dato = elem, sig;
    int* act = vec;
    while(act<vec + (ce-1) && *act<elem)
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


int eliminar_por_pos_vec(int vec, int ce, int pos){

    if(pos > ce)
        return 1;
    int* act = vec +(pos-1), sig;
    while(act<=vec+(ce-1)){
        sig = *(act+1);
        *act = sig;
        act++;
    }
    return ce-1;
}



