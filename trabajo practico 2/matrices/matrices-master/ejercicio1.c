#include <stdio.h>

int sumatoria (int m[][4], int* updiagonalp, int* dise, int* updiagonalincluida, int* underdiagonal);

int main()
{
    
    int matriz[][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int updiagonal = 0, dise = 0, updiagonalincluida = 0, underdiagonal = 0;
    int* up = &updiagonal;
    int* updi = &updiagonalincluida;
    int* ds = &dise;
    int* ud = &underdiagonal;
    
    sumatoria(matriz, *up, *ds, *updi, *ud);
    
    printf("Encima de diagonal : %d \n Y con la diagonal incluida : %d \n", *up, *updi);
    printf("Diagonal secundaria : %d \n Debajo de la diagonal principal : %d", *ds, *ud);
    
    return 0;
    
}

int sumatoria(int m[][4], int* updiagonalp, int* dise, int* updiagonalincluida, int* underdiagonal)
{
    int i, j;
    int diagonal = 0;
    int n = 4;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i != j && i < j)
            {
                *updiagonalp += m[i][j];
            }
            else if (i == j)
            {
                diagonal += m[i][j];
            
            }
            else if (i != j && i > j)
            {
                *underdiagonal += m[i][j];
            }
            else 
            {
                
            }
            
            


        }
    }
    *updiagonalincluida = *updiagonalp + diagonal;
    j = n;
    i = (n - j + 1);
    
    while(i <= n && j <= n)
    {
        *dise += m[i][j];
     
        j--;   
    }

}
