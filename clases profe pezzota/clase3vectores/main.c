#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vec3[5] = {0}, vec4[5] = {1,2}, vec5[5]={1,2,3,4,5};
    int i;
    printf("%p",vec5);
    /*for(i=0;i<15;i++)
        printf("%d",vec5[i]);
    */
    vec3 = vec4;
    return 0;
}
