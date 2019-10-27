#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int d,
        m,
        a;
}t_fecha;

typedef struct {
    int dni;
    char apyn[30];
    t_fecha fec;
    char sexo;
    int cat_mat;
    int notas[50];
    char estado;

}t_alumno;

int ingresar_alumno(t_alumno *alu);
void recorrer_archivo(t_alumno *al);
void actualizar_archivo(t_alumno *alu);

int main()
{

    /*int x1 = 5, x2 = 5, y1, y2;
    y1 = x1++;
    y2 = ++x2;
    printf("%d - %d - %d - %d", x1, x2, y1, y2);
    */
    /* --------------------------------------------------*/

    t_alumno alu[3] = {{39749664, "Axel Correa", {2,9,1996},'M', 5, {9,8,9,8,9},'R'}, {40982135, "Pablo Correa", {14,2,2003}, 'M', 5, {9,8,6,8,9},'V'},{37865912, "Yesica Correa", {19,04,2005}, 'F', 5, {8,6,7,8,9}, 'V'}};

    //ingresar_alumno(alu);
    t_alumno al;

    actualizar_archivo(&al);
    recorrer_archivo(&al);


    return 0;
}


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
        if(alu->fec.a > 2000){
            fseek(pf,-sizeof(t_alumno),SEEK_CUR);
            alu->estado = 'V';
            fwrite(alu, sizeof(t_alumno),1,pf);
        }
        fseek(pf,0,SEEK_CUR);
        fread(alu,sizeof(t_alumno),1,pf);
    }
    fclose(pf);
}
