#ifndef COLA_H
#define COLA_H

#include <Defs.h>
#include <Tipos.h>
#include <stdlib.h>

typedef struct sNodo{
    t_dato dato;
    struct sNodo *sig;
}t_nodo;

typedef struct
{
    t_nodo *pri,
           *ult;
}
t_cola;



void crear_cola(t_cola* pcola);
int poner_en_cola(t_cola* pcola, const t_dato* pd);
int sacar_de_cola(t_cola* pcola, t_dato* pd);
int frente_de_cola(const t_cola* pcola, t_dato* pd);
int cola_vacia(const t_cola* pcola);
int cola_llena(const t_cola* pcola);
void vaciar_cola(t_cola* pcola);
void crear_cola_res(t_cola* pcola);
int poner_en_cola_res(t_cola* pcola, const t_dato* pd);
int sacar_de_cola_res(t_cola* pcola, t_dato* pd);
int frente_de_cola_res(const t_cola* pcola, t_dato* pd);
int cola_vacia_res(const t_cola* pcola);
int cola_llena_res(const t_cola* pcola);
void vaciar_cola_res(t_cola* pcola);


#endif // COLA_H
