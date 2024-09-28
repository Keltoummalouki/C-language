#include <stdio.h>
    void sumcalcul()
    {
        int x , y;
        printf("Entrer le premier nombre : ");
        scanf("%d", &x);
        printf("\nEntrer le deuxieme nombre : ");
        scanf("%d", &y);
        int sum = x + y;
        printf("\nLa somme de deux nombres est : %d .", sum);

    }
        int main()
        {
            sumcalcul();

            return 0;
        }