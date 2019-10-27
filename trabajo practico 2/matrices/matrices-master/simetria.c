#include <stdio.h>

int es_simetrica (int m[][4], int n);

int main()
{
    int n = 4;
    int resultado;
    int matriz[][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    resultado = es_simetrica(matriz, n);
    printf ("%d", resultado);

    return 0;
}

int es_simetrica (int m[][4], int n)
{
    int contador = 0, i , j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (m[i][j] == m[j][i] && i != j)
            {
                contador++;
            }
            else
            {
                
            }
        }
    }
 
 if (contador == ((n*n)/2))
 {
     return 5;
 }
 else
 {
     return -5;
 }

}
