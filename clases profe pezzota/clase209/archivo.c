#include "archivo.h"

int crear_lotes (t_movimiento *socios, int cant_registros)
{
    FILE* pf;
    pf = fopen("cuentas.dat","wb");
    if(!pf)
    {
        return -1;
    }

    fwrite(socios, sizeof(t_cuenta)*cant_registros,1,pf);

    fclose(pf);
    return 0;

}

int archivo_socios()
{
 FILE * psa = fopen("archivob1.dat", "rb");
 FILE * psb = fopen("archivob2.dat", "rb");
 FILE * psc = fopen("archivob3.dat", "wb");
 t_socio sociosA;
 t_socio sociosB;

 if (psa == NULL || psb == NULL)
 {
     return -5;
 }

 fread(&sociosA, sizeof(t_socio),1, psa);
 fread(&sociosB, sizeof(t_socio),1,psb);
 while (!feof(psa) && !feof(psb))
 {
     if (sociosA.dni < sociosB.dni)
     {
         fwrite(&sociosA, sizeof(t_socio),1,psc);
         fread(&sociosA, sizeof(t_socio),1, psa);

     }
     else if (sociosA.dni > sociosB.dni)
     {
         fwrite(&sociosB, sizeof(t_socio),1,psc);
         fread(&sociosB, sizeof(t_socio),1,psb);
     }
     else
     {
         fwrite(&sociosA, sizeof(t_socio),1, psc);
         fread(&sociosA, sizeof(t_socio),1,psa);
         fread(&sociosB, sizeof(t_socio),1,psb);
     }


 }


    while(!feof(psa))
    {
       fwrite(&sociosA, sizeof(t_socio),1,psc);
       fread(&sociosA, sizeof(t_socio),1, psa);

    }

    while(!feof(psb))
    {
         fwrite(&sociosB, sizeof(t_socio),1,psc);
         fread(&sociosB, sizeof(t_socio),1,psb);

    }


 fclose(psa);
 fclose(psb);
 fclose(psc);
 return 0;
}

int mostrar_archivo()
{
    t_cuenta sociosC;
    FILE * pf = fopen("cuentas.dat","rb");

    if (pf == NULL)
    {
        return -1;
    }

    fread(&sociosC, sizeof(t_cuenta),1,pf);

    while(!feof(pf))
    {
        printf("%d %d %f\n", sociosC.nro_cuenta, sociosC.tipo_cuenta, sociosC.saldo);
        fread(&sociosC,sizeof(t_cuenta),1,pf);
    }
    fclose(pf);
    return 0;
}

int actualizar_cuentas()
{
    FILE * pc = fopen("cuentas.dat","rb+");
    FILE * pm = fopen("movimientos.dat", "rb");
    FILE * pe = fopen("error.txt","wt");
    t_cuenta cuentas;
    t_movimiento movimientos;
    int cuen = 0;

    if (pc == NULL && pm == NULL)
    {
        return -5;
    }

    fread(&cuentas,sizeof(t_cuenta),1,pc);
    fread(&movimientos, sizeof(t_movimiento),1,pm);
    while (!feof(pc) && !feof(pm))
    {
        fseek(pc, 0L, SEEK_CUR);
        if(cuentas.nro_cuenta == movimientos.nro_cuenta)
        {
            if(movimientos.tipo_mov == 'D')
            {
                cuentas.saldo += movimientos.importe;
                fseek(pc, -sizeof(t_cuenta), SEEK_CUR);
                fwrite(&cuentas,sizeof(t_cuenta),1,pc);
                fread(&movimientos, sizeof(t_movimiento),1,pm);

            }
            else
            {
                cuentas.saldo -= movimientos.importe;
                fseek(pc, -sizeof(t_cuenta), SEEK_CUR);
                fwrite(&cuentas,sizeof(t_cuenta),1,pc);
                fread(&movimientos, sizeof(t_movimiento),1,pm);
                fseek(pc, 0L, SEEK_CUR);

            }


        }
        else if(cuentas.nro_cuenta < movimientos.nro_cuenta)
        {
            //fseek(pc,0,SEEK_CUR);
            fread(&cuentas,sizeof(t_cuenta),1,pc);
        }
        else if(cuentas.nro_cuenta > movimientos.nro_cuenta)
        {
            if(cuentas.nro_cuenta != cuen)
                fprintf(pe,"ERROR EN EL NUMERO DE CUENTA %d, ES INEXISTENTE\n",cuentas.nro_cuenta);
            fread(&movimientos, sizeof(t_movimiento),1,pm);
            cuen = cuentas.nro_cuenta;

        }






    }

    while(!feof(pc))
    {
        fread(&cuentas,sizeof(t_cuenta),1,pc);
    }

    fclose(pc);
    fclose(pm);
    fclose(pe);
    return 0;
}
