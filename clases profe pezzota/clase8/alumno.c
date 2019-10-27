#include "alumno.h"
int ingresar_alumno(t_alumno *alu)
{

    FILE * pf = fopen("Alumnos.dat","wb");

    //printf("\n %d - %s - %d/%d/%d - %c - %d",alu->dni, alu->apyn, alu->fec.d, alu->fec.m, alu->fec.a, alu->sexo, alu->cat_mat);

    if(!pf)
        return 1;

    fwrite(alu, sizeof(t_alumno)*3,1,pf);

    fclose(pf);
    return 0;

}

void recorrer_archivo(t_alumno *al)
{
    FILE *pf = fopen("Alumnos.dat","rb");
    if(!pf)
        return;

    fread(al, sizeof(t_alumno),1,pf);

    while(!feof(pf)){
        printf("\n %d - %s - %d/%d/%d - %c - %d - %c",al->dni, al->apyn,al->fec.d, al->fec.m, al->fec.a, al->sexo, al->cat_mat, al->estado);
        fread(al, sizeof(t_alumno),1,pf);
    }

    fclose(pf);

}

void actualizar_archivo(t_alumno *alu)
{
    FILE *pf= fopen("Alumnos.dat","rb+");
    if(!pf)
        return;

    fread(alu,sizeof(t_alumno),1,pf);


    while(!feof(pf)){
        if(alu->fec.a < 2000){
            fseek(pf,-sizeof(t_alumno),SEEK_CUR);
            alu->estado = 'N';
            fwrite(alu, sizeof(t_alumno),1,pf);
        }
        fseek(pf,0,SEEK_CUR);
        fread(alu,sizeof(t_alumno),1,pf);
    }
    fclose(pf);
}
/*
LITERALES
0xF
07
7
7L
9.2f
*/


//---------------------CLASE 9---------------------

int crea_lote_alus(char * path, t_alumno *alus, int ce)
{
    FILE * pf = fopen(path, "wb");
    if(!pf)
        return 0;
    fwrite(alus, sizeof(t_alumno), ce, pf);
    fclose(pf);
    return 1;
}
