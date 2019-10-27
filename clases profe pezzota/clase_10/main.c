#include "merge.h"
int main()
{
    t_socio sociosA[3] = {{39749664, "Axel Correa", {2, 9, 1996}}, {40824163, "Pablo Correa", {9, 4, 1989}}, {45750142, "Yesica Correa", {14, 2, 1992} }};
    t_socio sociosB[5] = {{39749664, "Axel Correa", {2, 9, 1996}}, {39861951,"Patricia Andrada", {5,2,1982}}, {40824163, "Pablo Correa", {9, 4, 1989}}, {41693251, "Luciano Barua", {18, 6, 1995}}, {45750142, "Yesica Correa", {14, 2, 1992} }};

    ingresar_socios(sociosA, 3, "Socios1.dat");
    ingresar_socios(sociosB, 5, "Socios2.dat");

    //recorrer_archivo("Socios2.dat");

    merge_entre_archivos("Socios1.dat", "Socios2.dat","Resultado.dat");
    recorrer_archivo("Resultado.dat");




    return 0;
}
