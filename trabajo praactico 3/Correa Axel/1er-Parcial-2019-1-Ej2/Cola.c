#include <Cola.h>



void crear_cola(t_cola* pcola)
{
/*  IMPLEMENTACION ESTATICA
    pcola->ce = 0;
    pcola->fondo = 0;
    pcola->frente = 0;
*/

    pcola->pri = NULL;
    pcola->ult = NULL;
}



int poner_en_cola(t_cola* pcola, const t_dato *pd)
{
    /* IMPLEMENTACION ESTATICA
    if(pcola->ce == TAM)
        return SIN_MEM;
	pcola->vcola[pcola->fondo] = *pd;
	pcola->fondo++;
	pcola->ce++;
	return TODO_OK;
	*/
	t_nodo *nue = (t_nodo*)malloc(sizeof(t_nodo));
	if(!nue)
        return 1;
    nue->dato = *pd;
    nue->sig = NULL;

    if(!pcola->pri)
        pcola->pri = nue;
    else
        pcola->ult->sig = nue;
    pcola->ult = nue;

    return 0;
}



int sacar_de_cola(t_cola* pcola, t_dato* pd)
{
    /*  IMPLEMENTACION ESTATICA
    *pd = pcola->vcola[pcola->frente];
    pcola->frente++;
    pcola->ce--;
    return TODO_OK;
    */
    if(!pcola->pri)
        return 1;
    *pd = pcola->pri->dato;
    t_nodo *aux = pcola->pri;
    pcola->pri = pcola->pri->sig;
    free(aux);
    return 0;
}

int cola_vacia(const t_cola* pcola)
{
    /* IMPLEMENTACION ESTATICA
    if(pcola->ce == 0)
        return 1;
    return 0;
    */

    return pcola->pri == NULL;
}
