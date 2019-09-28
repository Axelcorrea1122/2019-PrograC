#include"alumno.h"



int main()
{

    /*int x1 = 5, x2 = 5, y1, y2;
    y1 = x1++;
    y2 = ++x2;
    printf("%d - %d - %d - %d", x1, x2, y1, y2);
    */
    /* --------------------------------------------------*/

    t_alumno alu[3] = {{39749664, "Axel Correa", {2,9,1996},'M', 5, {9,8,9,8,9},'R'}, {40982135, "Pablo Correa", {14,2,2003}, 'M', 5, {9,8,6,8,9},'N'},{37865912, "Yesica Correa", {19,04,2005}, 'F', 5, {8,6,7,8,9}, 'N'}};

    //ingresar_alumno(alu);
    t_alumno al;

    actualizar_archivo(&al);
    recorrer_archivo(&al);



    return 0;
}


