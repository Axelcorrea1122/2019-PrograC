#include <stdio.h>
#include <stdlib.h>

void mi_intercambiar(void *ele1, void *ele2);
void mi_qsort(void *vec, long ce, long tam, int(*cmp)(const void*, const void*));
int* mi_buscar_menor(void *menor, void *vec, long ce, long tam, int(*cmp)(const void*, const void*));
int cmp_int(const void* e1, const void* e2);
void intercambiar(int *ele1, int *ele2);
int* buscar_menor(int *menor, int *vec, int ce);
void ordenar_vec(int *vec, int ce);
int cmp_flotantes(const void* e1, const void* e2);




int main()
{




    float vec[] = {5.2,1.4,6.6,8.5,2.0};

    //ordenar_vec(vec, 5);
    //qsort(vec, sizeof(vec)/sizeof(float), sizeof(float),cmp_flotantes);

    for(int i=0; i<5; i++)
        printf("\n%.1f", vec[i]);



    return 0;
}



void ordenar_vec(int *vec, int ce)
{
    int *ini = vec;
    int *menor = vec;
    while(ini < vec+ce-1)
    {
        menor = buscar_menor(menor, ini, ce);
        if(menor != vec)
            intercambiar(menor, ini);
        ini++;
    }

}

int* buscar_menor(int *menor, int *vec, int ce)
{
    int *ini = vec;
    while(ini < vec+ce-1){
        if(*ini < *menor)
            menor = ini;
        ini++;
    }

    return menor;
}

void intercambiar(int *ele1, int *ele2)
{
    int aux = *ele1;
    *ele1 = *ele2;
    *ele2 = aux;
}


int cmp_int(const void* e1, const void* e2)
{
    return *((int*)e1) - *((int*)e2);
}

int cmp_flotantes(const void* e1, const void* e2)
{
    return *((float*)e1) - (*(float*)e2);
}



void mi_qsort(void *vec, long ce, long tam, int(*cmp)(const void*, const void*))
{
    void *ini = vec;
    void *menor = vec;
    while(ini < vec+(ce*tam)-tam)
    {
        menor = mi_buscar_menor(menor, ini, ce, tam, cmp);
        if(menor != vec)
            intercambiar(menor, ini);
        ini+=tam;
    }

}

int* mi_buscar_menor(void *menor, void *vec, long ce, long tam, int(*cmp)(const void*, const void*))
{
    void *ini = vec;
    while(ini < vec+ce-tam){
        if(cmp(ini,menor)<0)
            menor = ini;
        ini+=tam;
    }

    return menor;
}

void mi_intercambiar(void *ele1, void *ele2)
{

}
