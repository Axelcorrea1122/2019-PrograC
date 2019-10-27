#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


int suma_por_arriba_diagonal(int mat[][3], int cf, int cc);
int suma_por_abajo_diagonal(int mat[][3], int cf, int cc);
int suma_por_arriba_con_diagonal(int mat[][3], int cf, int cc);
int suma_por_abajo_con_diagonal(int mat[][3], int cf, int cc);
void mostrar( int mat[][3] );
void mostrar_triangulo_superior(int mat[][3], int cf, int cc);
void mostrar_vecinos(int mat[][3], int cf, int cc, int fil, int col);

#endif // MATRICES_H_INCLUDED
