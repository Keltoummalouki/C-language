#include <stdio.h>
    void affichage ( int T[], int N)
    {
        if(N!=0)
    {
        affichage (T,N-1);
        printf("%d \n", T[N-1]);
        
    }
    }
int main()
{
    int N;
    int i;
    int j;

    printf("Entrer nombre des elements du tableau original : ");
    scanf("%d" , &N);

    int T[N]; //Tableau original

    for ( i = 0 ; i < N ; i++ )
    {
        printf("T[%d] = " ,i + 1 );
        scanf("%d", &T[i]);
    }
    printf("Les elements du tableau original : \n");
    affichage(T,N);

    printf("\nLes elements du copie de tableau  : \n");
    affichage(T,N);

    if ( T[N-1] =  T[N-1])

        printf("la copie est correcte.");
    else 
    {
        printf("la copie est incorrecte.");
    }
    return 0;
}