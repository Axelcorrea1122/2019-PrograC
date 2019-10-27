#include <stdio.h>
#include <stdlib.h>
#include <Tipos.h>
#include <Cola.h>
#include <Utilitarias.h>
#include <string.h>



void procesar_arch_productos(FILE* arch_prod, FILE* arch_prod_mas_1000, FILE* arch_prod_menos_1000);
void escribir_arch_con_cola(FILE *arch_prod, t_cola *cola);



int main()
{
	generar_archivo_productos();

    FILE* arch_prod = fopen("../Archivos/Productos.dat", "rb");
    FILE* arch_prod_mas_1000 = fopen("../Archivos/ProductosMas1000.dat", "wb");
    FILE* arch_prod_menos_1000 = fopen("../Archivos/ProductosMenos1000.dat", "wb");

    if(!arch_prod || !arch_prod_mas_1000 || !arch_prod_menos_1000)
    {
        puts("Error en apertura archivos");
        return 1;
    }

	puts("Archivo de Productos");
	mostrar_archivo_prod(arch_prod);
	rewind(arch_prod);

    ///procesar_arch_productos(arch_prod, arch_prod_mas_1000, arch_prod_menos_1000);
    procesar_arch_productos(arch_prod, arch_prod_mas_1000, arch_prod_menos_1000);

    fclose(arch_prod);
    fclose(arch_prod_mas_1000);
    fclose(arch_prod_menos_1000);

    arch_prod_mas_1000 = fopen("../Archivos/ProductosMas1000.dat", "rb");
    arch_prod_menos_1000 = fopen("../Archivos/ProductosMenos1000.dat", "rb");

    puts("Archivo de productos de costo mayor a $1000");
	mostrar_archivo_prod(arch_prod_mas_1000);

    puts("Archivo de productos de costo menor a $1000");
    mostrar_archivo_prod(arch_prod_menos_1000);

	fclose(arch_prod_mas_1000);
	fclose(arch_prod_menos_1000);

    return 0;
}



void procesar_arch_productos(FILE* arch_prod, FILE* arch_prod_mas_1000, FILE* arch_prod_menos_1000)
{
    t_cola cola;
    crear_cola(&cola);
    t_mat_prima_art art;
    char codArt[7];
    float costoTotal = 0;

    fread(&art, sizeof(t_mat_prima_art), 1, arch_prod);
    strcpy(codArt, art.cod_art);

    while(!feof(arch_prod))
    {
        while(strcmp(codArt, art.cod_art) == 0 && !feof(arch_prod))
        {
            costoTotal += art.cantidad * art.costo_unit;
            poner_en_cola(&cola, &art);
            fread(&art, sizeof(t_mat_prima_art), 1, arch_prod);
        }
        if(costoTotal >= 1000){
            escribir_arch_con_cola(arch_prod_mas_1000, &cola);
        }else{
            escribir_arch_con_cola(arch_prod_menos_1000, &cola);
        }
        strcpy(codArt, art.cod_art);
        costoTotal = 0;
    }
}


void escribir_arch_con_cola(FILE *arch_prod, t_cola *cola)
{
    t_mat_prima_art art;

    while(!cola_vacia(cola))
    {
        sacar_de_cola(cola, &art);
        fwrite(&art, sizeof(t_mat_prima_art), 1, arch_prod);
    }
}

