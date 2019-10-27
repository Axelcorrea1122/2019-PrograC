#include "merge.h"

void ingresar_socios(t_socio *socio, int ce, char *path)
{
    FILE *arch = fopen(path, "wb");
    fwrite(socio, sizeof(t_socio)*ce, 1, arch);
    fclose(arch);
}

void recorrer_archivo(char *path)
{
    t_socio socio;
    FILE *pf = fopen(path,"rb");
    if(!pf)
        return;

    fread(&socio, sizeof(t_socio),1,pf);

    while(!feof(pf)){
        printf("\n %d - %s - %d/%d/%d",socio.dni, socio.apyn,socio.fec.d, socio.fec.m, socio.fec.a);
        fread(&socio, sizeof(t_socio),1,pf);
    }

    fclose(pf);

}

void merge_entre_archivos(char *path1, char *path2, char *result)
{
    FILE *arch1 = fopen(path1, "rb");
    FILE *arch2 = fopen(path2, "rb");
    FILE *arch3 = fopen(result, "wb");

    t_socio socioA;
    t_socio socioB;
    int comp;

    if(!arch1 && !arch2)
        return;

    fread(&socioA, sizeof(t_socio), 1,arch1);
    fread(&socioB, sizeof(t_socio), 1,arch2);


    while(!feof(arch1) && !feof(arch2)){

        comp = socioA.dni - socioB.dni;

        if(comp == 0){
            fwrite(&socioA, sizeof(t_socio), 1, arch3);
            fread(&socioA, sizeof(t_socio), 1,arch1);
            fread(&socioB, sizeof(t_socio), 1,arch2);
        }

        if(comp < 0){
            fwrite(&socioA, sizeof(t_socio), 1, arch3);
            fread(&socioA, sizeof(t_socio), 1,arch1);
        }

        if(comp > 0){
            fwrite(&socioB, sizeof(t_socio), 1, arch3);
            fread(&socioB, sizeof(t_socio), 1,arch2);
        }
    }

    while(!feof(arch1))
        fwrite(&socioA, sizeof(t_socio), 1, arch3);

    while(!feof(arch2))
        fwrite(&socioB, sizeof(t_socio), 1, arch3);

    fclose(arch1);
    fclose(arch2);
    fclose(arch3);

}
