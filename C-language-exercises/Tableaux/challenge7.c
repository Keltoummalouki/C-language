#include <stdio.h>
int main()
{
    int N;
    int i , j , res;


    printf("Saisir un tableau d'entiers : \n");
    scanf("%d", &N);

    int T[N];

    for ( i = 0 ; i < N ; i++ )
    {
        printf("T[%d] = " ,i + 1 );
        scanf("%d", &T[i]);
    }

    for ( i = 0 ; i < N ; i ++)
    {
        for ( j = i + 1 ; j < N ; j++)
        {
            if(T[i]>T[j])
            {
                res = T[i];
                T[i] = T[j];
                T[j] = res;
            }
        }
    }

    printf("Les elements du tableau par ordre coissant est : \n");
    
    for ( i = 0 ; i < N ; i++)
        printf("%d ", T[i]);

    return 0;
}