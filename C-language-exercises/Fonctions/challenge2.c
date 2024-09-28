#include <stdio.h>

    int Mulcalcul()
    {
        int x , y , res;
        printf("Entrer le premier nombre : ");
        scanf("%d", &x);
        printf("\nEntrer le deuxieme nombre : ");
        scanf("%d", &y);
        res = x * y ;
        printf("Le produit des deux nombres est : %d.", res);
        
    }

    int main()
    {

         Mulcalcul();

        return 0;
    }