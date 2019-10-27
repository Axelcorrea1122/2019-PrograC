#include "matrices.h"

int main()
{
    int mat[][3] = {{1,2,3},{4,5,6},{7,8,9}};

    //mostrar_triangulo_superior(mat,3,3);
    mostrar_vecinos(mat, 3, 3, 1, 1);

    return 0;
}
