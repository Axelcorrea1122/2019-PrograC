#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include <stdio.h>

typedef struct {
int dia;
int mes;
int an;}t_ing;

typedef struct {
int dni;
char apyn[50];
t_ing ingreso;
}t_socio;

typedef struct {
    int nro_cuenta;
    char tipo_cuenta;
    float saldo;

}t_cuenta;

typedef struct {
    int nro_cuenta;
    char tipo_mov;
    float importe;
    }t_movimiento;


int crear_lotes(t_movimiento *socios, int cant_registros);
int archivo_socios();
int mostrar_archivo();
int actualizar_cuentas();


#endif // ARCHIVO_H_INCLUDED
