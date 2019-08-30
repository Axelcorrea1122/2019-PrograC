#include <stdio.h>
#include <stdlib.h>
#include"vector.h"
int main()
{
    int vec[5]= {1,3,4,5};

    //insertar_en_vector_pos(vec, 4, 2, 1);
    insertar_en_vector_asc(vec, 4, 2);
    eliminar_por_pos_vec(vec, 5, 2);
    int i;
    for( i=0 ; i<5 ; i++)
        printf("\n%d", vec[i]);

    return 0;
}
