#include <stdio.h>
    int Max()
    {
        int i ;
        int max;
        int N1,N2 ;
        
        printf("Entrer le premier nombre : ");
        scanf("%d", &N1);
        printf("Entrer le deuxieme nombre : ");
        scanf("%d", &N2);

        if (N1>N2)
        {
            printf("Le grand nombre est : %d.", N1);
        }
        else 
        {
            printf("Le grand nombre est %d.", N2);
        }
    }


    int main()
    {
        int Q ;
        do
        {
        Max();
        printf("1 - Quitter. ");
        scanf("%d", &Q);
        printf("2 - Quitter. ");
        scanf("%d", &Q);
        }while ( Q =  3);

        return 0;
    }