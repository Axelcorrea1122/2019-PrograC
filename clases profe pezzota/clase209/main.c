#include "archivo.h"

int main()
{
   /* t_socio sociosA[] = {{40306191, "Matias Beltramone",{15,5,2014}},
                       {50578418, "Elsa Bandija",{20,5,2015}},
                       {66205789, "Chita Mo", {5,8,2016}}};

    t_socio sociosB[] = {{40306191, "Matias Beltramone", {15,5,2014}},
                         {66205789, "Chita Mo", {5,8,2016}},
                         {8746164, "Maga Ly", {5,2,2015}}
                       };   */

     //crear_lotes(sociosA);
    //crear_lotes(sociosB);
    //archivo_socios();
    //mostrar_archivo();


    t_cuenta cuentas[] = {{1,'A',1000},{2,'A',200},{4,'C',15000},{8,'C',150}};
    t_movimiento mov[] = {{1,'D',500},{1,'E',1000},{1,'E',100},{3,'D',500},{3,'D',1000},{4,'E',1500},{4,'E',1300}};


    crear_lotes(mov,7);
    crear_lotes(cuentas,4);

    actualizar_cuentas();
    mostrar_archivo();












    return 0;
}
