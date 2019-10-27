#include "matrices.h"
int suma_por_arriba_diagonal(int mat[][3], int cf, int cc)
{
    int i,j,sum=0;
    for(i=0 ; i<cf ; i++)
    {

        for(j=i ; j<cc ; j++)
        {
            if(j != i)
            {
                sum += mat[i][j];
            }
        }
    }

    return sum;
}

int suma_por_abajo_diagonal(int mat[][3], int cf, int cc)
{
    int i,j,sum=0;
    for(i=0 ; i<cf ; i++)
    {

        for(j=i ; j<cc ; j++)
        {
            if(j != i)
            {
                sum += mat[j][i];
            }
        }
    }

    return sum;
}


int suma_por_arriba_con_diagonal(int mat[][3], int cf, int cc)
{
    int i,j,sum=0;
    for(i=0 ; i<cf ; i++)
    {

        for(j=i ; j<cc ; j++)
        {
            sum += mat[i][j];

        }
    }

    return sum;
}


int suma_por_abajo_con_diagonal(int mat[][3], int cf, int cc)
{
    int i,j,sum=0;
    for(i=0 ; i<cf ; i++)
    {

        for(j=i ; j<cc ; j++)
        {

            sum += mat[j][i];

        }
    }

    return sum;
}

void mostrar( int mat[][3] )
{
    int i, j;
    int n = 3;

    for(i = 1; i<n ; i++){

        for(j = (i+1) > (n - 1) ? (i+1) : (n - 1); j< n; j++){
            printf("%d", mat[i][j]);
        }
    }
}

void mostrar_triangulo_superior(int mat[][3], int cf, int cc)
{
    int i,j, c=0;
    for(i=0, j=0 ; i<cf ; i++)
    {
        for(j=c; j<cc ; j++){
            printf("%d",mat[i][j]);
        }
        c++;
        cc--;
    }
}

void mostrar_vecinos(int mat[][3], int cf, int cc, int fil, int col)
{
    int i=fil, j=col;
    int a = i-1<0 && j-1<0 ? '\0' :mat[i-1][j-1];
    int b = i-1<0 ? '\0' : mat[i-1][j];
    int c = i-1<0 && j+1<cc ? '\0' : mat[i-1][j+1];



}


