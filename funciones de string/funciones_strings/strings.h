#ifndef STRINGS_H_INCLUDED
#define STRINGS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"

int mi_strlen(char *cad);
char* mi_strcat( char *cad, char *cad2);
char* mi_strchr(char *cad, char c);
int mi_strcmp(char *cad, char* cad2);
int es_palindromo(char *cad, char *cad2);
char* invertir_cadena(char *vec);
char* mi_strcpy(char *cad, char *cad2);


#endif // STRINGS_H_INCLUDED
