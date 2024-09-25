#include <stdio.h>
int main()
{
    int Num;
    int i;
    float f;

        printf("Entrer un nombre n : ");
        scanf("%d", &Num);

    if(Num<0)
        printf("Enrer un nombre positif!");

    else if (Num==0)
        printf("la factorielle est 1.");

    else 
    {
    f = 1;
    for (i = 1 ; i <= Num ; i++)
    f = f * i;
    printf("La factorielle de %d est %.0f" ,Num ,f);
    
    }
    return 0;
}