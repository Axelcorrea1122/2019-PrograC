#ifndef ATOI_ITOA_H_INCLUDED
#define ATOI_ITOA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "strings.h"

int mi_atoi(char *vec);
char* mi_itoa(char *vec,long long n, int base);
char* invertir_cadena(char *vec);


#endif // ATOI_ITOA_H_INCLUDED
