#include "archivos.h"

int ingresar_alumno(t_alumno *alu)
{
    FILE* pf;
    pf = fopen("alla.dat","wb");
    if(!pf)
    {
        return -1;
    }

    fwrite(alu, sizeof(t_alumno)*3,1,pf);

    fclose(pf);
    return 0;

}

int mostrar_archivo()
{
    t_alumno alu;
    FILE * pf = fopen("txtabin.dat","rb");

    if (pf == NULL)
    {
        return -1;
    }

    fread(&alu, sizeof(t_alumno),1,pf);

    while(!feof(pf))
    {
        printf("%d %s %d/%d/%d %d %c %c\n", alu.dni, alu.apyn,alu.fech.dia, alu.fech.mes, alu.fech.an, alu.cant_notas, alu.sexo, alu.estado);
        fread(&alu,sizeof(t_alumno),1,pf);
    }
    fclose(pf);
    return 0;
}

int actualizar()
{
    t_alumno al;
    FILE * pf = fopen("alla.dat","rb+");
    if (pf == NULL)
    {
        return -1;
    }

    fread(&al,sizeof(t_alumno),1,pf);
    while(!feof(pf))
    {
        if(al.fech.an < 2000)
        {
            fseek(pf,-sizeof(t_alumno),1);
            al.estado = 'V';
            fwrite(&al,sizeof(t_alumno),1,pf);
        }
        fseek(pf,0,1);
        fread(&al,sizeof(t_alumno),1,pf);
    }

    fclose(pf);
    return 0;
}

int creartexto()
{
    t_alumno al;
    FILE * pf = fopen("archivo.txt","wt");
    FILE * pb = fopen("alla.dat","rb");

    if(pb == NULL)
    {
        printf("ERROR");
    }

    fread(&al, sizeof(t_alumno),1,pb);
    while(!feof(pb))
    {

        fprintf(pf, "%d - %s - %d/%d/%d - %c - %d - %c\n", al.dni, al.apyn, al.fech.dia, al.fech.mes, al.fech.an,al.sexo,al.cant_notas,al.estado);
        fread(&al, sizeof(t_alumno),1,pb);


    }

    fclose(pb);
    fclose(pf);

    return 0;
}

int txt_a_bin ()
{
    t_alumno al;
    FILE * pt = fopen("archivo.txt","rt");
    FILE * pb = fopen("txtabin.dat","wb");


    char cad_aux[50];
    int r;

    while(fgets(cad_aux, sizeof(cad_aux),pt))
    {
        if (!strchr(cad_aux,'\n'))
        {
            return -1;
        }

        r = sscanf(cad_aux, "%d-%30[^-]-%2d/%2d/%4d-%c-%2d-%c",&al.dni,al.apyn,&al.fech.dia,&al.fech.mes,&al.fech.an,&al.sexo,&al.cant_notas,&al.estado);

        fwrite(&al,sizeof(t_alumno),1,pb);

    }

    fclose(pt);
    fclose(pb);

    return 1;
}


