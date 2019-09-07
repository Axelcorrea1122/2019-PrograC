#include "normalizar.h"

int main()
{
    char cad[50] = ";'.,     dE   [[;;'PaUl     ;.*/-+    AxEL[];";
    printf("%s", normalizar_cadena(cad));

    return 0;
}
