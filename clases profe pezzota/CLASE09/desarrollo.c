#include "header.h"
int bin_a_txt_fijo(char *pathbin, char *pathtxt, t_alumno *alu)
{
    FILE *pfbin = fopen(pathbin, "rb");
    FILE *pftxt = fopen(pathtxt, "wt");
    if(!pftxt || !pfbin)
        return 1;

    fread(alu, sizeof(t_alumno), 1, pfbin);

    while(!feof(pfbin)){
        fprintf(pftxt, "%d%s%d/%d/%d%c%f\n",alu->dni, alu->apyn, alu->fing.d, alu->fing.m, alu->fing.a, alu->estado, alu->promedio);
        fread(alu, sizeof(t_alumno), 1, pfbin);
    }


    return 0;
}
