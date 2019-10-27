#include <stdio.h>
#include <string.h>
#include <Cadena.h>



int main()
{
	char linea[101];
	char* palabra1 = linea, *palabra2, *finLinea;
	FILE* archAnagramas = fopen("../Archivos/Anagramas.txt", "rt");

	if(!archAnagramas)
	{
		puts("Error en apertura archivo");
		return 1;
	}

	fgets(linea, 101, archAnagramas);
	while(!feof(archAnagramas))
	{
		finLinea = strchr(linea, '\n');
		*finLinea = '\0';
		palabra2 = strchr(linea, '|');
		*palabra2 = '\0';
		palabra2++;

		if(son_anagramas(palabra1, palabra2))/*son_anagramas(palabra1, palabra2)*/
			printf("Las palabras %s y %s son anagramas\n", palabra1, palabra2);
		else
			printf("Las palabras %s y %s NO son anagramas\n", palabra1, palabra2);

		fgets(linea, 101, archAnagramas);
	}



	return 0;
}
