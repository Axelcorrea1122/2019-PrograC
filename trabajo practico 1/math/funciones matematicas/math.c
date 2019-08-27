#include "math.h"

long factorial(int n)
{
    if(n==0)
        return 1;
    int num;
    long fact = 1;

    for(num = n;num>0;num--)
        fact *= num;
    return fact;
}

float combinatorio( int n1, int n2)
{
    float comb;

    comb = factorial(n1)/((float)(factorial(n2)*factorial(n1-n2)));

    return comb;
}

float e_elevado_x(int n, float tol)
{
    float result=1;
    int i=1;
    while(result >= tol){
        result += pow(n,i)/i;
        i++;
    }
    return result;
}

float raiz_cuadrada( int n, float tol)
{
    float res = 1;
    float resant = 0;
    while(abs(resant - res) >= tol)
    {
        resant = res;

        res = ((float)(1/2))*((resant) + (n/(resant)));
    }
    return res;
}


int es_fibonacci(int n)
{
    int ult = 1, suma = 0, anteult = 1;

    while(suma<n){
        suma = anteult + ult;
        anteult = ult;
        ult = suma;
    }
    if(suma == n || n == 1)
        return 1;
    return 0;
}
float seno_de_x(float n, float tol)
{
    float result = n, resultant=0;
    int exp = 3;
    int resta = 1, suma = 0;

    while(result-resultant<0? (result-resultant)*-1: (result-resultant)> tol ){
        if(resta){
            resultant = result;
            result -= (pow(n,exp))/(float)(factorial(exp));
            resta = 0;
            suma = 1;
        }else{
            if(suma)
            {
                resultant = result;
                result += (pow(n,exp))/(float)(factorial(exp));
                suma = 0;
                resta = 1;
            }
        }

        exp = exp+2;
    }
    return result;
}
